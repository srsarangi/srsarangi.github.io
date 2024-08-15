#include <stdio.h>

/*
   * precision: %.2f --> 2 digits after the .
   * different operators
   * trimming: for HackerEarth, no leading or trailing spaces
   */

int main(){
	int num, i=0;
	float sum = 0;
	while (1){
		scanf ("%d",&num);
		if (num == -1) break;
		i++;
		sum += num;
	}

	/* This is what this means: 
	   * 7.2f --> means the last floating point digit is at the
	   * 7th position with respect to the left margin
	   * 2 means that there are 2 digits after the decimal point
	   */

	/* print the average */
	printf("%7.2f\n",	(sum/i));
}
