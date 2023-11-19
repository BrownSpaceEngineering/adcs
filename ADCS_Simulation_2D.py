import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import random

# Constant
ZOOM_FACTOR = 8
R_EARTH = 6371 / ZOOM_FACTOR  # Earth radius in km
ORBIT_HEIGHT = 600  # Orbit height in km
ORBIT_RADIUS = R_EARTH + ORBIT_HEIGHT
CUBESAT_WIDTH = 100
CUBESAT_HEIGHT = 300
EARTH_CENTER = [0, 0]

def geo_to_cartesian(lat_deg, lon_deg, radius=R_EARTH):
    """Convert geographic coordinates to Cartesian coordinates."""
    lat_rad = np.radians(lat_deg)
    lon_rad = np.radians(lon_deg)
    x = radius * np.cos(lat_rad) * np.cos(lon_rad)
    y = radius * np.cos(lat_rad) * np.sin(lon_rad)
    return x, y

# Time for one orbit using Kepler's Third Law (T^2 ~ R^3)
T_ORBIT = 2 * np.pi * np.sqrt(ORBIT_RADIUS**3 / 398600.4418)

def compute_position(t):
    # assume Earth is a perfect circle
    orbit_angle_rad = 2 * np.pi * t / T_ORBIT
    x = ORBIT_RADIUS * np.cos(orbit_angle_rad)
    y = ORBIT_RADIUS * np.sin(orbit_angle_rad)
    return x, y

def compute_rectangle(x, y, rotate_rad):
    # Basic rectangle coordinates around (x, y)
    half_width = CUBESAT_WIDTH / 2
    half_height = CUBESAT_HEIGHT / 2
    rect_x = [-half_width, half_width, half_width, -half_width, -half_width]
    rect_y = [-half_height, -half_height, half_height, half_height, -half_height]
    head_x = [0, 0]
    head_y = [half_height, CUBESAT_HEIGHT]

    # Rotation matrix
    R = np.array([[np.cos(rotate_rad), -np.sin(rotate_rad)],
                  [np.sin(rotate_rad),  np.cos(rotate_rad)]])

    rotated_rect = np.dot(R, np.vstack((rect_x, rect_y)))
    rotated_head = np.dot(R, np.vstack((head_x, head_y)))

    # Calculate the directional vector for the head
    head_vector = [rotated_head[0, 1], rotated_head[1, 1]]

    # Calculate the angle with respect to the +x axis
    angle_with_x_axis = np.arctan2(head_vector[1], head_vector[0])

    # Normalize the angle between 0 and 2*pi
    if angle_with_x_axis < 0:
        angle_with_x_axis += 2 * np.pi

    # Translate the rotated coordinates back to center (x, y)
    rotated_rect[0] += x
    rotated_rect[1] += y
    rotated_head[0] += x
    rotated_head[1] += y

    return rotated_rect[0], rotated_rect[1], rotated_head[0], rotated_head[1], angle_with_x_axis

fig, ax = plt.subplots(figsize=(8, 8))
earth_circle = plt.Circle(EARTH_CENTER, R_EARTH, color='#7BAFD4', label="Earth")
ax.add_patch(earth_circle)

# Set Ground Statiom
GS_X, GS_Y = geo_to_cartesian(42.3601, -71.0589)
ax.plot(GS_X, GS_Y, 'ko', markersize=5, label="PVD-GS")
offset = 100  # Adjust this value as needed for best visual positioning
ax.text(GS_X + offset, GS_Y, 'PVD-GS', fontsize=9, ha='left', va='center')

satellite, = ax.plot([], [], 'r-')
pointing_vector, = ax.plot([], [], 'k--')

ax.set_xlim(-ORBIT_RADIUS - 500, ORBIT_RADIUS + 500)
ax.set_ylim(-ORBIT_RADIUS - 500, ORBIT_RADIUS + 500)

GS_COMM_ANGLE = np.radians(15)  # Transmission angle in radians, e.g., 20 degrees. Adjust as needed.
GS_COMM_ANGLE_DEG = np.degrees(GS_COMM_ANGLE)  # Convert ALPHA to degrees

ATTITUDE_ADJUST_ANGLE = GS_COMM_ANGLE + np.radians(15)
ATTITUDE_ADJUST_ANGLE_DEG = np.degrees(ATTITUDE_ADJUST_ANGLE)

# Create a text element for displaying the angle
pointing_angle_text = ax.text(0.95, 0.95, 'Pointing Angle', fontsize=9, ha='right', va='top', transform=ax.transAxes)

def transmission_cone_coords(gs_transmission_angle, distance=2000):
    """
    Compute the coordinates for the transmission cone
    based on the transmission angle alpha and the distance the cone should be drawn.
    """
    # Angle range for the cone
    base_angle = np.arctan2(GS_Y, GS_X)
    angles = [base_angle - gs_transmission_angle, base_angle + gs_transmission_angle]
    
    # Compute x and y coordinates based on the angles
    trans_x_coords = GS_X + distance * np.cos(angles)
    trans_y_coords = GS_Y + distance * np.sin(angles)

    return trans_x_coords, trans_y_coords

transmission_cone_left, = ax.plot([], [], 'r--', label="Transmission Cone Left")
transmission_cone_right, = ax.plot([], [], 'r--', label="Transmission Cone Right")

