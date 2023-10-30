import numpy as np

def euler_to_rotation_matrix(roll, pitch, yaw):
    # Convert degrees to radians
    roll = np.radians(roll)
    pitch = np.radians(pitch)
    yaw = np.radians(yaw)

    # Roll: rotation about the X-axis
    Rx = np.array([
        [1, 0, 0],
        [0, np.cos(roll), -np.sin(roll)],
        [0, np.sin(roll), np.cos(roll)]
    ])

    # Pitch: rotation about the Y-axis
    Ry = np.array([
        [np.cos(pitch), 0, np.sin(pitch)],
        [0, 1, 0],
        [-np.sin(pitch), 0, np.cos(pitch)]
    ])

    # Yaw: rotation about the Z-axis
    Rz = np.array([
        [np.cos(yaw), -np.sin(yaw), 0],
        [np.sin(yaw), np.cos(yaw), 0],
        [0, 0, 1]
    ])

    # Combined rotation matrix: R = Rz * Ry * Rx
    R = Rz.dot(Ry.dot(Rx))
    return R

def compute_angular_velocity(roll_rate, pitch_rate, yaw_rate, roll, pitch):
    # Convert degrees to radians
    roll = np.radians(roll)
    pitch = np.radians(pitch)
    yaw = np.radians(yaw)

    transformation_matrix = np.array([
        [1, np.sin(roll) * np.tan(pitch), np.cos(roll) * np.tan(pitch)],
        [0, np.cos(roll), -np.sin(roll)],
        [0, np.sin(roll) / np.cos(pitch), np.cos(roll) / np.cos(pitch)]
    ])

    rates = np.array([roll_rate, pitch_rate, yaw_rate])
    omega = transformation_matrix.dot(rates)
    return omega

def rotation_to_angular_velocity(R, dt):
    theta = np.arccos((np.trace(R) - 1) / 2)
    
    # Compute the rotation axis using the rotation matrix properties
    axis = np.array([(R[2,1] - R[1,2]), 
                     (R[0,2] - R[2,0]), 
                     (R[1,0] - R[0,1])])
    axis /= np.linalg.norm(axis)
    
    # Angular velocity
    omega = axis * theta / dt
    return omega


roll_0, pitch_0, yaw_0 = 0, 0, 0

roll_1, pitch_1, yaw_1 = 20, 15, -10

R = euler_to_rotation_matrix(roll_1 - roll_0, pitch_1 - pitch_0, yaw_1 - yaw_0)
print("Rotation Matrix: \n", R)
t = 1
omega = rotation_to_angular_velocity(R, t)
print("Angulare Velocity: \n", omega)
