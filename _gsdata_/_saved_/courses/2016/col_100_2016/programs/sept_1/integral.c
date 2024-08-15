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

/* for loop
   for (<initialization> ; <loop condition> ; <action on each 
   												iteration>) {
	   ....
	   ....
	   ....
  } */

/* i++ means (i = i + 1) */

#define PI 3.14159265

int main() {
	/* Don't look above this line */
	float limit1 = 0, limit2 = 10;
	float delta = PI/100;
	float angle, at;
	float integral = 0;


	for (angle = limit1; angle <= limit2; angle += delta){
	
		/* for each of these points: find the integral */
		integral = 0;
		for (at=0; at <= angle; at+= delta){
			integral += delta * ( expf(cosf(at) + sqrt(at)) ); 
		}

		printf ("%f %f \n", angle, integral);
	}

	/* Don't look below this line */
}








