#include <stdio.h>
#define SIZE 7

void swap (int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void array_reverse(int values[], int start, int end){
	/* termination condition */
	if (start >= end)
		return;

	/* action */
	swap (&values[start], &values[end]);

	/* recursion condition */
	array_reverse(values, start + 1, end - 1);
}

int main(){
	int values[] = {1, 2, 3, 4, 5, 6, 7};
	int i;
	
	/* reverse the array */
	array_reverse(values, 0, SIZE - 1);

	/* print */
	for(i=0; i < SIZE;i++)
		printf ("%d ", values[i]);
	printf ("\n");
}

