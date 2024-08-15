#include <stdio.h>

int factorial (int n){
	if(n <= 1)
		return 1; // termination condition
	return ( n * factorial(n-1)   ); // recursion step

}


int main(){
	int n;
	scanf("%d",&n);
	printf ("Factorial is %d \n",factorial(n));
}
