from datetime import datetime
import numpy as np
from typing import Callable
from numpy.typing import NDArray
from pyquaternion import Quaternion
from filterpy.kalman import UnscentedKalmanFilter, MerweScaledSigmaPoints
class KalmanFilter():
    '''Class detailing an abstract Kalman Filter'''
    def __init__(self, observation_noise_matrix : NDArray[np.float64], 
                 process_noise_matrix : NDArray[np.float64], 
                 starting_state : NDArray[np.float64], 
                 starting_covariance : NDArray[np.float64], 
                 simulation_dt : int):
        self.state_estimate = starting_state
        self.covariance = starting_covariance
        self.Q = process_noise_matrix
        self.R = observation_noise_matrix
        self.dt = simulation_dt
        self.state_size = len(starting_state)
        self.measurement_size = len(process_noise_matrix)
        self.time = datetime.now()

    def f(self, state) -> NDArray[np.float64]:
        '''Proceeds to the next state by dt time'''
        return state
    def h(self, state) -> NDArray[np.float64]:
        '''Gets the expected measurements at a state'''
        return state
    def predict(self) -> None:
        '''Make initial predictions for state & covariance matrices'''
        pass
    def update(self, measurements) -> None:
        '''Updates the predictions in the KF based on kalman gain terms'''
        pass
    def iterate(self, measurements) -> None:
        '''Performs a predict+update iteration'''
        self.predict()
        self.update(measurements)
    def set_time(self, time : datetime.time):
        '''Sets a standard time for calculations'''
        self.time = time

    def estimate_jacobian(self, f : Callable[NDArray[np.float64], NDArray[np.float64]],
                     state : NDArray[np.float64], #estimate jacobian at this state
                      epsilon = 0.001 #limit definition of the derivative applied to vectorvalued partials
                     ):
        '''Estimates the Jacobian of a given function'''
        y = f(state)
        n = state.shape[0]#function input vector shape
        m = y.shape[0]#function output vector shape
        J = np.zeros((m, n))
        for i in range(n):
            state_1 = np.copy(state)
            state_1[i] = state[i] + epsilon
            f_1 = f(state_1)
            for j in range(m):
                J[j][i] = (f_1[j] - y[j])/epsilon

        return J

class UKF(KalmanFilter):
    '''Class detailing a generalized unscented Kalman filter'''
    def __init__(self, 
                 observation_noise_matrix : NDArray[np.float64], 
                 process_noise_matrix : NDArray[np.float64], 
                 starting_state : NDArray[np.float64], 
                 starting_covariance : NDArray[np.float64], 
                 simulation_dt : int,
                 alpha : int):
        super().__init__(observation_noise_matrix,
                 process_noise_matrix, 
                 starting_state,
                 starting_covariance,
                 simulation_dt)
        
        points = MerweScaledSigmaPoints(self.state_size, alpha=alpha, beta=2., kappa= 3 - self.measurement_size)
        self.kf = UnscentedKalmanFilter(dim_x=self.state_size, dim_z=self.measurement_size, dt=simulation_dt, fx=self.f, hx=self.h, points=points)
        self.kf.x = starting_state
        self.kf.P = starting_covariance
        self.kf.Q = process_noise_matrix
        self.kf.R = observation_noise_matrix
    def f(self, state, dt) -> NDArray[np.float64]:
        #redefines f for the UnscentedKalmanFilter formulation given by filterpy
        pass
    def predict(self) -> None:
        self.kf.predict()
    def update(self) -> None:
        self.kf.update()

class EKF(KalmanFilter):
    '''Class detailing a standard EKF'''
    def predict(self):
        F = self.estimate_jacobian(self.f, self.state_estimate)
        self.state_estimate = self.f(self.state_estimate)
        self.covariance = F@self.covariance@F.T + self.Q
    def update(self, measurements):
        residual = measurements - self.h(self.state_estimate)
        H = self.estimate_jacobian(self.h, self.state_estimate)
        S = H@self.covariance@H.T + self.R
        kalman_gain = self.covariance@H.T@np.linalg.inv(S)

        self.state_estimate = self.state_estimate+ kalman_gain@residual
        self.covariance = (np.eye(len(self.state_estimate)) - kalman_gain@H)@self.covariance

