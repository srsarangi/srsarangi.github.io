#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* 
   %d --> decimal integer
   %f --> floating point (32 bits)
   %lf --> double (64 bits)
   %x --> hexadecimal integer
   %o --> octal integer 
   %g --> cleaner output for float and double
   %c --> character*/

/* Some other special characters
   \n --> new line
   \t --> tab
   */

/* if (expression) {
     	...
		...
	} else {
		...
		...
	}
	*/

/* convert from type A to type B
   value = (int) value_in_other_type;
   */

/* HUGE SOURCES OF ERRORS
   1) while comparing floats, take the difference, then absolute value,
   see if the absolute value < threshold (ALWAYS do this) 
   2) for comparing two integers
   the operators are:  < > <= >= != (not equal) == (equal) */

int main() {
	/* Don't look above this line */
	float f;
	int value;
	float trunc_val;
	float diff;
	int match = 0;
	printf ("Enter a number: ");
	scanf ("%f", &f); /* always put an & in scanf */

	/* find if the number is of the form x + 0.5 */
	/* then do something */
	trunc_val = (int) f;
	diff = f - trunc_val;
	diff = fabsf(diff);  /* absolute value of the difference */
	if ( fabsf (diff - 0.5) < 1e-10) 
		match = 1;

	/* If a number is of the form: x+0.5 (match = 1) else (match = 0) */

	/* otherwise do this */
	if (f < 0) {
		value = (int) (f - 0.5); 
		if (match == 1) { /* SEE THE == */
			if ( abs(value) % 2 == 1) 
				value = value + 1;
		}
	} else {
		value = (int) (f + 0.5);
		if (match == 1) { /* SEE THE == */
			if ( value % 2 == 1) 
				value = value - 1;
		}
	}

	printf ("\n The rounded value is %d \n",value);

	/* Don't look below this line */
}
