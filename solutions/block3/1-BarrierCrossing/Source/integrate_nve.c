#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "system.h"

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

void IntegrateNVE(void)
{
  double U,F,NewVelocity;

  // start modification
// Integration of equations of motion: Leap Frog.
    Force(Position,&U,&F);
    NewVelocity=Velocity+Tstep*F;
    Position+=Tstep*NewVelocity;
// Conserved quantity is v(t) = (Vpos + Vnew)/2.
// We square them, so we need a factor 8.
    ConservedEnergy=U+SQR(NewVelocity+Velocity)/8.0;
    Velocity=NewVelocity;
    OldF=F;

  // end modification
} 
