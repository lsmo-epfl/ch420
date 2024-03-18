#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "system.h" 

/*
// integrate the equations of motion and calculate the total impulse
void Integrate(double Step,VECTOR *Momentum)
{ 
  int i;
  double Scale;
  VECTOR NewPositions[MAXPART];

  // set kinetic energy to zero 
  // verlet integrator
  UKinetic=0.0;
  for(i=0;i<NumberOfParticles;i++)
  {
    NewPositions[i].x=2.0*Positions[i].x-OldPositions[i].x+Forces[i].x*SQR(Deltat);
    NewPositions[i].y=2.0*Positions[i].y-OldPositions[i].y+Forces[i].y*SQR(Deltat);
    NewPositions[i].z=2.0*Positions[i].z-OldPositions[i].z+Forces[i].z*SQR(Deltat);
 
    Velocities[i].x=(NewPositions[i].x-OldPositions[i].x)/(2.0*Deltat);
    Velocities[i].y=(NewPositions[i].y-OldPositions[i].y)/(2.0*Deltat);
    Velocities[i].z=(NewPositions[i].z-OldPositions[i].z)/(2.0*Deltat);
 
    UKinetic+=0.5*(SQR(Velocities[i].x)+SQR(Velocities[i].y)+SQR(Velocities[i].z));
  }
 
  // for NumberOfSteps < NumberOfInitializationSteps; use the velocity 
  // scaling to get the exact temperature 
  // otherwise: Scale=1.0 beware that the positions/velocities have to be
  // recalculated !!!!

  if(Step<NumberOfInitializationSteps)
    Scale=sqrt(Temperature*(3.0*NumberOfParticles-3.0)/(2.0*UKinetic));
  else
    Scale=1.0;
 
  UKinetic=0.0;
  (*Momentum).x=0.0;
  (*Momentum).y=0.0;
  (*Momentum).z=0.0;
 
  // scale velocities and put particles back in the box
  // beware: the old positions are also put back in the box 
  for(i=0;i<NumberOfParticles;i++)
  {
    Velocities[i].x*=Scale;
    Velocities[i].y*=Scale;
    Velocities[i].z*=Scale;
 
    (*Momentum).x+=Velocities[i].x;
    (*Momentum).y+=Velocities[i].y;
    (*Momentum).z+=Velocities[i].z;
 
    // error 1, add two fold for the second term, see the Verlet algorithm
    NewPositions[i].x=OldPositions[i].x+2.0*Velocities[i].x*Deltat;
    NewPositions[i].y=OldPositions[i].y+2.0*Velocities[i].y*Deltat;
    NewPositions[i].z=OldPositions[i].z+2.0*Velocities[i].z*Deltat;

    PositionsNONPDB[i].x+=NewPositions[i].x-Positions[i].x;
    PositionsNONPDB[i].y+=NewPositions[i].y-Positions[i].y;
    PositionsNONPDB[i].z+=NewPositions[i].z-Positions[i].z;
 
    UKinetic+=0.5*(SQR(Velocities[i].x)+SQR(Velocities[i].y)+SQR(Velocities[i].z));
 
    OldPositions[i].x=Positions[i].x;
    OldPositions[i].y=Positions[i].y;
    OldPositions[i].z=Positions[i].z;
 
    Positions[i].x=NewPositions[i].x;
    Positions[i].y=NewPositions[i].y;
    Positions[i].z=NewPositions[i].z;

    // put particles back in the box
    // the previous position has the same transformation (Why ?)
    if(Positions[i].x>=Box)
    {
      Positions[i].x-=Box;
      OldPositions[i].x-=Box;
    }
    else if (Positions[i].x<0.0)
    {
      Positions[i].x+=Box;
      OldPositions[i].x+=Box;
    }
 
    if(Positions[i].y>=Box)
    {
      Positions[i].y-=Box;
      OldPositions[i].y-=Box;
    }
    else if(Positions[i].y<0.0)
    {
      Positions[i].y+=Box;
      OldPositions[i].y+=Box;
    }
 
    if(Positions[i].z>=Box)
    {
      Positions[i].z-=Box;
      OldPositions[i].z-=Box;
    }
    else if(Positions[i].z<0.0)
    {
      Positions[i].z+=Box;
      OldPositions[i].z+=Box;
    }
  }
 
  // add the kinetic part of the pressure
  // error 2, momentum conservation
  Pressure+=2.0*UKinetic*NumberOfParticles/(CUBE(Box)*(3.0*NumberOfParticles-3.0));
}
*/

