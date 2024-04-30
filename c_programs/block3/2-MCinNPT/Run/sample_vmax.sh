#! /bin/bash -f
#
# NPART    = NUMBER OF PARTICLES
# NSTEP    = NUMBER OF TIMESTEPS
# NINIT    = NUMBER OF INITIALIZATION STEPS
# DISPMAX = MAXIMUM DISPLACEMENT
# VOLMAX  = MAXIMUM VOLUME CHANGE
# BETA     = INVERSE TEMPERATURE
# PRESSURE = PRESURE


NSTEP=2000
NINIT=200
NPART=100
DISPMAX=1 
VOLMAX="0.0001 0.0005 0.001 0.005 0.01 0.05 0.1 0.5 1 5 10 50" 
BETA=10
PRESSURE=1
for i in ${VOLMAX}
do
cat > input <<EOF
$NSTEP $NINIT $NPART $DISPMAX $i $BETA $PRESSURE
EOF
echo "I am at ${i}"
time ../Source/mc_npt >> output_${i}.txt
FRACTION="$(grep "Fraction Succes (Volume)" output_${i}.txt |grep -Eo  "[0-9]+\.[0-9]+")" echo "${i}   ${FRACTION}" >> output_summary.txt
rm input
done