#include <stdio.h>

/* What is a string? A string is a sequence of characters.
   How is it represented in C.
   Starting quote " ... sequence of characters " ending quote
   */

/* 
   %d --> decimal integer
   %f --> floating point (32 bits)
   %lf --> double (64 bits)
   %x --> hexadecimal integer
   %o --> octal integer 
   %g --> cleaner output for float and double*/

/* Some other special characters
   \n --> new line
   \t --> tab
   */

int main() {
	/* Don't look above this line */

	/* declaration section */
	int a = 1734343, b = 4;
	float f = 3.5;
	double d = 4.8234;

	/* using the variables */
	printf (" Value in hex = %x \n", a);
	printf (" Value in hex = %x", b);

	/* Don't look below this line */
}
