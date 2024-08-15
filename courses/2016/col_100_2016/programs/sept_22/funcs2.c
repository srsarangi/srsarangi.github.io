#include <stdio.h>

/* in the add function, x, y, and z are LOCAL variables
   they are not visible or usable outside the add function
   The SCOPE is defined to the add function */
int add (int x, int y){
	int z = x + y ;
	return z;
}

/* There are two ways to declare variables inside a function
   	(1) Define it in the argument list
	(2) Define it within the body of the function (between { and })
	In both cases the variables are local to the function and cannot be
	used/modified/seen/accessed outside the function */

int main(){
	int x = 3;
	int y = 4;
	int z = add (x,y) + 5;
	printf ("The value of z is %d \n",z);
}
