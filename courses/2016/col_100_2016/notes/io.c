#include <stdio.h>

int main() {

	/* In C : first declare a variable and then use it */
	/* Format --> type variable_name */
	/* scanf, use of the & operator before a variable name */
	/* variables : declaration, definition */
	/* variables follow rules of algebra */
	/* mathematical operators: + - * / % */
	/* operater short cuts : += *= -= /= %= */
	/* int --> integer, float --> floating point, char --> character */
	/* variables : naming, start with [a-z,A-Z,_] after that they can contain
	 	[a-z,A-Z,_,0-9]*/
	/* ASCII Character Set: to find out print a character as an integer */
	/* Conversion (typecast) operator: integer_variable = (int) float_variable , and similar */
	/* i++ --> i = i + 1 return old value of i, ++i --> i=i+1, return new value */
	/* = means assigned to, == is equal to */


	/* PROGRAM STARTS */
	int dividend, divisor, quotient; 
	printf ("Enter divident and divisor: ");
	scanf ("%d %d", &dividend, &divisor);

	if (divisor == 0) { // a curly bracket 
		printf ("Invalid value of divisor. Bye bye !!! \n");
		return;
	} // curly bracket --> end of the if part 

	quotient = dividend / divisor; 

	printf ("Result is : %d",quotient);
	/* PROGRAM ENDS */
}
