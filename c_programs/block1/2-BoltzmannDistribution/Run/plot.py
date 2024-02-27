import numpy as np
import matplotlib.pyplot as plt

# Load data
data = np.loadtxt('results.dat')
x = data[:, 0]
y = data[:, 1]

plt.figure()
plt.plot(x,y, lw=3)
plt.xlabel('energy level')
plt.ylabel('distribution')
plt.title('Boltzmann distribution')
plt.tight_layout()
plt.savefig('boltzmann_distribution.png')
plt.show()
plt.close()