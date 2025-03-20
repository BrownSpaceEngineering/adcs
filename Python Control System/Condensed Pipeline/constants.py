#A file of general constants

import numpy as np

DT = 10
MAG_BIAS = 100
PHOTO_BIAS = 0

ORBIT_Q = np.eye(6) * MAG_BIAS#change
ORBIT_R = np.array([MAG_BIAS**2])

BDOT_Q = np.eye(9)*1e-5#change
BDOT_R = np.eye(3)*(MAG_BIAS**2)

ROT_Q = np.eye(6) * 1
ROT_R = np.eye(9)*100
