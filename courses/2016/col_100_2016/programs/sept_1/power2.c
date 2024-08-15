#include <stdio.h>
#include <stdlib.h>

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

int main() {
	/* Don't look above this line */
	int num;
	int base;
	int prod = 1, exp = 0;
	scanf ("%d %d",&num, &base);
	printf ("The number is %d and the base is %d \n",num, base);

	/* find out which powers of 2 it lies between */
	while (1){
		if ( (num >= prod) && (num < (base * prod) )){
			printf ("The powers of %d are %d and %d \n",base, exp, exp + 1);
			exit(1);
		}
		prod *= base; 
		exp++;
	}

	/* Don't look below this line */
}








