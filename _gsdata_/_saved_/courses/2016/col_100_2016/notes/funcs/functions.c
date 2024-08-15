#include <stdio.h>

/* Every C/C++ program definitely needs a main function */
/* Variables have a life (scope) only inside the function that they are declared
   Outside the function they do not exist
   We call a function as follows: func(list of arguments)
   Every argument is matched with a variable in a function 
   void --> nothing
   */

void print () {
	printf("Life is good");
	return;
}

void main(){
	double a,b;
	scanf("%lf %lf", &a, &b);
	print();
}

