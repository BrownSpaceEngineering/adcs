import numpy as np
import matplotlib.pyplot as plt
from math import sin, cos
from abc import ABC, abstractmethod

class Constants:
    # TODO: Link sources for constants
    CORE_PERMEABILITY = 100000           # relative permeability of permalloy
    CORE_DENSITY = 8700                  # kg/m3
    WIRE_DENSITY = 8930                  # kg/m3
    WIRE_DIAMETER = 0.000254             # copper wire 30 AWG in m
    SATELLITE_MASS = 4                   # kg
    SATELLITE_LENGTH = 0.3               # m
    SATELLITE_WIDTH = 0.1                # m
    
    SATELLITE_SURFACE_AREA = (4 * SATELLITE_LENGTH * SATELLITE_WIDTH) + (2 * SATELLITE_WIDTH * SATELLITE_WIDTH) #m2
   
    # long axis               
    INERTIA_Z = 1/12 * SATELLITE_MASS * (SATELLITE_WIDTH**2 + SATELLITE_LENGTH**2)
    # short axes
    INERTIA_XY = 1/12 * SATELLITE_MASS * (SATELLITE_WIDTH**2 + SATELLITE_WIDTH**2)
    
    SECONDS_PER_ORBIT = 5574             # s
    EARTH_BFIELD_EQUATOR = 0.000026      # Tesla
    EARTH_BFIELD_NORTHPOLE = 0.000048    # Tesla

    WIRE_TEMP_COEFF = 0.00393            # 1/Celsius
    WIRE_REF_RESISTIVITY = 1.71e-8       # Ohm*m
    TEMP_REF = 20                        # Celsius
    MAX_TEMP = 80                        # Celsius
    MIN_TEMP = -80                       # Celsius

    MU_0 = 4 * np.pi * 10**-7            # H/m

class Magnetorquer(ABC):
    '''
    Abstract class for magnetorquer
    '''
    def __init__(self, current, core_length, layers, temp) -> None:
        '''
        param current: current in Amps (MAX 0.1 A for 30AWG wire)
        param core_length: length of core in meters
        param layers: number of layers of coils
        param temp: temperature in Celsius
        '''
        if current > 0.1: raise ValueError("Current exceeds maximum current of 0.1 A for 30 AWG wire")
        
        self.current = current
        self.core_length = core_length
        self.layers = layers
        self.temp = temp
        self.turns_per_layer = core_length / Constants.WIRE_DIAMETER
        self.turns = int(np.floor(self.turns_per_layer * layers))
        self.total_mass = self.core_mass() + self.wire_mass()

        # Voltage required to achieve given current
        self.voltage = current * self.wire_resistance(self.temp)

        # Max voltage required to achieve given current
        self.max_voltage = current * self.wire_resistance(Constants.MAX_TEMP)

        # Increase in radius due to wire thickness
        self.wire_height = Constants.WIRE_DIAMETER * ( 1 + np.sqrt(3) * (layers - 1) )

        super().__init__()
    
    @abstractmethod
    def dipole_moment(self):
        pass

    @abstractmethod
    def wire_length(self):
        pass

    @abstractmethod
    def core_mass(self):
        pass

    def wire_mass(self):
        wire_volume = self.wire_length() * np.pi * (Constants.WIRE_DIAMETER / 2) ** 2
        return wire_volume * Constants.WIRE_DENSITY

    def wire_resistance(self, temp):
        '''
        param temp: temperature in Celsius
        '''
        resist = Constants.WIRE_REF_RESISTIVITY * (1 + Constants.WIRE_TEMP_COEFF * (temp - Constants.TEMP_REF))
        cross_section = np.pi * (Constants.WIRE_DIAMETER / 2) ** 2
        return resist * self.wire_length() / cross_section


