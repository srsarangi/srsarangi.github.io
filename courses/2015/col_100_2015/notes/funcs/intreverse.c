#include <stdio.h>

int stick(int ls_digit, int num){
	/* 1 , 2345 --> 12345 */
	int copy = num;
	while(num != 0){
		num = num / 10;
		ls_digit = ls_digit * 10;
	}
	return (ls_digit + copy);
}

int intreverse (int num){ /* 12345 */
	int ls_digit = num % 10; /* 5 */
	int remaining_num = num / 10; /* 1234 */

	/* termination condition */
	if(remaining_num == 0)
		return ls_digit;

	/* recursion condition */
	return stick(ls_digit, intreverse(remaining_num)); /* stick 5, intreverse(1234) = 54321 */
}

int main(){
	int num;
	printf ("Enter an integer \n");
	scanf ("%d",&num);

	printf ("%d \n", intreverse(num));
}