class QuaternionMEKF(KalmanFilter):
    '''Class detailing a Quaternion MEKF'''
    def __init__(self, observation_noise_matrix : NDArray[np.float64], 
                 process_noise_matrix : NDArray[np.float64], 
                 starting_state : NDArray[np.float64], 
                 starting_covariance : NDArray[np.float64], 
                 simulation_dt : int):
        self.estimate = Quaternion(starting_state)
        self.estimate_covariance = starting_covariance
        self.observation_covariance = observation_noise_matrix
        self.process_covariance = process_noise_matrix
        self.angular_velocities = np.array([0.0, 0.0, 0.0])
        self.dt = simulation_dt
        self.G = np.zeros(shape=(6, 6), dtype=float)
        self.G[0:3, 3:6] = -np.eye(3)

    def predict(self):
        gyro_meas = -self.angular_velocities#fakes a gyro measurement using the angular velocities
        self.G[0:3, 0:3] = -self.skewSymmetric(gyro_meas)
        F = np.eye(6) + self.G*self.dt

        #Standard Kalman Filter
        self.estimate_covariance = np.dot(np.dot(F, self.estimate_covariance), F.transpose()) + self.process_covariance
        self.estimate = self.estimate + self.dt*0.5*self.estimate*Quaternion(scalar = 0, vector=gyro_meas)
        self.estimate = self.estimate.normalised
        
    def skewSymmetric(self, v):
        '''Returns skew-symmetric matrix for an angular velocity vector'''
        return np.array([[0.0, -v[2], v[1]],
                        [v[2], 0.0, -v[0]],
                        [-v[1], v[0], 0.0]]) 
        
    def iterate(self, measurements):
        time_delta = self.dt
        
        gyro_meas = -self.angular_velocities

        #Integrate angular velocity through forming quaternion derivative
        self.estimate = self.estimate + time_delta*0.5*self.estimate*Quaternion(scalar = 0, vector=gyro_meas)
        self.estimate = self.estimate.normalised
        
        #Form process model
        self.G[0:3, 0:3] = -self.skewSymmetric(gyro_meas)
        F = np.eye(6) + self.G*time_delta

        #Update with a priori covariance
        self.estimate_covariance = np.dot(np.dot(F, self.estimate_covariance), F.transpose()) + self.process_covariance

        #Form Kalman gain
        H = np.zeros(shape=(9,6), dtype=float)
        H[0:3, 0:3] = self.skewSymmetric(self.estimate.inverse.rotate(np.array([0.0, 0.0, 1.0])))
        H[3:6, 0:3] = self.skewSymmetric(self.estimate.inverse.rotate(np.array([0, 1.0, 0])))
        H[6:9, 0:3] = self.skewSymmetric(self.estimate.inverse.rotate(np.array([1.0, 0, 0])))
        PH_T = np.dot(self.estimate_covariance, H.transpose())
        inn_cov = H.dot(PH_T) + self.observation_covariance
        K = np.dot(PH_T, np.linalg.inv(inn_cov))

        #Update with a posteriori covariance
        self.estimate_covariance = (np.identity(6) - np.dot(K, H)).dot(self.estimate_covariance)

        predicted_observation = np.zeros(shape=(9, ), dtype=float)
        predicted_observation[0:3] = self.estimate.inverse.rotate(np.array([0.0, 0.0, 1.0]))
        predicted_observation[3:6] = self.estimate.inverse.rotate(np.array([0.0, 1.0, 0.0]))
        predicted_observation[6:9] = self.estimate.inverse.rotate(np.array([1.0, 0.0, 0.0]))

        aposteriori_state = np.dot(K, (measurements - predicted_observation).transpose())

        #Fold filtered error state back into full state estimates
        self.estimate = self.estimate * Quaternion(scalar = 1, vector = 0.5*aposteriori_state[0:3])
        self.estimate = self.estimate.normalised
        self.angular_velocities += aposteriori_state[3:6]