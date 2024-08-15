#include <stdio.h>
#include <stdlib.h>

#define N 50000
#define MAXVAL 50

/* variable = (condition) ? var1 : var2 ;
   if condition is true : variable = var1
   else variable = var2
   */

void print_array (int values[], int size){
	int i;
	for (i=0; i < size; i++)
		printf ("%d ", values[i]);
	printf ("\n");
}

int findMinIndex (int values[], int start, int end) {
	int i;
	int min = start;

	for(i= start; i <= end; i++){
		min =  (values[i] < values[min]) ? i : min;
	}

	return min;
}
void swap (int *ptr1, int *ptr2){
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}

void selsort (int values[], int size) {
	int idx, minIdx;
	for (idx = 0; idx <= size - 2; idx++){
		minIdx = findMinIndex(values, idx, size - 1);
		swap (&values[idx], &values[minIdx]); 
	}
}

int main() {
	int values[N];

	srand (10);
	// initialize the array
	int i, minIndex;
	for (i=0; i < N; i++)
		values[i] = rand() % MAXVAL;

	// print the array
//	print_array (values, N);

	// sort the array 
	selsort(values, N);

	// print the sorted array
	printf ("\n");
//	print_array (values, N);
}


