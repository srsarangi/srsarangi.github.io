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

/* We always need the & character in front of a variable
   in scanf */

int main() {
	/* Don't look above this line */

	/* declaration section */
	int num1, num2;
	float f = 3.5;
	double d = 4.8234;

	printf ("Please enter a number: ");
	scanf ("%o", &num1);

	/* using the variables */
	printf (" Values in hex = %d \n", num1);

	/* Don't look below this line */
}
