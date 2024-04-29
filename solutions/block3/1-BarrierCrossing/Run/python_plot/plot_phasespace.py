import numpy as np
import matplotlib.pyplot as plt

# Assuming 'pos_vel.dat' contains position and velocity data
data = np.loadtxt('pos_vel.dat')

position = data[:, 0]
velocity = data[:, 1]

plt.plot(position, velocity, 'o', markersize=3)
plt.xlabel('Position')
plt.ylabel('Velocity')
plt.title('Phase space trajectories')

plt.savefig("phasespace_noStoch.png")
