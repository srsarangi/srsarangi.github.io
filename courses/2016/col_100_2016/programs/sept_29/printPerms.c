#include <stdio.h>

#define N 3

/* EXAMPLE:
1 2 3 4 5 --> start = 2

1 2 3 4 5 --> print_perms(arr,3)
1 2 4 3 5 --> print_perms(arr,3);
1 2 5 4 3 --> print_perms(arr,3); 
*/

void print_array(int arr[]){
	int i;
	for (i=0; i < N; i++)
		printf("%d ",arr[i]);
	printf ("\n");
}

/* print all possible permutations 
   start --> starting index
   to the left of it (lower indices) everything is constant
   only do the permutations to the right of it */
void print_perms (int arr[], int start){
	int copy[N]; int i,j,temp;
	/* termination condition*/
	if (start == N-1) {
		print_array(arr);
		return;
	}
	/* at the start position, keep putting an element from its right
	   permute the rest of the digits */
	for (i=start; i < N; i++) {
		/* create a copy of the array */
		for (j=0; j < N; j++) copy[j] = arr[j]; 

		/* need to swap elements: @start and @i */
		/* SWAP copy[start] and copy[i] */
		temp = copy[start];
		copy[start] = copy[i];
		copy[i] = temp;

		/* call a smaller version of the function */
		print_perms (copy, start + 1);
	}
}

int main(){
	int arr[N]; 
	int i;
	for (i=0; i < N; i++)
		arr[i] = i+1;
	
	print_perms(arr,0);
}
