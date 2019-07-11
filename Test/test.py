"""Just a test."""
import matplotlib.pyplot as plt
import numpy as np

x = [1, 2, 3, 4, 5]
y = [10, 2, 4, 9, 3]
plt.plot(x, y)
plt.show()

for i in range(11):
    if (i < 10):
        print('%d' % i)
    else:
        print('%d!' % i)
