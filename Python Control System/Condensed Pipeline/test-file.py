import math
from kalman_filters import EKF, QuaternionMEKF
import support_functions
import numpy as np
from pyquaternion import Quaternion
from numpy.typing import NDArray
import constants
from datetime import datetime
from filterpy.kalman import UnscentedKalmanFilter, MerweScaledSigmaPoints
class NoiseEstimator():
    def __init__(self, observation_noise_matrix : NDArray[np.float64], 
                 process_noise_matrix : NDArray[np.float64], 
                 starting_state : NDArray[np.float64], 
                 starting_covariance : NDArray[np.float64], 
                 simulation_dt : int):
        points = MerweScaledSigmaPoints(9, alpha=10, beta=2., kappa=-6)
        self.kf = UnscentedKalmanFilter(dim_x=9, dim_z=1, dt=simulation_dt, fx=self.f, hx=self.h, points=points)
        self.kf.x = np.concatenate([starting_state, np.zeros(6)], axis = 0)
        self.kf.P = starting_covariance
        self.kf.Q = process_noise_matrix
        self.kf.R = observation_noise_matrix

    def f(self, state, dt):
        return state
    def h(self, state):
        B_k = state[:3]
        S_k = np.diag(state[3:6])
        bias_k = state[6:]
        measurement = (S_k + np.eye(3))@B_k + bias_k
        return np.array([np.linalg.norm(measurement)])
    def set_time(self, time):
        self.time = time
    def predict(self):
        self.kf.predict()
    def update(self, measurement):
        self.kf.update(measurement)



true_scale_factors = np.array([1, 1, 1])
true_measurement = np.array([10000, 0, 0])
true_noise = 350

estimator = NoiseEstimator(
    np.eye(1) * 1000,
    np.eye(9) * 1,
    true_measurement,
    np.diag([1,1,1,100, 100, 100,100000,100000,100000]),
    1
)
for i in range(5000):
    measurement = np.diag(true_scale_factors)@true_measurement + np.random.normal(size = 3, scale = 100, loc = true_noise)
    estimator.predict()
    estimator.update(np.array(np.linalg.norm([measurement])))
print('MEAN: ', estimator.kf.x[:3])
print('BIAS: ', estimator.kf.x[6:])
print('SCALE FACTOR', np.ones(3) + estimator.kf.x[3:6])