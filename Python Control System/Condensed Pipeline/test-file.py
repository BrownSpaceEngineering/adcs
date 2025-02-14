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
framework = Framework(iss_posn, magnetometer, False)
random_4 = []
random_3 = [0.2, 0.3, 0.6]
if(np.linalg.norm(random_3) < 1):
    random_4 = np.array([random_3[0], random_3[1], random_3[2], math.sqrt(1 - np.linalg.norm(random_3)**2)])

true_rot = Quaternion(random_4)
true_posn = iss_posn

for i in range(int(90*60/constants.DT)):#1 revolution
    true_posn = support_functions.propagate_orbit(true_posn, constants.DT)
    time = datetime.now()
    if(i%2):
        xyz = support_functions.kep_to_cart(true_posn)[:3]
        mag = support_functions.igdf_eci_vector(xyz[0], xyz[1], xyz[2], time) + np.random.normal(size = 3)
        magnetometer = true_rot.rotate(mag)
        framework.propagate(magnetometer, time)
    else:
        framework.propagate([], time)
    #sun = true_rot.rotate(support_functions.eci_sun_vector(time))
    #framework.propagate(np.concatenate([magnetometer, sun], axis = 0), time)
    distance = np.linalg.norm(support_functions.kep_to_cart(true_posn)[:3] - support_functions.kep_to_cart(framework.get_position_eci())[:3])
    print("KM OFFSET: %f", distance/1000)
    qd = true_rot.conjugate * framework.get_rotation_from_eci()
    phi   = math.atan2( 2 * (qd.w * qd.x + qd.y * qd.z), 1 - 2 * (qd.x**2 + qd.y**2) )
    theta = math.asin ( 2 * (qd.w * qd.y - qd.z * qd.x) )
    psi   = math.atan2( 2 * (qd.w * qd.z + qd.x * qd.y), 1 - 2 * (qd.y**2 + qd.z**2) )
    print("ANGLE OFFSET:", math.degrees(abs(phi) + abs(theta) + abs(psi)))
    print("\n")

print("KM OFFSET: %f", distance/1000)
print("ANGLE OFFSET:", math.degrees(abs(phi) + abs(theta) + abs(psi)))
print("\n")
