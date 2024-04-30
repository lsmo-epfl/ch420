import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt('../density.dat')

position = data[:, 0]
distribution = data[:, 1]

plt.plot(position, distribution)
plt.xlabel('Position')
plt.ylabel('Distribution')

plt.savefig("density.png")