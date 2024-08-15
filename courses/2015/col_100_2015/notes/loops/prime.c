#include <stdio.h>
#include <math.h>

int main() {
	int totalPrimes, i, j, isPrime, primesFound=0,remainder;
	printf ("Enter the number of primes: ");
	scanf("%d", &totalPrimes);


	for(i= 2; primesFound < totalPrimes ; i++){

		/* tests i for primality */
		isPrime = 1;
		for(j=2; j<i; j++){ 
			remainder = i%j;
			if(remainder == 0) {
				isPrime = 0;
				break;
			}
		}

		/* looks at isPrime*/
		if(isPrime == 1){
			printf ("%d \n",i);
			primesFound++;
		}
	}
}
