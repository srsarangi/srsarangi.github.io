#include <stdio.h>

int fib(n){
	if (n <= 1) return 1;
	else return (fib(n-1) + fib(n-2));
}

int main(){
	int num;
	scanf ("%d",&num);
	printf ("Fib(%d) = %d\n",num,fib(num));
}
