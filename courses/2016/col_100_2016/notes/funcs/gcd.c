#include <stdio.h>

/* a >= b */
int gcd (int a, int b){
	int remainder; 

	/* termination condition */
	if(b == 1)
		return 1;

	remainder = a % b;
	if (remainder == 0)
		return b;

	/* recursion condition: remainder is non-zero */
	return gcd(b, remainder);
}

/* gcd (a,b)  = gcd (b, a%b) */

int main() {
	int a, b;
	printf ("Enter two numbers a and b. (a >= b) \n");
	scanf("%d %d", &a, &b);
	printf ("GCD is %d \n", gcd(a,b));

}