class CoreMagnetorquer(Magnetorquer):

    def __init__(self, current, core_radius, core_length, layers, temp):
        self.core_radius = core_radius
        super().__init__(current, core_length, layers, temp)
        self.total_radius = core_radius + self.wire_height

    def dipole_moment(self):
        super().dipole_moment()
        r, N, I, mu, L = self.core_radius, self.turns, self.current, Constants.CORE_PERMEABILITY, self.core_length
        Nd = (4*(np.log(L/r) - 1))/((L/r)**2 - 4*(np.log(L/r)))
        return np.pi * (r**2) * N * I * (1 + ((mu - 1)/(1 + ((mu - 1) * Nd))))

    def core_mass(self):
        super().core_mass()
        core_volume = (self.core_radius **2) * self.core_length * np.pi
        return core_volume * Constants.CORE_DENSITY  

    def wire_length(self):
        super().wire_length()
        length = 0
        for i in range(self.layers):
            h_row = Constants.WIRE_DIAMETER * (1/2 + np.sqrt(3) * i)
            r_turn = self.core_radius + h_row
            length += 2 * np.pi * r_turn * self.turns_per_layer
        return length

    def __str__(self) -> str:
        out = f"\nCORE MAGNETORQUER INFO\n"
        out += f"####################################################################\n"
        out += f"Core radius:                              {self.core_radius * 100} cm\n"
        out += f"Core length:                              {self.core_length * 100} cm\n"
        out += f"Number of Turns:                          {self.turns}\n"
        out += f"Number of Layers:                         {self.layers}\n"
        out += f"Dipole Moment:                            {self.dipole_moment()} A*m^2\n"
        out += f"Total Mass:                               {self.total_mass} kg\n"
        out += f"Wire Length:                              {self.wire_length()} m\n"
        out += f"Theoretical Wire Resistance:              {self.wire_resistance(self.temp)} Ohms\n"
        out += f"Voltage Required at                       {self.temp}\N{DEGREE SIGN}C: {self.voltage}\n"
        out += f"Voltage Required at                       {Constants.MAX_TEMP}\N{DEGREE SIGN}C: {self.max_voltage} V\n"
        out += f"Total Radius:                             {self.total_radius*1000} mm"
        out += f"\n####################################################################\n"
        return out

class AirMagnetorquer(Magnetorquer):
    def __init__(self, current, side_length, core_length, layers, temp) -> None:
        self.side_length = side_length
        super().__init__(current, core_length, layers, temp)
        self.total_side_length = self.side_length + 2*self.wire_height

    def dipole_moment(self):
        super().dipole_moment()
        return self.side_length**2 * self.turns * self.current
    
    def core_mass(self):
        super().core_mass()
        return 0
    
    def wire_length(self):
        super().wire_length()
        length = 0
        for i in range(self.layers):
            h_row = Constants.WIRE_DIAMETER * (1/2 + np.sqrt(3) * i)
            length += 4 * (self.side_length + ( 2 * h_row)) * self.turns_per_layer
        return length

    def __str__(self) -> str:
        out = f"\nAIR MAGNETORQUER INFO\n"
        out += f"####################################################################\n"
        out += f"Number of Turns:                          {self.turns}\n"
        out += f"Number of Layers:                         {self.layers}\n"
        out += f"Dipole Moment:                            {self.dipole_moment()} A*m^2\n"
        out += f"Total Mass:                               {self.total_mass} kg\n"
        out += f"Wire Length:                              {self.wire_length()} m\n"
        out += f"Theoretical Wire Resistance:              {self.wire_resistance(self.temp)} Ohms\n"
        out += f"Voltage Required at                       {self.temp}\N{DEGREE SIGN}C: {self.voltage}\n"
        out += f"Voltage Required at                       {Constants.MAX_TEMP}\N{DEGREE SIGN}C: {self.max_voltage} V\n"
        out += f"Total Side Length:                        {self.total_side_length*1000} mm"
        out += f"\n####################################################################\n"
        return out

