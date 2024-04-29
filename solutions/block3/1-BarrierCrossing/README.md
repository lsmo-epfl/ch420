# Q1
Second derivative of $U(x)$ should be continuous:
$B = 2\pi^2$

![plot](./Run/python_plot/barrier.png)

# Q2
## Expectations 
As long as the discussion makes sense. 

1. NVE: Like a circle. 

2. Andersen thermostat: Canonical distribution. 
 
3. Nose-Hoover chain: Canonical distribution. Note that the third figure below shows the Nose-Hoover thermostat. 

4. Monte Carlo: $P(U)$ is proportional to $exp[βU(x)]$.

![plot](./Run/results/phase.jpg)

## Results from simulations
![plot](./Run/results/thermostats/phasespace_NVE.png)
![plot](./Run/results/thermostats/phasespace_And.png)
![plot](./Run/results/thermostats/phasespace_NHC.png)
![plot](./Run/results/thermostats/phasespace_MC.png)

# Q3. Codes
1. (a) Velocities are not sampled. (b) MC can perform unphysical moves and sample regions that would be inaccessible with MD at the same temperature. 

2. At low and high temperatures the Hamiltonian (Energy) can be approximated by $E=\frac{1}{2}mv^2 + \frac{1}{2}\epsilon \pi^2 x^2$, which is the equation for an ellipse when E is constant. In the v(t), x(t)-plot this is a closed graph. At temperatures near the barrier height this will break down.

3. In principle the chain has to be infinite.

![plot](./Run/results/NHC_number/phasespace_NHC1.png)
![plot](./Run/results/NHC_number/phasespace_NHC2.png)
![plot](./Run/results/NHC_number/phasespace_NHC3.png)
![plot](./Run/results/NHC_number/phasespace_NHC4.png)

# Q4. Cross the barrier

Run the program at different temperatures. $T > (0.2-0.25)$

![plot](./Run/results/temperature/phasespace_NHC_T0.05.png)
![plot](./Run/results/temperature/phasespace_NHC_T0.1.png)
![plot](./Run/results/temperature/phasespace_NHC_T0.15.png)
![plot](./Run/results/temperature/phasespace_NHC_T0.2.png)

# Q5. Berendsen thermostat

Run the program with and without the stochastic term. 

![plot](./Run/results/Berendsen/phasespace_Berendsen.png)
![plot](./Run/results/Berendsen/phasespace_noStoch.png)

# Q6. Periodic potential energy
Change the code `force.c`.

## Diffusion coefficient as a function of T

At low temperatures (with respect to the barriers in the potential energy surface) the system is confined to one of the local energy minima most of the time. The diffusion is governed by a hopping dynamics, where the hopping over the barriers is a rare event using normal molecular dynamics. 

![plot](./Run/results/PeriodicPotential/T_NHC/msd_NHC_T0.1.png)
![plot](./Run/results/PeriodicPotential/T_NHC/msd_NHC_T0.3.png)
![plot](./Run/results/PeriodicPotential/T_NHC/msd_NHC_T0.5.png)
![plot](./Run/results/PeriodicPotential/T_NHC/msd_NHC_T0.7.png)
![plot](./Run/results/PeriodicPotential/T_NHC/msd_NHC_T0.9.png)

## Collision frequency

The Andersen thermostat adds a stochastic component to the inertial dynamics of the system. The higher the Andersen thermostat collision frequency the more the dynamics of the system will behave in a stochastic manner.

![plot](./Run/results/PeriodicPotential/Collision/msd_And_c1.png)
![plot](./Run/results/PeriodicPotential/Collision/msd_And_c5.png)
![plot](./Run/results/PeriodicPotential/Collision/msd_And_c10.png)