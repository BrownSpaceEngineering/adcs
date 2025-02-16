from main_structure import Framework
import support_functions
import math
import numpy as np
from datetime import datetime
import constants
from pyquaternion import Quaternion

iss_posn = np.array([7e6, math.radians(0.05), math.radians(50), math.radians(311.6218), math.radians(199.2431), math.radians(48.4420)])
xyz = support_functions.kep_to_cart(iss_posn)[:3]
magnetometer = support_functions.igdf_eci_vector(xyz[0], xyz[1], xyz[2], datetime.now())
framework = Framework(iss_posn, magnetometer, True)
random_4 = []
random_3 = [0.2, 0.3, 0.6]
if(np.linalg.norm(random_3) < 1):
    random_4 = np.array([random_3[0], random_3[1], random_3[2], math.sqrt(1 - np.linalg.norm(random_3)**2)])

true_rot = Quaternion(random_4)
true_posn = iss_posn

for i in range(int(90*60/constants.DT)):#1 revolution
    true_posn = support_functions.propagate_orbit(true_posn, constants.DT)
    time = datetime.now()
    xyz = support_functions.kep_to_cart(true_posn)[:3]
    mag = support_functions.igdf_eci_vector(xyz[0], xyz[1], xyz[2], time)
    magnetometer = true_rot.rotate(mag)
    sun = true_rot.rotate(support_functions.eci_sun_vector(time))
    framework.propagate(np.concatenate([magnetometer + np.random.normal(scale = 3, size = 3), sun], axis = 0), time)
    distance = np.linalg.norm(support_functions.kep_to_cart(true_posn)[:3] - support_functions.kep_to_cart(framework.get_position_eci())[:3])
    print("KM OFFSET: %f", distance/1000)
    print("REAL: ", true_rot)
    print("PRED: ", framework.quaternion_estimation.estimate)
    print("W: ", framework.quaternion_estimation.gyro_bias)
    true_rot *= Quaternion(axis = [1, 0, 0], degrees = 0.5)
    print("\n")

print("KM OFFSET: %f", distance/1000)
print("\n")
