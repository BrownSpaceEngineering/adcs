#A file of general constants

import numpy as np

DT = 5
MAG_BIAS = 10
PHOTO_BIAS = 0

ORBIT_Q = np.eye(6)#change
ORBIT_R = np.array([MAG_BIAS**2])

BDOT_Q = np.eye(9) * 10#change
BDOT_R = np.eye(3)*(MAG_BIAS**2)

ROT_Q = np.eye(6) * 10#use the Q equation from Table II of the "backup satellite" paper
ROT_R = np.eye(3)*10#use Equation 26 of the same paper when actually finding R
