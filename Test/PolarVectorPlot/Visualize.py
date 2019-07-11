"""Reshape and visualize vector field."""
from mpl_toolkits.mplot3d import Axes3D  # imported to assign 3d axes.
import matplotlib.pyplot as plt
import numpy as np
import VectorData as Vec
import Tool

# no use in simple reshape. quiver3d requires exactly 6 imputs.
# theta = Vec.theta.reshape(Vec.Nx, Vec.Ny, Vec.Nz)
# phi = Vec.phi.reshape(Vec.Nx, Vec.Ny, Vec.Nz)
theta = Vec.theta
phi = Vec.phi

"""convert vector index to original lattice coordinate (xyz)"""
index = np.array(range(0, Vec.Nx*Vec.Ny*Vec.Nz))
x = index // (Vec.Ny*Vec.Nz)
y = index // Vec.Nz - Vec.Ny*x
z = index % Vec.Nz
print(x)
print(y)
print(z)

"""plot"""
# quiver(x,y,z,u,v,w,length=???)
# x,y,z : lattice point
# u,v,w : vector field
# length : shrink/elongate vector by this param.
fig = plt.figure()
ax = fig.gca(projection='3d')
ax.quiver(x, y, z, Tool.Pol2Cart(theta, phi, 1), Tool.Pol2Cart(theta, phi, 2), Tool.Pol2Cart(theta, phi, 3), length=0.1)
plt.show()

# """stack and calculation"""
# A = np.stack([theta, phi])
# B = np.stack([phi, theta])
# print(A+B)
