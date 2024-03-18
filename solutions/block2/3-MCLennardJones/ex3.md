## Ex 3

First of all, we need to tell students the formula to calculate virial

# Question 2

The pressure of system can be calculated by the following
$$
\begin{gathered}
P=\frac{\rho}{\beta}+\frac{v i r}{3 V} \\
v i r=-r \cdot \frac{d U(r)}{d r}
\end{gathered}
$$

In the program, the calculation formula of virial is missing.

# Question 4
The heat capacity is
$$
C_V=\frac{1}{N}\left(\frac{\partial U}{\partial T}\right)_V=\frac{\left\langle U^2\right\rangle-\langle U\rangle^2}{N k_B T^2}
$$

The unit of capacity is $k_b$. To make it dimensionless
$$
C v^*=\frac{C_v}{k_b}
$$

# Question 5

The mc_move file is slightly modified by adding a loop that all particles are displaced. Simulation is performed with the given run file. The particles number is reduced to 50. We could observe that the maximum displacements of the moves increase a lot after the modification. In the 8000/10000 step, the maximum distribution is set to 0.954. Before the modification, the maximum distribution is set to 0.224.

During the exercise session, we know that the Frenkel proved that for an N-particle system,
$$
P_{a c c, N}=\exp (-\rho N|\Delta|)
$$
I do not find this formulalar in book   

the maximum displacement decreases with $\mathrm{N}$, the number of particles displaced at a time. The low maximum displacement means that the phase space is slowly sampled. So it is inefficient that doing a trial move in which all particles are displaced.

Ratio is shown in output file

'''   
Number Of Att. To Displ. A Part.  : 500000  
Success: 317808 (63.561600)   
''''

# 3.6 Question 6

question:Instead of using a uniformly distributed displacement, one can also use a Gaussian displacement. Does this increase the efficiency of the simulation?

If one uses a Gaussian displacement, on the one hand, there is more chance for a small move and a small move is more likely to be accepted. But the small move will contribute less to the efficiency of the sampling.

On the other hand, there is less chance for a large move. Although a large move is less likely to be accepted, it contributes more to the efficiency of the sampling. The two effects may compensate each other and finally may not increase the efficiency of the simulation.