set title "Lennard-Jones Potential" font ",14"
set xlabel "r/sigma" font ",10"
set ylabel "V/epsilon" font ",10"
set grid
set key inside

plot 'data.dat' lt rgb "red" lw 2 title "V(r)"

pause -1 "Hit return to continue"
