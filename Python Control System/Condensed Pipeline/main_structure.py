import math
from kalman_filters import EKF, QuatMEKF
import support_functions
import numpy as np
from pyquaternion import Quaternion
from numpy.typing import NDArray
import constants
from datetime import datetime
class AttitudeIndependentOrbitPropagation(EKF):
    def f(self, state):
        return support_functions.propagate_orbit(state, self.dt)
    def h(self, state):
        cartesian_terms = support_functions.kep_to_cart(state)
        mag_vec = support_functions.igdf_eci_vector(cartesian_terms[0], 
                                                 cartesian_terms[1],
                                                 cartesian_terms[2],
                                                 self.time)
        return np.array([np.linalg.norm(mag_vec)])
    

class BDotEstimation(EKF):
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
        X = -(alpha*np.eye(3) + beta*S + S@S)@Z#look idfk but my vectors were always off by a negative sign

        return 1/math.sqrt(gamma**2 + (np.linalg.norm(X))**2) * Quaternion(scalar = gamma, vector = X)
    
class Framework():
    '''The framework of attitude & orbital determination based on Yakupoglu-Altuntas et al.'''
    def __init__(self, initial_position : NDArray, initial_readings : NDArray, throw_eclipse = False):
        self.throw_eclipse = throw_eclipse#determines if we throw the BDot measurement when not in eclipse
        self.last_called = datetime.now()
        self.dt = constants.DT
        self.position = initial_position#should be in Kepler format
        self.rotation_quat = Quaternion(vector = [0, 0, 0], scalar = 1)
        self.angular_velocities = np.array([0.001, 0.001, 0.001])
        self.prev_quaternion_cov = np.eye(6) * 10000

        if(len(initial_readings) == 3):
            self.sun_vec = None
            self.magnetometer = initial_readings
        else:
            self.magnetometer = initial_readings[:3]
            self.sun_vec = initial_readings[3:]#assumed unit vector
        #State: IN RADIANS
        #[Semi-major axis, Eccentricity, Inclination, Argument of periapsis, Longitude of ascending node, Anomaly].
        #Observation: [MagB]
        self.orbit_determination = AttitudeIndependentOrbitPropagation(
            constants.ORBIT_R,
            constants.ORBIT_Q,
            self.position,
            np.eye(6) * 100000,
            self.dt
        )

        #State: [Bx, By, Bz, Bdot_x, Bdot_y, Bdot_z, B2dot_x, B2dot_y, B2dot_z]
        #Observation: [Bx, By, Bz]
        self.bdot_estimation = BDotEstimation(
            constants.BDOT_R,
            constants.BDOT_Q,
            np.concatenate([self.magnetometer, np.zeros(6)]),
            np.eye(9),
            self.dt
        )

        #State: [q0, q1, q2, q3, w_x, w_y, w_z], angular vels in RADIANS
        #Observation: [q0, q1, q2, q3]
        
        self.quaternion_estimation = QuatMEKF(
            constants.ROT_R,
            constants.ROT_Q,
            np.concatenate([self.rotation_quat.elements, self.angular_velocities], axis = 0),
            np.eye(6)*10000,
            self.dt
        )
        

    def propagate(self, measurements, time):
        '''Propagates all aspects of the model'''

        cur_time = time
        last_time = self.last_called
        self.last_called = cur_time
        self.bdot_estimation.set_time(cur_time)
        self.orbit_determination.set_time(cur_time)
        self.quaternion_estimation.set_time(cur_time)

        if(len(measurements) == 0):#if we received no measurements, just propagate forward
            self.bdot_estimation.predict()
            self.orbit_determination.predict()
            self.quaternion_estimation.predict()

            self.position = self.get_position_eci()
            self.rotation_quat = self.get_rotation_from_eci()
        else:
            
            self.magnetometer = measurements[:3]#definitely will be there
            #ORBITAL
            last_position = self.get_position_eci(True)[:3]
            self.orbit_determination.iterate(np.linalg.norm(self.magnetometer))
            self.position = self.orbit_determination.state_estimate
            new_position = self.get_position_eci(True)[:3]

            #ATTITUDE
            self.bdot_estimation.iterate(self.magnetometer)
            b = self.get_b()
            bdot = self.get_bdot()

            reference_b = support_functions.igdf_eci_vector(new_position[0], new_position[1], new_position[2], cur_time)
            reference_b_last = support_functions.igdf_eci_vector(last_position[0], last_position[1], last_position[2], last_time)
            reference_bdot = (reference_b - reference_b_last)/self.dt
            observed_vectors = [b, bdot]
            reference_vectors = [reference_b, reference_bdot]
            

            if(len(measurements) > 3):#if not in eclipse
                if(self.throw_eclipse):
                    observed_vectors = [b]
                    reference_vectors = [reference_b]
                self.sun_vec = measurements[3:6]
                observed_vectors.append(self.sun_vec)
                reference_vectors.append(support_functions.eci_sun_vector(cur_time))

            normalized_observed = []
            normalized_reference = []
            for vec in observed_vectors:
                normalized_observed.append(vec / np.linalg.norm(vec))
            for vec in reference_vectors:
                normalized_reference.append(vec / np.linalg.norm(vec))
            pred_quaternion = QUEST.QUEST(normalized_observed, normalized_reference)

            self.quaternion_estimation.iterate(pred_quaternion)
            state = self.quaternion_estimation.state_estimate
            self.rotation_quat = Quaternion(state[:4])
            self.angular_velocities = state[4:]

    def get_rotation_from_eci(self):
        '''Gets the current believed rotation quaternion that goes from ECI frame to body frame'''
        return Quaternion(self.quaternion_estimation.state_estimate[:4])
    
    def get_w(self):
        '''Gets the current believed angular velocities'''
        return self.quaternion_estimation.state_estimate[4:7]
    
    def get_position_eci(self, cartesian = False):
        '''Gets the current believed position in ECI(6 elements)'''
        current_position = self.orbit_determination.state_estimate
        if(cartesian):
            return support_functions.kep_to_cart(current_position)
        else:
            return current_position

    def get_b(self):
        '''Gets the current believed magnetosphere influence'''
        return self.magnetometer

    def get_bdot(self):
        '''Gets the current believed derivative of magnetosphere influence'''
        return self.bdot_estimation.state_estimate[3:6]



        
