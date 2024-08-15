#include <stdio.h>


int main(){
	int x = 1215;
	int y = 624; 

	/* xold and yold refer to the original values of x and y */
	/* identities: x^x = 0, x^0 = x */

	x = x ^ y; // x = xold ^ yold
	y = x ^ y; // y = xold ^ yold ^ yold
	x =	x ^ y; // x = xold ^ yold ^ xold	 

	printf ("%d %d\n",x,y);

	x = x + y;
	y = x - y;
	x = x - y;
	
	printf ("%d %d\n",x,y);
}
