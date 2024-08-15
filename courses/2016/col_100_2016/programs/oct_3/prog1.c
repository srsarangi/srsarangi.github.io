#include <stdio.h>

int main(){
	int x = 5;
	int *p = &x;
	double y = 3.0;
	double *py = &y;

	printf ("Variable is %d and its address is %p \n",*p,p);

	/* pointer arithmetic */
	printf ("p + 1 = %p \n", (p+1));

	/* double example */
	printf ("py = %p, py + 1= %p \n",py, (py+1));
}
