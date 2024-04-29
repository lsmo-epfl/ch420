#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "system.h"
#include "ran_uniform.h"

// integrate the equations of motion for an NVE system
// use either velocity verlet or leap-frog. you do not
// have to declare any new variables
//
// hint: use the following symbols:
//
// Tstep            : timestep integration
// Position         : old position
// OldF             : old force
// ConservedEnergy  : conserved quantity
//
// to calculate the force and energy for a given position,
// see force.c

void IntegrateBerendsen(void)
{
  double U,F,NewVelocity;
  double Ekin, tau = 0.01, Berendsen, Stoch=0, Scale, lambda;

  // Integration of equations of motion: Leap Frog.
  Force(Position,&U,&F);

  Ekin = Velocity*Velocity;
  //begin modification
  if(Ekin<0.0001)
  {
      Ekin=0.0001;
  }
  Berendsen = (Temperature - Ekin)*(Tstep/tau);
  double lambdasqr;
  do 
  {
      Stoch = 2.0 * sqrt((Ekin * Temperature)* (Tstep/tau)) *RandomGaussianNumber();
      // Stoch = 0;
      Scale = Berendsen + Stoch;
      lambdasqr=(Ekin+Scale)/Ekin;
  }while (lambdasqr<=0);
  lambda=sqrt(lambdasqr);
  //end modification
  NewVelocity=lambda*(Velocity+Tstep*F);
  Position+=Tstep*NewVelocity;
  // Conserved quantity is v(t) = (Vpos + Vnew)/2.
  ConservedEnergy=U + (((NewVelocity+Velocity)/2.0) * ((NewVelocity+Velocity)/2.0));
  Velocity=NewVelocity;
  OldF=F;
} 
