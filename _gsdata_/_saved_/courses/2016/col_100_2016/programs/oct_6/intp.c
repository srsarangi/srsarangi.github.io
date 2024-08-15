#include <stdio.h>

/* There are multiple uses of the * operation (Bad idea, what to do :( )

   * --> means multiplication a * b, if used in an arithmetic expression

	int *p --> means declare p as a pointer to an integer (this definition
	is only valid in a declaration)

	*p = 4; 
	Assume that p = 100
	In the locations 100-103, put in a 4-byte integer, which in this case is 4

	int x = *p
	Go go the address p (in this case 100). Then read the 4 bytes at 100-103
	and assign them to x.
	*/

int main(){
	/* for this statement, the compiler first allocates 8 bytes of space
	   in memory. Assume the locations are from 100 to 107
	   In this case x will contain 100 */
	int x[] = {5,6};

	int* p = x; /* p will contain 100 */
	*p = 1; /* Go to locations 100-103 and write 1*/
	*(p+1) = 2; /* Go to locations 104-107 and write 2 */

	printf ("Address %d %d %d\n",p, x[0], x[1]);
}
