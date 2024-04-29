import numpy as np
import matplotlib.pyplot as plt

pi = np.pi
B = 2.0 * pi ** 2

def f(x):
    return np.where(x < 0, B * x ** 2,
                    np.where(x <= 1, 1 - np.cos(2.0 * pi * x),
                             B * (x - 1) ** 2))

x = np.linspace(-0.5, 1.5, 1000)
y = f(x)

plt.plot(x, y)
plt.xlabel('x')
plt.ylabel('Energy')
plt.title('Barrier Crossing')
plt.savefig('barrier.png')