class SingleAxisDipoleModel:
    def __init__(self, magnetorquer: Magnetorquer, dt, orbits) -> None:
        '''
        param magnetorquer: Magnetorquer object
        param dt: time step (seconds)
        param orbits: number of orbits to simulate
        '''
        self.magnetorquer = magnetorquer
        self.T = orbits * Constants.SECONDS_PER_ORBIT
        self.dt = dt
        self.n = int(self.T / self.dt)

        # Variables
        self.theta = np.zeros(self.n)       # orientation angle (rads)
        self.omega = np.zeros(self.n)       # angular velocity (rad/s)
        self.alpha = np.zeros(self.n)       # angular acceleration (rad/s/s)

        # Initial Conditions
        self.theta[0] = np.pi
        self.omega[0] = 0.0

        # Euler Method 
        self.convergence_time = -1
        self.convergence_iteration = self.n
        for i in range(self.n - 1):
            self.alpha[i] = -self.magnetorquer.dipole_moment() * Constants.EARTH_BFIELD_EQUATOR/Constants.INERTIA_Z
            self.omega[i + 1] = self.omega[i] + self.alpha[i] * dt
            self.theta[i + 1] = self.theta[i] + self.omega[i] * dt
            if self.theta[i - 1] >= 0 and self.theta[i] < 0:
                self.convergence_time = i*dt
                self.convergence_iteration = i  # for plotting purposes
                break

    def plot(self):
        plt.figure(figsize=(10, 6))
        plt.plot(np.linspace(0, self.convergence_time, self.convergence_iteration), self.theta[:self.convergence_iteration])
        
        #x = np.linspace(0, round(self.convergence_time), round(self.convergence_time))
        #plt.plot(x, self.theta[:round(self.convergence_time)])
        plt.ylim(0, self.theta[0])
        #plt.xlim(0, round(self.convergence_time))
        plt.xlabel('Time (seconds)')
        plt.ylabel('Theta (radians)')
        plt.title('Orientation over Time')
        plt.grid(True)
        plt.show()

    def __str__(self) -> str:
        out = f"\nSINGLE AXIS DIPOLE MODEL\n"
        out += f"####################################################################\n"
        if self.convergence_time > 0:
            out += f"Convergence Time:                     {round(self.convergence_time, 3)} s\n"
            out += f"Convergence Achieved in               {round(self.convergence_time / Constants.SECONDS_PER_ORBIT, 5)} orbits\n"
        else:
            out += f"SIMULATION DID NOT CONVERGE\n"

        out += f"####################################################################\n"
        return out
    
class DisturbanceModel:
    def __init__(self, orbit_altitude) -> None:
        self.altitude = (orbit_altitude + 6378.14) * 1000 #adds radius of the Earth to get orbital semimajor axis (m)

    def gravity_gradient(self):
        mu = 3.986 * (10**14) #Earth's gravity constant (m3/s2)
        z_axis_deviation = np.pi #6*np.pi/180 #the maximum deviation of the Z-axis from local vertical (rad) -- TODO: old spreadsheet uses 6 degrees?

        max_gravity_torque = (3 * mu)/(2 * (self.altitude ** 3)) * abs(Constants.INERTIA_Z - Constants.INERTIA_XY) * abs(sin(2*z_axis_deviation))

        return max_gravity_torque
    
    def solar_radiation(self):
        solar_constant = 1367    #solar radiation flux constant (W/m2)
        light_speed = 3*(10**8)  #m/s
        
        reflectance_factor = 0.6 #ranges on [0, 1]
        angle_incidence_to_sun = 0 #(rad) chosen to maximize term
        pressure_differential = Constants.SATELLITE_LENGTH/2 #supposed to be center_solar_pressure - center_gravity. Chose the magnitude of longest distance from surface to center

        F = (solar_constant / light_speed) * Constants.SATELLITE_SURFACE_AREA * (1 + reflectance_factor) * cos(angle_incidence_to_sun)

        max_solar_torque = F*(pressure_differential)
        
        return max_solar_torque
    
    def aerodynamic(self):
        atmospheric_density = 2.62*(10**-12) #mean atmospheric density at 400km (kg/m3) 
        drag_coefficient = 2.25 #usually between 2 and 2.5
        satellite_velocity = 2*np.pi *self.altitude / Constants.SECONDS_PER_ORBIT #approximation (m/s)

        F = 0.5 * atmospheric_density * drag_coefficient * Constants.SATELLITE_SURFACE_AREA * (satellite_velocity ** 2)
        pressure_differential = Constants.SATELLITE_LENGTH/2 #supposed to be center_aerodynamic_pressure - center_gravity. Chose the magnitude of longest distance from surface to center

        aerodynamic_torque = F * pressure_differential
        return aerodynamic_torque
    
    def total_disturbance(self):
        return self.solar_radiation() + self.gravity_gradient() + self.aerodynamic()

    def __str__(self) -> str:
        out = f"\nDISTURBANCE TORQUE PREDICTIONS\n"
        out += f"####################################################################\n"
        out += f"Solar Radiation Torque:                   {self.solar_radiation()} Nm\n"
        out += f"Gravity Gradient Torque:                  {self.gravity_gradient()} Nm\n"
        out += f"Aerodynamic Torque:                       {self.aerodynamic()} Nm\n"
        out += f"TOTAL DISTURBANCE TORQUES:                {self.total_disturbance()} Nm\n"
        out += f"####################################################################\n"

        return out

