#A file of general constants

import numpy as np

DT = 10
MAG_NOISE = 100
BIAS_UPDATE_FREQ = 1
'''how many iterations do we iterate thru before updating bias estimation?
 Useful for gradual drfit estimation, not so much for our simulation'''

PHOTODIODE_NOISE = 0

ORBIT_Q_KEP = np.eye(3) * MAG_NOISE#change
ORBIT_Q_CARTESIAN = np.eye(9) * MAG_NOISE#change
ORBIT_R = np.array([MAG_NOISE**2])
ORBIT_INITIAL_COVARIANCE = 1

BDOT_Q = np.eye(9)*1e-5#change
BDOT_R = np.eye(3)*(MAG_NOISE**2)
BDOT_INITIAL_COVARIANCE = np.eye(9) * 100

ROT_Q = np.eye(6) * 1
ROT_R = np.eye(9)*10000
QUAT_INITIAL_COVARIANCE = np.eye(6) * 10000
