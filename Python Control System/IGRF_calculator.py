import csv
# import "igrf_coeffs.csv"
import numpy as np
import math
from sympy import symbols, diff, sin, cos, Function
import csv
# Path: adcs/IGRF_calculator.py


theta, phi, r = symbols('theta phi r')



def calc_k_n(n,m):
    if m == 0:
        return 1/(2**n)
    else:
        return 1/(2**n) * math.sqrt(2*math.factorial(n-m)/math.factorial(n+m))
    

def calc_P_n_m(n,m,theta):

    u=cos(theta)
    y = (u**2 - 1)**n

    derivative = diff(y,theta,n+m) / diff(u, theta, n+m)
    
    return calc_k_n(n,m) * (sin(theta)**m) * derivative

def IGRF_calculator(r_1, phi_1, theta_1, t):
    """
    Calculates the magnetic field vector in the body frame of the satellite
    using the IGRF model.
    :param time: Time in seconds since the epoch
    :param position: Position vector in the ECI frame in meters
    :return: Magnetic field vector in the body frame in Teslas
    """
    a = 6371  # equatorial radius of the Earth in meters
    N = 13 # Max degree of spherical harmonic expansion

    igrf_table = np.zeros((14,14,2))  # nxmx2 array
    sv_table = np.zeros((14,14,2))  # nxmx2 array
    

    with open('igrf_coeffs.csv', 'r') as file:
        reader = csv.reader(file, delimiter='\t')
        for row in reader:
            # print(row)
            isG = True if str(row[0]).strip() == 'g' else False
            n = int(row[1])
            m = int(row[2])
            if isG:
                # print(n,m)
                igrf_table[n][m][0] = row[3]
                sv_table[n][m][0] = row[4]
            else:
                igrf_table[n][m][1] = row[3]
                sv_table[n][m][1] = row[4]
    V = 0
    for n in range(1,N+1):
        for m in range(0,n+1):
            V += ((a/r)**(n+1) * (igrf_table[n][m][0] * cos(m*phi) + igrf_table[n][m][1] * sin(m*phi)) * calc_P_n_m(n,m,theta))

    V = V * a

    Bx = diff(V,r).subs(r,r_1).subs(phi,phi_1).subs(theta,theta_1).evalf()
    By = (1/r * diff(V,theta)).subs(r,r_1).subs(phi,phi_1).subs(theta,theta_1).evalf()
    Bz = (1/(r*sin(theta)) * diff(V,phi)).subs(r,r_1).subs(phi,phi_1).subs(theta,theta_1).evalf()
    
    B = -np.array([float(Bx),float(By),float(Bz)])
    print(B)
    print(f'{np.linalg.norm(B)} nT')


IGRF_calculator(6371,-71.418884,41.825226,4)