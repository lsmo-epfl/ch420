import numpy as np
import matplotlib.pyplot as plt

vacf = np.loadtxt('vacf.dat')

# Plotting
plt.figure(figsize=(10, 5))

# Plot Velocity autocorrelation function
plt.subplot(2, 1, 1)
plt.plot(vacf[:, 0], vacf[:, 1])
plt.xlabel('t')
plt.ylabel(r'$<v(0)v(t)>$')
plt.title('Velocity autocorrelation function')

# Plot Integral
plt.subplot(2, 1, 2)
plt.plot(vacf[:, 0], vacf[:, 2])
plt.xlabel('t')
plt.ylabel(r'Integral $<v(t)v(0)>$')
plt.title('Diffusion coefficient from VACF')

plt.tight_layout()
plt.savefig('vacf.png', dpi=300)
