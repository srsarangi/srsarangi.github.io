#include <stdio.h>

int x; /* global variable */

void foo(int y){
	printf ("Foo: Location of x is %p and y is %p \n",&x, &y);
}
int main(){
	int y = 10;
	x = 4;
	printf ("Main: Location of x is %p and y is %p \n",&x, &y);
	foo(y);
}
