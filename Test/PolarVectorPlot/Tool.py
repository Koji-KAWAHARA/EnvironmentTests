"""Basic tools for vector operations."""
import numpy as np


def Pol2Cart(theta, phi, axis):
    """Convert a vector from polar rep. to cartesian rep."""
    if axis == 1:
        return np.sin(theta)*np.cos(phi)
    if axis == 2:
        return np.sin(theta)*np.sin(phi)
    if axis == 3:
        return np.cos(theta)
