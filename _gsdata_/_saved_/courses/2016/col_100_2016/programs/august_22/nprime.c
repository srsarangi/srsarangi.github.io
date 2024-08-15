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

/* while loop
   while (<condition>) {
		...
   }
   */

int main() {
	/* Don't look above this line */
	int num,pos,divisor;
	int remainder;
	int isPrime,count; 

	/* input */
	printf("Program to find the nth prime. Enter n: \n");
	scanf("%d",&pos);


	/* logic of the program */
	count = 0; /* initially, we have not found any prime number */
	num = 2;
	/* infinite loop */
	while (1) { /* in each iteration, check if num is prime or not */
		/* assume num is prime */
		isPrime = 1;

		/* test if num is prime of not (has come from prime.c) */
		for (divisor = 2; divisor < num; divisor++) {
			remainder = num % divisor; /* divide */
			if (remainder == 0) {
				/* number is not prime */
				isPrime = 0;

				/* exit the for loop */
				break;
			}
		}

		/* at this point, we know the value of isPrime for a given 
		   value of num */
		if(isPrime == 1)
			count++; /* we found one more prime number */
		if(count == pos) {
			/* we have reached the end of the computation*/
			break;
		} else
			num++;
	}

	/* print the nth prime number */
	printf ("The %dth prime number is: %d \n",pos, num);


	/* Don't look below this line */
}








