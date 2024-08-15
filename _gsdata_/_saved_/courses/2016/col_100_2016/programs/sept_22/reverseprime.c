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
int reverse (int num){
	int revnum = 0;
	while(num != 0){
		revnum = revnum*10 +  num % 10;
		num = num / 10;
	}
	return revnum;
}

int main(){
	int num, revnum;
	scanf ("%d",&num);
	
	revnum = reverse(reverse(reverse(num)));
	printf ("The reversed number is %d\n",revnum);
	printf ("Is it Prime? Ans: %d",isPrime(revnum));
}
