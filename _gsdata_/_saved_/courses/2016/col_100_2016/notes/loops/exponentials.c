#include <stdio.h>


int main() {
	
	/* for loop: very very versatile loop */
	/* for (initialize; looping condition; increment condition) { ... } */

	int i, x, n, negativeFlag = 0;
	float result = 1;

	printf ("Enter the numbers x and n. Compute x^n : ");
	scanf ("%d %d", &x, &n);

	if( n < 0){
		negativeFlag = 2;
		n = n * -1;
	} 


	/* loop */
	for (i=1; i<=n; i++) {
		result = result * x;
	}

	/* check for negative */
	if (negativeFlag)
		result = 1 /result;

	printf ("The result is %g \n",result);

}






