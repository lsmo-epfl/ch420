# import packages

import numpy as np
import matplotlib.pyplot as plt

# calculate normal distribution
def normal_dist(x, mean, var):
    std = var**0.5
    prob_density = np.exp(-0.5*((x-mean)/std)**2) / (std*(2*np.pi)**0.5)
    return prob_density


# load data
data = np.loadtxt("exercise_2.dat")

# generate normal distribution data
x = np.arange(-5, 5, 0.1)

m1, var1 = 0, 0.2
m2, var2 = 0, 1.0
m3, var3 = -1, 0.2

y1 = normal_dist(x, m1, var1)
y2 = normal_dist(x, m2, var2)
y3 = normal_dist(x, m3, var3)

# make plots
fig, ax = plt.subplots(1, 2, figsize=(14,6))

ax[0].plot(data[:, 0], data[:, 1])

ax[1].plot(x, y1, label=f"$\mu$=%s, $\sigma^{2}$=%s" %(m1, var1))
ax[1].plot(x, y2, label=f"$\mu$=%s, $\sigma^{2}$=%s" %(m2, var2))
ax[1].plot(x, y3, label=f"$\mu$=%s, $\sigma^{2}$=%s" %(m3, var3))

ax[1].set_xlabel("x")
ax[1].set_ylabel("$\phi_{\mu, \sigma^{2}}(x)$")
ax[1].set_ylim(-0.05, 1.05)
ax[1].legend()

fig.savefig("exe2.png")
