#include <stdio.h>


int main() {
	
	/* for loop: very very versatile loop */
	/* for (initialize; looping condition; increment condition) { ... } */

	/* 
	Fib(0) = 1;
	Fib(1) = 1;
	Fib(2) = Fib(0) + Fib(1) = 2;
	Fib(3) = (Fib(1) + Fib(2)) = 3;

	Fib (n) = Fib(n-1) + Fib(n-2);
	*/

	int num, last = 1, secondLast = 0, result = 1,i;

	printf ("Enter the number: ");
	scanf("%d", &num);

	if (num < 0){
		printf  ("Invalid Number. Bye bye !!!");
		return;
	}

	for (i=1; i<= num; i++) {
		result = last + secondLast;
		printf ("Fib(%d) = %d \n",i, result);
		secondLast = last;
		last = result;
	}


}






