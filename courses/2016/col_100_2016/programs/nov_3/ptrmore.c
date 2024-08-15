#include <stdio.h>

int main(){
	int vals[2];
	char *x;
	int *v, *v2, *v3;
	vals[0] = 0x00ABCDEF;
	vals[1] = 0x12345678;
	
	x = (char *) &vals[0];
	v = (int *) (x + 1);
	v2 = (int *) (x+2);
	v3 = (int *) (x+3);

	printf ("%x \n", *x); /*0x EF */
	printf ("%x \n", *v); /*0x 7800ABCD */
	printf ("%x \n", *v2); /*0x 567800AB */
	printf ("%x \n", *v3); /*0x 34567800 */
}

