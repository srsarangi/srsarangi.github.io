#include <stdio.h>

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

int main() {
	/* Don't look above this line */
	float f;
	float value;
	printf ("Enter a number: ");
	scanf ("%f", &f); /* always put an & in scanf */

	if (f < 0) {
		value = (int) (f - 0.5); 
	} else {
		value = (int) (f + 0.5);
	}

	printf ("\n The rounded value is %f \n",value);

	/* Don't look below this line */
}
