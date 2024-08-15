#include <stdio.h>

/* void --> nothing is being returned */

/* Ideally the function that is being called should come first.
   If that is not the case, just write the signature of the function */
void print_something(float f, char c, char line[10]); 

int main(){
	char line[10];
	scanf("%s",line);
	print_something(3.0, line[0], line);
}

void print_something(float f, char c, char line[10] ){
	printf ("Values are %g, %c, %s\n",f,c,line);
}
