set terminal postscript eps color
set size 0.75, 0.75
set xrange[0:1000]
set xlabel "Time (ps)"
set ylabel "Current (A)"
set output "pulse.eps"
plot f(x) = 0.5/114 * (exp(-1 * x / 164) - exp(-1 * x / 50)), f(x) t "current pulse" lw 5
