# Ex 2 answers

## Q1
From state nj = 0, there is no probability to go to any state that nj < 0 since it is not defined in our phase space. Because any state that nj < 0 is not accessible, there is no probability to go from states that nj < 0 to states that nj = 0. The two probability are both zero so the detail balance is maintained.
## Q2

The algorithm is still correct when trial moves are performed that change nj with a random integer from the interval [-5, 5]. However, it will take a longer time to sample the entire phase space.
The algorithm is not correct when trial moves are performed that change nj with either -3 or +3. In this case, starting from k, the the occupancy number can only be 3n + k, so not all the configuration are explored in sampling.

## Q3

The program clearly shows how moves and samples are performed in a 1-Dimension Monte Carlo simulation. In the looping, the simulation starts from the first occupancy number. Then, a trial move to randomly increase or decrease nj by 1 is performed. Finally, reject or accept the trial move depending on the acceptance rule. During the looping, the occupancy number is sampling.

In code, the part for a trial move is missing.

## Q4

Result is generated with the same run_auto file and is plotted with the gnuplot script. It is observed that the simulation result (Figure 2) does not match the analytical solution.
They are erroneous result because the probability of not moving is not zero. If we only sample after an accepted trial move, the detail balance is no longer maintained.
When the β is higher, or in other words, the temperature is lower, this error becomes more pronounced. At lower temperature, there is a larger probability of rejecting a move and therefore more configurations that stay the same after one trail move. We are not sampling these configurations so the error is more pronounced.
