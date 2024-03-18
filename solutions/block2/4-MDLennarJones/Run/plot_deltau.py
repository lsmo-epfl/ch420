import numpy as np
from glob import glob
import matplotlib.pyplot as plt

# Read the data from the file
drift_files = sorted(glob("drift*.dat"))
temperatures = []
drifts = []
for file in drift_files:
    drift = np.loadtxt(file)
    drifts.append(drift)
    
    temp = float(file.split("drift-")[1].split(".dat")[0])
    temperatures.append(temp)

# Plot the data
for temp, drift in zip(temperatures, drifts):
    plt.plot(drift[:, 0], drift[:, 1], marker=".", label=temp)
plt.xlabel("Time step")
plt.ylabel("Delta U")
plt.title("Energy drift as a function of time step")
plt.legend()
plt.tight_layout()
plt.savefig("deltau.png", dpi=300)