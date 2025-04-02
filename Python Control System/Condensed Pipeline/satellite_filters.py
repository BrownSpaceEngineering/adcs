import math
from kalman_filters import EKF, UKF
import support_functions
import numpy as np
from pyquaternion import Quaternion
from numpy.typing import NDArray

class AttitudeIndependentOrbitPropagation(UKF):
    '''An orbital propagator filter that directly predicts a 6-value ECI Cartesian system
    (x,y,z,velocity x, velocity y, velocity z), as well as magnetometer biases'''
    def __init__(self, observation_noise_matrix : NDArray[np.float64], 
                 process_noise_matrix : NDArray[np.float64], 
                 starting_state : NDArray[np.float64], 
                 starting_covariance : NDArray[np.float64], 
                 simulation_dt : int,
                 bias_sparcity : int,
                 alpha = 10):
        starting_state = np.concatenate([support_functions.kep_to_cart(starting_state),
                                    np.zeros(3)])
        super().__init__(observation_noise_matrix,
                       process_noise_matrix,
                       starting_state,
                       starting_covariance,
                       simulation_dt,
                       alpha = alpha)
        self.bias_update_sparcity = bias_sparcity
        self.last_bias = np.zeros(3)
        self.iterations = 0

    def f(self, state, dt):
        '''Estimates the next position based on a second derivative
        Newtonian estimation. Leaves the estimated biases untouched'''
        g = support_functions.get_gravity_accel(state[:3])
        return state + dt * np.concatenate([state[3:6] + 1/2 * g * dt, g, np.zeros(3)])
    def h(self, state):
        '''Gets the magnetometer magnitude at a certain state'''
        mag = support_functions.igdf_eci_vector(state[0], state[1], state[2], self.time) + state[6:]
        n = np.linalg.norm(mag)
        return np.array([n])
    def predict(self):
        '''Propagates the orbit via the second derivative Newtonian estimation'''
        self.kf.predict()
    def update(self, measurement):
        '''Updates the biases and estimated position'''
        self.last_bias = self.kf.x[6:]
        self.kf.update(measurement)
        if(not(self.iterations % self.bias_update_sparcity == 0)):#bias sparcity
            self.kf.x[6:] = self.last_bias
        self.iterations += 1
        

class KeplerAssumedOrbitalPropagatorWithBias(UKF):
    '''An orbital propagator filter that iterates using an assumed 6-value Keplerian system
     (semi-major axis (a), eccentricity (e), inclination (i), 
     longitude of the ascending node (Ω), argument of periapsis (ω), and true anomaly (ν)) 
     and estimates magnetometer biases based on Crassidis et. al'''
    def __init__(self, observation_noise_matrix : NDArray[np.float64], 
                 process_noise_matrix : NDArray[np.float64], 
                 starting_state : NDArray[np.float64],
                 starting_covariance : NDArray[np.float64], 
                 simulation_dt : int,
                 bias_sparcity : int,
                 alpha = 10):
        
        self.kepler_state = starting_state
        starting_bias = np.zeros(3)#initial assumed bias
        super().__init__(observation_noise_matrix,
                         process_noise_matrix,
                         starting_bias,
                         starting_covariance,
                         simulation_dt,
                         alpha = alpha)
        self.bias_update_sparcity = bias_sparcity
        self.last_bias = np.zeros(3)
        self.iterations = 0

    def f(self, state, dt):
        '''Returns the estimated bias'''
        return state
    def h(self, state):
        '''Gets the magnetometer magnitude at the current position'''
        eci_position = support_functions.kep_to_cart(self.kepler_state)[:3]
        mag = support_functions.igdf_eci_vector(eci_position[0], eci_position[1], eci_position[2], self.time) + state
        n = np.linalg.norm(mag)
        return np.array([n])
    def predict(self):
        '''Propagates the orbit via the Keplerian elements'''
        self.kepler_state = support_functions.propagate_orbit(self.kepler_state, self.dt)
        self.kf.predict()
    def update(self, measurement):
        '''Updates the magnetometer bias'''
        self.last_bias = self.kf.x
        self.kf.update(measurement)
        if(not(self.iterations % self.bias_update_sparcity == 0)):#bias sparcity 
            self.kf.x = self.last_bias
        self.iterations += 1

class KeplerAssumedOrbitalPropagator():
    '''An orbital propagator filter that iterates using an assumed 6-value Keplerian system
     (semi-major axis (a), eccentricity (e), inclination (i), 
     longitude of the ascending node (Ω), argument of periapsis (ω), and true anomaly (ν)) 
     and assumes 0 magnetometer bias'''
    def __init__(self, starting_state, simulation_dt):
        self.kepler_state = starting_state
        self.dt = simulation_dt
    def predict(self):
        #propagates orbit
        self.kepler_state = support_functions.propagate_orbit(self.kepler_state, self.dt)
    def update(self, measurement):
        #allows this propagator to work with the others
        pass
    def iterate(self, measurement):
        #iterates via a predict
        self.predict()
    def set_time(self):
        #allows this propagator to work with the others
        pass
    

class BDotEstimation(EKF):
    '''A BDot estimation algorithm based off of Searcy et. al'''
    def df(self, state):
        return np.array([
            state[3], state[4], state[5], state[6], state[7], state[8], 0, 0, 0
        ])
    def f(self, state):
        return state + self.dt*self.df(state)
    def h(self, state):
        return state[:3]
    
    
    
class QUEST():
    '''An implementation of the Quaternion Estimation algorithm by Shuster et al.'''
    @staticmethod
    def NewtonRaphson(proposed_eigen, a, b, c, d, sigma):
        return proposed_eigen - (proposed_eigen**4 - (a+b)*(proposed_eigen**2) - c*proposed_eigen + (a*b + c*sigma - d)) \
        / (4*(proposed_eigen**3) - 2*(a+b)*proposed_eigen - c)
    @staticmethod
    def QUEST(observation_vectors, reference_vectors):
        iters = 1
        #all vectors should be unit vectors of shape (3, )
        vector_count = len(observation_vectors)
        weights = np.random.random(vector_count)
        weights /= weights.sum()

        B = np.zeros((3, 3))
        Z = np.zeros(3)
        for i in range(vector_count):
            B += weights[i] * np.outer(observation_vectors[i], reference_vectors[i])
            Z += weights[i] * np.cross(observation_vectors[i],reference_vectors[i])
        S = B + B.T

        delta = np.linalg.det(S)
        kappa = np.trace(np.linalg.inv(S).T * delta)
        sigma = 1/2*np.trace(S)
        d = Z@S@S@Z.T
        c = delta + Z@S@Z.T
        b = sigma**2 + Z@Z.T
        a = sigma**2 - kappa

        proposed_eigen = 1
        for i in range(iters):
            proposed_eigen = QUEST.NewtonRaphson(proposed_eigen, a, b, c, d, sigma)

        alpha = proposed_eigen**2 - sigma**2 + kappa
        beta = proposed_eigen - sigma
        gamma = (proposed_eigen + sigma)*alpha - delta
        X = (alpha*np.eye(3) + beta*S + S@S)@Z#non-negative as we are attempting to get a vector from reference to observation, rather from observation to reference 

        return 1/math.sqrt(gamma**2 + (np.linalg.norm(X))**2) * Quaternion(scalar = gamma, vector = X)
    