import numpy as np
import matplotlib.pyplot as plt

# Load data from file
msd = np.loadtxt('msd.dat')

fig, ax1 = plt.subplots()

# Plot Mean square displacement on the left y-axis
l1, = ax1.plot(msd[:,0], msd[:,1], 'b-', label='MSD')
ax1.set_xlabel('t')
ax1.set_ylabel(r'$\Delta r^2(t)$', color='b')
ax1.tick_params('y', colors='b')
first_legend = ax1.legend(handles=[l1], loc='upper right')

# Create the right y-axis for Diffusion coefficient
ax2 = ax1.twinx()
l2, = ax2.plot(msd[:,0], msd[:,2], 'r-', label='Diffusion Coefficient')
ax2.set_ylabel('D', color='r')
ax2.tick_params('y', colors='r')

# Create another legend for the second line.
ax1.add_artist(first_legend)
ax1.legend(handles=[l2], loc='lower right')

fig.tight_layout()
fig.savefig('msd.png', dpi=300)