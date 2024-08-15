#include <stdio.h>

/* 
   A style of programming where a function calls itself is known as recursion
   */

int factorial (int n){
	if (n == 0)
		return 1; /* termination condition */
	return (n * factorial(n-1)); /* recursive step */
}

int main() {
	printf ("%d \n",factorial(6));
}