/*
void Integrate(double Step,VECTOR *Momentum)
{ 
  int i;
  double Scale;
  VECTOR NewPositions[MAXPART];
  VECTOR OldForces[MAXPART];

  // set kinetic energy to zero 
  // Velocity verlet
  UKinetic=0.0;
  for(i=0;i<NumberOfParticles;i++)
  {
    NewPositions[i].x = Positions[i].x + Velocities[i].x * Deltat + 0.5 * Forces[i].x * SQR(Deltat);
    NewPositions[i].y = Positions[i].y + Velocities[i].y * Deltat + 0.5 * Forces[i].y * SQR(Deltat);
    NewPositions[i].z = Positions[i].z + Velocities[i].z * Deltat + 0.5 * Forces[i].z * SQR(Deltat);

    // record initial positions and forces
    OldPositions[i].x = Positions[i].x;
    OldPositions[i].y = Positions[i].y;
    OldPositions[i].z = Positions[i].z;

    OldForces[i].x = Forces[i].x;
    OldForces[i].y = Forces[i].y;
    OldForces[i].z = Forces[i].z;

    // calculate force of t+dt
    Positions[i].x = NewPositions[i].x;
    Positions[i].y = NewPositions[i].y;
    Positions[i].z = NewPositions[i].z;

    PositionsNONPDB[i].x += NewPositions[i].x - OldPositions[i].x;
    PositionsNONPDB[i].y += NewPositions[i].y - OldPositions[i].y;
    PositionsNONPDB[i].z += NewPositions[i].z - OldPositions[i].z;
  }

  Force();
  for(i=0;i<NumberOfParticles;i++)
  {
    // calculate velocity
    Velocities[i].x += (Forces[i].x + OldForces[i].x) * 0.5 * Deltat;
    Velocities[i].y += (Forces[i].y + OldForces[i].y) * 0.5 * Deltat;
    Velocities[i].z += (Forces[i].z + OldForces[i].z) * 0.5 * Deltat;

    UKinetic += 0.5 * (SQR(Velocities[i].x) + SQR(Velocities[i].y) + SQR(Velocities[i].z));
  }

  // for NumberOfSteps < NumberOfInitializationSteps; use the velocity 
  // scaling to get the exact temperature 
  // otherwise: Scale=1.0 beware that the positions/velocities have to be
  // recalculated !!!!

  if(Step<NumberOfInitializationSteps)
    Scale=sqrt(Temperature*(3.0*NumberOfParticles-3.0)/(2.0*UKinetic));
  else
    Scale=1.0;
 
  UKinetic=0.0;
  (*Momentum).x=0.0;
  (*Momentum).y=0.0;
  (*Momentum).z=0.0;
 
  // scale velocities and put particles back in the box
  // beware: the old positions are also put back in the box 
  for(i=0;i<NumberOfParticles;i++)
  {
    Velocities[i].x*=Scale;
    Velocities[i].y*=Scale;
    Velocities[i].z*=Scale;
 
    (*Momentum).x+=Velocities[i].x;
    (*Momentum).y+=Velocities[i].y;
    (*Momentum).z+=Velocities[i].z;

 
    UKinetic+=0.5*(SQR(Velocities[i].x)+SQR(Velocities[i].y)+SQR(Velocities[i].z));

    // put particles back in the box
    // the previous position has the same transformation
    if(Positions[i].x>=Box)
    {
      Positions[i].x-=Box;
    }
    else if (Positions[i].x<0.0)
    {
      Positions[i].x+=Box;
    }
 
    if(Positions[i].y>=Box)
    {
      Positions[i].y-=Box;
    }
    else if(Positions[i].y<0.0)
    {
      Positions[i].y+=Box;
    }
 
    if(Positions[i].z>=Box)
    {
      Positions[i].z-=Box;
    }
    else if(Positions[i].z<0.0)
    {
      Positions[i].z+=Box;
    }
  }
 
  // add the kinetic part of the pressure
  Pressure+=2.0*UKinetic*NumberOfParticles/(CUBE(Box)*(3.0*NumberOfParticles-3.0));
}
*/


