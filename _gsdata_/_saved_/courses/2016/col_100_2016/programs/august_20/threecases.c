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

/* || --> OR one of the expressions is true
   && --> AND both the expressions are true
   */

/* if (expr1) {
   } else if (expr2) {
   } else if (expr3) {
   }
   ....

   else {
   } */

int main() {
	/* Don't look above this line */
	int choice;

	printf ("Choose your language: ");
	scanf ("%d", &choice);
	
	/* 1 --> English, 2 --> Hindi, 3 --> Russian */
	if ( (choice <= 0) || (choice > 3)) {
		printf ("Your input is invalid. Go away, don't come back \n");
		exit(1); /* exit the program completely */
	}
	
	if (choice == 1) 
		printf ("You chose English \n");
	else if (choice == 2)
		printf ("You chose Hindi \n");
	else 
		printf ("You chose Russian \n"); /* choice has to be 3 */


	/* Don't look below this line */
}





