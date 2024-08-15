#include <stdio.h>


int raise (int m, int n)
{
	if ( n==1) return m;
	else {
		if (n%2 == 0) return raise( m, n/2)*raise(m, n/2);
		else return m*raise( m, n/2)*raise(m, n/2);
	}
}

/* This function (raise 2) is clearly more efficient. Requires only log(n) steps */
int raise2 (int m, int n)
{
	int b;
	if ( n==1) return m;
	else {
		b = raise2(m, n/2);
		if ( (n & 1) == 0) return b*b;  // (n & 1) is the right thing to do
										// TAs do not penalize students for this
		else return m* b*b;
	}
}

int main(){
	printf ("%d \n", raise(2,3));
	printf ("%d \n", raise2(2,3));

	printf ("%d \n", raise(2,4));
	printf ("%d \n", raise2(2,4));

	printf ("%d \n", raise(3, 5));
	printf ("%d \n", raise2(3,5));

	printf ("%d \n", raise(1, 6));
	printf ("%d \n", raise2(1, 6));

	printf ("%d \n", raise(4, 6));
	printf ("%d \n", raise2(4, 6));
}
