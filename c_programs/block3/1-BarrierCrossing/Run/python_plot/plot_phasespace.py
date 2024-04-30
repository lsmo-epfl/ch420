import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt('../pos_vel.dat')

position = data[:, 0]
velocity = data[:, 1]

plt.plot(position, velocity, 'o', markersize=3)
plt.xlabel('Position')
plt.ylabel('Velocity')
plt.title('Phase space trajectories')

plt.savefig("phasespace.png")
