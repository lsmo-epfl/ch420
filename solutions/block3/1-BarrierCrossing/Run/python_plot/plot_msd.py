import numpy as np
import matplotlib.pyplot as plt

# Assuming 'msd.dat' contains mean square displacement data
data = np.loadtxt('msd.dat')

position = data[:, 0]
msd = data[:, 1]

plt.plot(position, msd)
plt.xlabel('Position')
plt.ylabel(f'MSD $<r^2>$')
plt.title('Mean square displacement')

plt.savefig("msd_NHC_T0.9.png")