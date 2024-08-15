#include <stdio.h>

void swap (int *ptrx, int *ptry){
	int temp = *ptrx; 
	*ptrx = *ptry;
	*ptry = temp;
}

void newswap (int x, int y){
	int temp = x;
	x = y;
	y = temp;
}


int main() {
	int x = 5;
	int y = 8;

	printf ("x = %d, y = %d \n", x, y);
	swap (&x,&y);
	printf ("x = %d, y = %d \n", x, y);
}
