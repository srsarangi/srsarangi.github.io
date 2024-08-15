#include <stdio.h>

/* Says if n is prime or not, if it is prime return 1, else return 0 */
int isPrime (int n){
	int i;
	for (i=2; i < n; i++) {
		if (n%i == 0)
			return 0;
	}
	return 1;
}

int main(){
	int num1, num2,num, count = 0;
	scanf ("%d %d",&num1, &num2);
	
	for (num=num1 ; num <= num2; num++){
		if (isPrime(num) == 1)
			count++;
	}
	printf ("The number of prime numbers between %d and %d is %d",num1,num2,count);
			
}
