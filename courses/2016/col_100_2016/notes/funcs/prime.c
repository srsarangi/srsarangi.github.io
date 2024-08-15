#include <stdio.h>
#include <math.h>

/* Parts of a function
   <return type> name_of_the_function (list of arguments)  { ... }
   */

int prime (int i){
	/* tests i for primality */
	/* return 1 if i is prime, otherwise return 0 */
	int j, isPrime, remainder;

	isPrime = 1;
	for(j=2; j<i; j++){ 
		remainder = i%j;
		if(remainder == 0) {
			isPrime = 0;
			break;
		}
	}

	return isPrime;
}


int main() {
	int totalPrimes, i, primesFound=0;
	printf ("Enter the number of primes: ");
	scanf("%d", &totalPrimes);

	for(i= 2; primesFound < totalPrimes ; i++){
		/* looks at isPrime*/
		if(prime(i) == 1){
			printf ("%d \n",i);
			primesFound++;
		}
	}
}
