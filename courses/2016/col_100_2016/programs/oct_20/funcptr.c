#include <stdio.h>

int inc (int x){
	return x+1;
}
int dec (int x){
	return x - 1;
}

int main(){
	int choice;
	printf ("Enter 1 for incrementing 10, 2 for decrementing 10\n");
	scanf ("%d",&choice);

	/* define a function pointer */
	int (*fptr)(int); /* a pointer to a function that takes an int and returns
						 an int */
	if (choice == 1)	
		fptr = &inc;
	else
		fptr = &dec;

	/* print the result */
	printf ("%d\n", (*fptr)(10));
}
