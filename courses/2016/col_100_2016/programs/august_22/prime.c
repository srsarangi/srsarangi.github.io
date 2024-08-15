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
	int divisor;
	int remainder;
	int isPrime = 1; /* standard trick: start with an assumption, break
					  	it later if needed */

	/* input */
	printf("Enter a number (>=2) : \n");
	scanf("%d",&num);

	/* logic of the program */
	for (divisor = 2; divisor < num; divisor++) {
		remainder = num % divisor; /* divide */
		if (remainder == 0) {
			/* number is not prime */
			isPrime = 0;

			/* exit the for loop */
			break;
		}
	}

	/* print 1 if number is prime, else print 0 */
	printf ("Is the number prime? Ans: %d \n", isPrime);


	/* Don't look below this line */
}








