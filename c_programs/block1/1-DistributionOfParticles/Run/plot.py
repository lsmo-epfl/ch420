import numpy as np
import matplotlib.pyplot as plt

# Read the data from the file
results = np.loadtxt("results.dat")
analytical = np.loadtxt("analytical.dat")

# Plot the data
plt.scatter(results[:, 0], results[:, 1], marker=".", label="Simulation")
plt.plot(analytical[:, 0], analytical[:, 1], c='orange', label="Analytical")
plt.xlabel("Number of particles")
plt.ylabel("Distribution (a.u.)")
plt.title("Distribution of N particles over p boxes")
plt.legend()
plt.show()