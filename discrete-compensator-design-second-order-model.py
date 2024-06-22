# -*- coding: utf-8 -*-
from sympy import Symbol, fraction, simplify, expand, roots, LC
from math import pi, exp, log, cos
z = Symbol('z')
#%% Discretized plant
R=5; Rs=1; T= 10e-6; H=1; C=10e-6
wp= 1/(R*C); fp=wp/(2*pi);
BGc= (R/Rs)*( 1 - exp(-wp*T) )/(z - exp(-wp*T))
BGcH= BGc*H
print ("BGc=", BGc)
print("-----")
#%% Model M
Mp=0.3; Kp=4;
Theta= pi/Kp; Sigma= -(Theta/pi)*log(Mp)
k= 1 - 2*exp(-Sigma)*cos(Theta) + exp(-2*Sigma)
M= k/( z**2 - 2*exp(-Sigma)*cos(Theta)*z + exp(-2*Sigma) )
print("M= ", M)
M_den= fraction(M)[1];
Poles_M=roots(M_den)
print("Poles_M= ", Poles_M)
print("-----")
#%% Compensator calculation by direct synthesis
C= simplify ( M/(BGc - BGcH*M) ) 
print("C= ",  C)
# Get leading coefficient of the denominator (LC) to normalize
lead_coeff=LC(fraction(C)[1])
# Get C's numerator and denominator and normalize
Cnum= expand( fraction(C)[0] )/lead_coeff
Cden= fraction(C)[1]/lead_coeff
print("Cnum= ", Cnum); print("Cden= ", Cden)
print("-----")
#%% Verification. Final closed-loop transfer function
Gcl= simplify ( C*BGc/( 1 + C*BGcH  ) )
gain= Gcl.evalf(subs={z:1})
print("Gcl= ", Gcl); print("Gain= ", gain)
Gcl_num= fraction(Gcl)[0]; Gcl_den= fraction(Gcl)[1];
print("Gcl_num= ", Gcl_num); print("Gcl_den= ", Gcl_den)
Zeros_Gcl=roots(Gcl_num); Poles_Gcl=roots(Gcl_den)
print("Zeros_Gcl= ", Zeros_Gcl); print("Poles_Gcl= ", Poles_Gcl)
print("-----")








