void Integrate(double Step,VECTOR *Momentum)
{ 
  int i;
  double Scale;
  VECTOR NewPositions[MAXPART];
  VECTOR OldForces[MAXPART];

  // set kinetic energy to zero 
  // Euler
  UKinetic=0.0;
  for(i=0;i<NumberOfParticles;i++)
  {
    NewPositions[i].x = Positions[i].x + Velocities[i].x * Deltat + 0.5 * Forces[i].x * SQR(Deltat);
    NewPositions[i].y = Positions[i].y + Velocities[i].y * Deltat + 0.5 * Forces[i].y * SQR(Deltat);
    NewPositions[i].z = Positions[i].z + Velocities[i].z * Deltat + 0.5 * Forces[i].z * SQR(Deltat);

    // record initial positions and forces
    OldPositions[i].x = Positions[i].x;
    OldPositions[i].y = Positions[i].y;
    OldPositions[i].z = Positions[i].z;

    OldForces[i].x = Forces[i].x;
    OldForces[i].y = Forces[i].y;
    OldForces[i].z = Forces[i].z;

    // calculate force of t+dt
    Positions[i].x = NewPositions[i].x;
    Positions[i].y = NewPositions[i].y;
    Positions[i].z = NewPositions[i].z;

    PositionsNONPDB[i].x += NewPositions[i].x - OldPositions[i].x;
    PositionsNONPDB[i].y += NewPositions[i].y - OldPositions[i].y;
    PositionsNONPDB[i].z += NewPositions[i].z - OldPositions[i].z;
  }

  Force();
  for(i=0;i<NumberOfParticles;i++)
  {
    // calculate velocity
    Velocities[i].x += OldForces[i].x * Deltat;
    Velocities[i].y += OldForces[i].y * Deltat;
    Velocities[i].z += OldForces[i].z * Deltat;

    UKinetic += 0.5 * (SQR(Velocities[i].x) + SQR(Velocities[i].y) + SQR(Velocities[i].z));
  }

  // for NumberOfSteps < NumberOfInitializationSteps; use the velocity 
  // scaling to get the exact temperature 
  // otherwise: Scale=1.0 beware that the positions/velocities have to be
  // recalculated !!!!

  if(Step<NumberOfInitializationSteps)
    Scale=sqrt(Temperature*(3.0*NumberOfParticles-3.0)/(2.0*UKinetic));
  else
    Scale=1.0;
 
  UKinetic=0.0;
  (*Momentum).x=0.0;
  (*Momentum).y=0.0;
  (*Momentum).z=0.0;
 
  // scale velocities and put particles back in the box
  // beware: the old positions are also put back in the box 
  for(i=0;i<NumberOfParticles;i++)
  {
    Velocities[i].x*=Scale;
    Velocities[i].y*=Scale;
    Velocities[i].z*=Scale;
 
    (*Momentum).x+=Velocities[i].x;
    (*Momentum).y+=Velocities[i].y;
    (*Momentum).z+=Velocities[i].z;

 
    UKinetic+=0.5*(SQR(Velocities[i].x)+SQR(Velocities[i].y)+SQR(Velocities[i].z));

    // put particles back in the box
    // the previous position has the same transformation
    if(Positions[i].x>=Box)
    {
      Positions[i].x-=Box;
    }
    else if (Positions[i].x<0.0)
    {
      Positions[i].x+=Box;
    }
 
    if(Positions[i].y>=Box)
    {
      Positions[i].y-=Box;
    }
    else if(Positions[i].y<0.0)
    {
      Positions[i].y+=Box;
    }
 
    if(Positions[i].z>=Box)
    {
      Positions[i].z-=Box;
    }
    else if(Positions[i].z<0.0)
    {
      Positions[i].z+=Box;
    }
  }
 
  // add the kinetic part of the pressure
  Pressure+=2.0*UKinetic*NumberOfParticles/(CUBE(Box)*(3.0*NumberOfParticles-3.0));
}

