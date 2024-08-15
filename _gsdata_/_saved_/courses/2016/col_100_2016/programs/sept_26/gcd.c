#include <stdio.h>
#include <stdlib.h>

/* Short cut
   max = (a > b)? a: b;
SAME AS:
   if (a > b) max = a;
   else max = b;
   */
int hcf(int a, int b){
	int max, min;
	max = (a >= b)? a : b;
	min = (a < b) ? a : b;

	/* termination condition */
	if (min == 0) return max;

	/* recursive condition */
	return hcf (min, max%min);
}

int hcf_nodiv(int a, int b){
	int arem = a % 2; 
	int brem = b % 2;
	int diff, min;

	/* termination condition */
	if (a==0) return b;
	else if (b == 0) return a;

	/* recursive condition */
	/* if both a and b are even */
	if ( (arem == 0) && (brem == 0))
		return (2 * hcf_nodiv(a/2,b/2));

	/* if a is even and b is odd */
	if ( (arem == 0) && (brem == 1))
		return (hcf_nodiv (a/2,b));

	/* if a is odd and b is even */
	if ( (arem == 1) && (brem == 0))
		return (hcf_nodiv (a,b/2));

	/* if a is odd and b is odd */
	min = (a < b)? a : b;
	diff = abs(a-b)/2;
	return hcf_nodiv (min,diff);
}


int main(){
	int a,b, i;
	scanf ("%d %d",&a, &b); 
	int sum = 0;
	printf ("%d \n",hcf(a,b));
}
