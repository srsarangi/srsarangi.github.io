#include <stdio.h>

enum Month {JAN=1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};

int main() {
	enum Month month;
	month = 11;
	printf ("%d %d %d \n", JAN, SEP, month);
}