def rigid_body_torque(mass, angle, diameter, time):
    # In: mass in kg, angle of motion in degrees, diameter of rotating body in m, time to rotate in s
    # Out: a torque to induce motion in specified time in Nm 

    d = diameter * 3.14 * (angle / 360)
    v = d / time 
    r = diameter/2
    a = v/(r**2)
    F = mass * a
    torque = F * d
    return torque

def calculate_bfield(r, m):
    '''
    param r: position vector of observation
    param m: magnetic dipole moment vector
    '''
    return Constants.MU_0 / (4 * np.pi) * ( (3 * r * np.dot(m,r)) / np.linalg.norm(r)**5 - m / np.linalg.norm(r)**3 )



######################################
##             INPUTS               ##
######################################

current = 0.08                       # Amps - 0.1A max through 30 AWG wire
temp = 20                            # Celsius

m1_radius = 0.005
m1_length = 0.06
m1_layers = 5

m2_radius = 0.005
m2_length = 0.06
m2_layers = 8

m_3_side_length = 0.07
m_3_length = 0.02
m_3_layers = 6

orbit_altitude = 400
######################################

m1 = CoreMagnetorquer(current, m1_radius, m1_length, m1_layers, temp)
m2 = CoreMagnetorquer(current, m2_radius, m2_length, m2_layers, temp)
am = AirMagnetorquer(current, m_3_side_length, m_3_length, m_3_layers, temp)

sim = SingleAxisDipoleModel(am, 0.01, 1)
sim.plot()
print(sim) 

print(f"MAX POSSIBLE POWER USAGE (Max voltage method):     {(m1.max_voltage + m2.max_voltage + am.max_voltage) * current} W")
print(f"MAX POSSIBLE POWER USAGE (9.9 * Current Method):   {9.9 * current} W\n")

disturbances = DisturbanceModel(orbit_altitude)
print(disturbances)

print(f"MINIMUM TORQUE GENERATED:                          {m1.dipole_moment() * Constants.EARTH_BFIELD_EQUATOR} Nm")
print(f"RIGID BODY PREDICTED TORQUE REQUIREMENT:           {rigid_body_torque(Constants.SATELLITE_MASS, sim.theta[0], Constants.SATELLITE_LENGTH, sim.convergence_time)} Nm\n")

print("B field (T)", np.linalg.norm(calculate_bfield(np.array([0,0,0.05]), np.array([0,0,0.1]))))
print("B field (mT)", np.linalg.norm(calculate_bfield(np.array([0.05,0,0]), np.array([0,0,0.1])))*10**3)

if (m1.dipole_moment() * Constants.EARTH_BFIELD_EQUATOR) < disturbances.total_disturbance():
    out =  "\n-------------------------------------------------------------------\n"
    out += "!    MODEL FAILS - DISTURBANCE TORQUES EXCEED GENERATED TORQUE    !"
    out += "\n-------------------------------------------------------------------\n"
    print(out)
elif ((m1.max_voltage + m2.max_voltage + am.max_voltage) * current) > 0.84:
    out =  "\n-------------------------------------------------------------------\n"
    out += "!         MODEL FAILS - POWER REQUIREMENT EXCEEDS BUDGET          !"
    out += "\n-------------------------------------------------------------------\n"
    print(out)
elif (sim.convergence_time / Constants.SECONDS_PER_ORBIT) > 1:
    out =  "\n-------------------------------------------------------------------\n"
    out += "!       MODEL FAILS - CONVERGENCE TIME EXCEEDS ONE ORBIT          !"
    out += "\n-------------------------------------------------------------------\n"
    print(out)
else:
    out =  "\n-------------------------------------------------------------------\n"
    out += "!                          MODEL PASSES                           !"
    out += "\n-------------------------------------------------------------------\n"
    print(out)
