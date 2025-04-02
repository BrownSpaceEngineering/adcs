from kalman_filters import QuaternionMEKF
from satellite_filters import BDotEstimation, QUEST, KeplerAssumedOrbitalPropagator, KeplerAssumedOrbitalPropagatorWithBias, AttitudeIndependentOrbitPropagation
import support_functions
import numpy as np
from pyquaternion import Quaternion
from numpy.typing import NDArray
import constants
from datetime import datetime

class Framework():
    '''The framework of the attitude & orbital determination model. All angular measurements
     are in radians and all spatial measurements are in meters'''
    def __init__(self, 
                 initial_cartesian_position : NDArray, #initial cartesian position
                 initial_kepler_position : NDArray, #initial kepler position
                 initial_readings : NDArray, #initial sensor readings
                 throw_eclipse = True, #determines if we throw the BDot measurement when not in eclipse
                 orbital_estimator = 'Kepler w/ Bias'
                 ):
        self.throw_eclipse = throw_eclipse
        self.last_called = datetime.now()
        self.dt = constants.DT
        self.cartesian_position = initial_cartesian_position
        self.rotation_quat = Quaternion(vector = [0, 0, 0], scalar = 1)#initial rotation prediction
        self.angular_velocities = np.array([0.0001, 0.0001, 0.0001])

        if(len(initial_readings) == 3):
            self.sun_vec = None
            self.magnetometer = initial_readings
        else:
            self.magnetometer = initial_readings[:3]
            self.sun_vec = initial_readings[3:]#assumed unit vector

        #initialize estimators
        if(orbital_estimator == 'Kepler w/ Bias'):
            self.orbit_determination = KeplerAssumedOrbitalPropagatorWithBias(
                constants.ORBIT_R,
                constants.ORBIT_Q_KEP,
                initial_kepler_position,
                constants.ORBIT_INITIAL_COVARIANCE,
                self.dt,
                constants.BIAS_UPDATE_FREQ#update bias every N updates
            )
        elif(orbital_estimator == 'Kepler'):
            self.orbit_determination = KeplerAssumedOrbitalPropagator(
                initial_kepler_position,
                self.dt
            )
        elif(orbital_estimator == 'Cartesian'):
            self.orbit_determination = AttitudeIndependentOrbitPropagation(
                constants.ORBIT_R,
                constants.ORBIT_Q_CARTESIAN,
                initial_kepler_position,
                constants.ORBIT_INITIAL_COVARIANCE,
                self.dt,
                constants.BIAS_UPDATE_FREQ#update bias every N updates
            )
        else:
            return Exception()

        self.bdot_estimation = BDotEstimation(
            constants.BDOT_R,
            constants.BDOT_Q,
            np.concatenate([self.magnetometer, np.zeros(6)]),
            constants.BDOT_INITIAL_COVARIANCE,
            self.dt
        )
        
        self.quaternion_estimation = QuaternionMEKF(
            constants.ROT_R,
            constants.ROT_Q,
            np.array([1, 0, 0, 0]),
            constants.QUAT_INITIAL_COVARIANCE,
            self.dt
        )
        
    def propagate(self, measurements, time):
        '''Propagates all aspects of the model'''

        #Manages the time dependence of many aspects of the model
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

            self.cartesian_position = self.get_cartesian_position_eci()
            self.rotation_quat = self.get_rotation_from_eci()
        else:
            self.magnetometer = measurements[:3]#definitely will be there
            #ORBITAL ESTIMATION
            last_position = self.get_cartesian_position_eci()
            self.orbit_determination.iterate(np.linalg.norm(self.magnetometer))
            new_position = self.get_cartesian_position_eci()

            #ATTITUDE ESTIMATION
            self.bdot_estimation.iterate(self.magnetometer)
            observed_b = self.magnetometer + self.get_mag_bias()#raw b value
            observed_bdot = self.get_bdot()#assumed 0 angular velocity, which is a major flaw point

            reference_b = support_functions.igdf_eci_vector(new_position[0], new_position[1], new_position[2], cur_time)
            reference_b_last = support_functions.igdf_eci_vector(last_position[0], last_position[1], last_position[2], last_time)
            reference_bdot = (reference_b - reference_b_last)/self.dt#very simple derivative calculation
            observed_vectors = [observed_b, observed_bdot]
            reference_vectors = [reference_b, reference_bdot]
            
            if(len(measurements) > 3):#if not in eclipse
                if(self.throw_eclipse):
                    observed_vectors = [observed_b]
                    reference_vectors = [reference_b]
                self.sun_vec = measurements[3:6]
                observed_vectors.append(self.sun_vec)
                reference_vectors.append(support_functions.eci_sun_vector(cur_time))

            normalized_observed_vectors = []
            normalized_reference_vectors = []
            for vec in observed_vectors:
                normalized_observed_vectors.append(vec / np.linalg.norm(vec))
            for vec in reference_vectors:
                normalized_reference_vectors.append(vec / np.linalg.norm(vec))

            predicted_quaternion = QUEST.QUEST(normalized_observed_vectors, normalized_reference_vectors) #predicted quaternion from ECI to body based on QUEST

            #rotates unit vectors from eci to body as "prediction" vectors
            measurement_1 = predicted_quaternion.rotate([0, 0, 1.0])
            measurement_2 = predicted_quaternion.rotate([0, 1.0, 0.0])
            measurement_3 = predicted_quaternion.rotate([1.0, 0.0, 0.0])
            self.quaternion_estimation.iterate(np.concatenate([measurement_1, measurement_2, measurement_3], axis =0))
            self.angular_velocities = self.quaternion_estimation.angular_velocities
            #generates vector from body to ECI

    def get_rotation_from_eci(self):
        '''Gets the current believed rotation quaternion that goes from ECI frame to body frame based off the QuatMEKF'''
        return self.quaternion_estimation.estimate
    
    def get_rotation_to_eci(self):
        '''Gets the current believed rotation quaternion that goes from body frame to ECI frame based off the QuatMEKF'''
        return self.quaternion_estimation.estimate.inverse()
    
    def get_w(self, degrees = False):
        '''Gets the current believed angular velocities based off the QuatMEKF'''
        if(degrees):
            return self.quaternion_estimation.angular_velocities * 180 / np.pi
        else:
            return self.quaternion_estimation.angular_velocities
    
    def get_cartesian_position_eci(self):
        '''Gets the current believed cartesian position in ECI(6 elements)'''
        if((isinstance(self.orbit_determination, AttitudeIndependentOrbitPropagation))):
            return self.orbit_determination.kf.x
        elif((isinstance(self.orbit_determination, KeplerAssumedOrbitalPropagatorWithBias)) or
             (isinstance(self.orbit_determination, KeplerAssumedOrbitalPropagator))):
            return support_functions.kep_to_cart(self.orbit_determination.kepler_state)

    def get_b(self):
        '''Gets the current believed magnetosphere influence based off the BDot estimator'''
        return self.bdot_estimation.state_estimate[:3]

    def get_bdot(self):
        '''Gets the current believed derivative of magnetosphere influence based off the BDot estimator'''
        return self.bdot_estimation.state_estimate[3:6]
    
    def get_mag_bias(self):
        '''Gets the current believed magnetometer bias based off the orbital propagator'''
        if((isinstance(self.orbit_determination, KeplerAssumedOrbitalPropagatorWithBias))):
            return self.orbit_determination.kf.x
        elif((isinstance(self.orbit_determination, AttitudeIndependentOrbitPropagation))):
            return self.orbit_determination.kf.x[6:]
        else:
            return np.zeros(3)
        
    def override_state(self, new_eci_state):
        '''Overrides the current state in the orbital propagator with a true one.
        Assumes input is a 6 value ECI state'''
        if(isinstance(self.orbit_determination, AttitudeIndependentOrbitPropagation)):
            self.orbit_determination.kf.x[:6] = new_eci_state
        elif(isinstance(self.orbit_determination, KeplerAssumedOrbitalPropagator) or
             isinstance(self.orbit_determination, KeplerAssumedOrbitalPropagatorWithBias)):
            self.orbit_determination.kepler_state = support_functions.cart_to_kep(new_eci_state)
        else:
            pass



        
