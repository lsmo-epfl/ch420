set terminal qt

set title "Trigonometric Functions" font ",14"
set xlabel "Angle (Degrees)" font ",10"
set ylabel "F(x)" font ",10"
set grid
set xrange [0:360]
set yrange [-1:1]
set key inside left bottom

plot 'exercise_2.dat' u 1:2 title "sin(x)", 'exercise_2.dat' u 1:3 w l title "cos(x)"

pause -1 "Hit return to continue"