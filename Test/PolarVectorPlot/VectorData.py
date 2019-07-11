"""Define vectors that contains angles of spherical coordinate."""
import math
import numpy as np
# size : 2*2*2
# numbering :
# lattice point (x,y,z) w. x = 0 - (Nx-1)
# -> vector index NyNz*x + Nz*y + z
# vector index range : 0 - (NxNyNz-1)
Nx = 2
Ny = 2
Nz = 2
pi = math.pi
theta = np.array([0, 0, 0, 0, pi/2, pi/2, pi/2, pi/2])
phi = np.array([0, 0, 0, 0, pi/2, pi/2, 0, 0])
