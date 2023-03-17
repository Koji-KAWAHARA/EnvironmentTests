#%%
import numpy as np
from scipy.ndimage.filters import sobel
import matplotlib.pyplot as plt

# Define the height map
M = np.array([
    [0, 0, 2],
    [0, 1, 3],
    [0, 2, 3],
    [0, 3, 2],
    [1, 0, 2],
    [1, 1, 3],
    [1, 2, 3],
    [1, 3, 2],
    [2, 0, 1],
    [2, 1, 2],
    [2, 2, 2],
    [2, 3, 1],
    [3, 0, 0],
    [3, 1, 1],
    [3, 2, 0],
    [3, 3, 0]
])

# Define the size of the height map
N = 4

# Reshape the height map into a 2-dimensional array
M = M[:,2].reshape(N, N)

# Apply the Sobel filter to detect ridges
sobelx = sobel(M, axis=0)
sobely = sobel(M, axis=1)
ridge_map = np.sqrt(sobelx**2 + sobely**2)

# Find the maximum values in the ridge map
max_values = np.argwhere(ridge_map == np.max(ridge_map))

# Convert the maximum values to polar coordinates
ridge_points = []
for i in range(len(max_values)):
    r = max_values[i][0]
    theta = max_values[i][1]
    h = M[r, theta]
    ridge_points.append((r, theta, h))

# Create a grayscale image of the height map
plt.imshow(M, cmap='gray')


# Overlay the detected ridge points on top of the image
for ridge_point in ridge_points:
    r = ridge_point[0]
    theta = ridge_point[1]
    plt.plot(theta, r, 'ro')

# Show the image with the ridge points overlaid
plt.show()

plt.imshow(ridge_map, cmap='gray')