def attitude_adjust_cone_coords(attitude_adjust_angle, distance=2000):
    """
    Compute the coordinates for the attitude adjust cone
    based on the transmission angle and the distance the cone should be drawn.
    """
    # Angle range for the cone
    base_angle = np.arctan2(GS_Y, GS_X)
    angles = [base_angle - attitude_adjust_angle, base_angle + attitude_adjust_angle]

    # Compute x and y coordinates based on the angles
    attitude_adjust_x_coords = GS_X + distance * np.cos(angles)
    attitude_adjust_y_coords = GS_Y + distance * np.sin(angles)

    return attitude_adjust_x_coords, attitude_adjust_y_coords

attitude_adjust_cone_left, = ax.plot([], [], 'g--', label="Attitude Adjust Cone Left")
attitude_adjust_cone_right, = ax.plot([], [], 'g--', label="Attitude Adjust Cone Right")

def is_inside_cone(x, y, GS_X, GS_Y, start_attitude_control_range):
    # Calculate angle between GS and the CubeSat
    angle_to_satellite = np.arctan2(y - GS_Y, x - GS_X)

    # Calculate base angle of GS (angle GS makes with respect to the origin)
    base_angle = np.arctan2(GS_Y, GS_X)

    # Check if the CubeSat's angle lies within the cone's range
    return base_angle - start_attitude_control_range <= angle_to_satellite <= base_angle + start_attitude_control_range

def disturbance():
    # Generate a small random angular velocity
    # The range of values can be adjusted based on the expected magnitude of disturbances
    return np.random.uniform(-0.05, 0.05)  # radians per second

def attitude_error_estimation(desired_pointing, current_pointing):
    rotate_rad = np.arctan2(desired_pointing[1] - current_pointing[1], desired_pointing[0] - current_pointing[0]) - np.pi / 2
    return rotate_rad

def pid_control(desired_orientation, current_orientation):
    # Simplified model for torque calculation
    # In reality, it would depend on the satellite's orientation and Earth's magnetic field
    angular_difference = desired_orientation - current_orientation
    Kp = 0.1  # Proportional control constant
    return Kp * angular_difference

def model(torque, current_angular_velocity, current_orientation):
    max_angular_velocity = 1.0  # Set a maximum angular velocity limit

    angular_velocity_change = torque - current_angular_velocity**2
    current_angular_velocity += angular_velocity_change * dt
    current_angular_velocity = np.clip(current_angular_velocity, -max_angular_velocity, max_angular_velocity)
    current_orientation += current_angular_velocity * dt
    return current_angular_velocity, current_orientation

current_angular_velocity = 0.0  # Angular velocity in radians per second
current_orientation = 0.0  # Initial orientation in radians

def orbit(t):
    global current_angular_velocity, current_orientation
    # Compute the satellite's position
    x, y = compute_position(t)

    # Determine the desired orientation
    if is_inside_cone(x, y, GS_X, GS_Y, ATTITUDE_ADJUST_ANGLE):
        # Calculate the angle to rotate the CubeSat to point towards the PVD-GS
        desired_orientation = attitude_error_estimation([GS_X, GS_Y], [x, y])
    else:
        # Calculate the angle to rotate the CubeSat to point towards the center of the Earth
        desired_orientation = attitude_error_estimation(EARTH_CENTER, [x, y])

    # Calculate torque using magnetorquers
    torque = pid_control(desired_orientation, current_orientation)

    # Update the CubeSat's orientation
    current_angular_velocity, current_orientation = model(torque, current_angular_velocity, current_orientation)

    # Compute the satellite's rectangle and pointing vector
    rect_x, rect_y, pointing_x, pointing_y, pointing_angle = compute_rectangle(x, y, current_orientation)

    satellite.set_data(rect_x, rect_y)
    pointing_vector.set_data(pointing_x, pointing_y)
    pointing_angle_text.set_text(f'Point Angle: {np.degrees(pointing_angle):.2f}°')

    trans_cone_x, trans_cone_y = transmission_cone_coords(GS_COMM_ANGLE)
    transmission_cone_left.set_data([GS_X, trans_cone_x[0]], [GS_Y, trans_cone_y[0]])
    transmission_cone_right.set_data([GS_X, trans_cone_x[1]], [GS_Y, trans_cone_y[1]])

    attitude_adjust_cone_x, attitude_adjust_cone_y = attitude_adjust_cone_coords(ATTITUDE_ADJUST_ANGLE)
    attitude_adjust_cone_left.set_data([GS_X, attitude_adjust_cone_x[0]], [GS_Y, attitude_adjust_cone_y[0]])
    attitude_adjust_cone_right.set_data([GS_X, attitude_adjust_cone_x[1]], [GS_Y, attitude_adjust_cone_y[1]])

    return satellite, pointing_angle_text, pointing_vector, transmission_cone_left, transmission_cone_right, attitude_adjust_cone_left, attitude_adjust_cone_right

dt = 2.0
time_points = np.arange(0, T_ORBIT, dt)
ani = FuncAnimation(fig, orbit, frames=time_points, interval=2, blit=True)
plt.figtext(0.95, 0.01, f'Transmission Range = {GS_COMM_ANGLE_DEG:.2f}°', fontsize=10, ha='right', color='red')
plt.figtext(0.95, 0.03, f'Attitude Adjust Range = {ATTITUDE_ADJUST_ANGLE_DEG:.2f}°', fontsize=10, ha='right', color='green')
plt.show()
# ani.save('orbit_animation_r5.gif', writer='Pillow', fps=30)