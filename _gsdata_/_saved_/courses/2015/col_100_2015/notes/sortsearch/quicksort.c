#include <stdio.h>
#include <stdlib.h>

#define N 20
#define MAXVAL 50

/* variable = (condition) ? var1 : var2 ;
   if condition is true : variable = var1
   else variable = var2
   */

void print_array (int values[], int start, int end){
	int i;
	printf("Array: ");
	for (i=start; i <= end; i++)
		printf ("%d ", values[i]);
	printf ("\n");
}
void swap (int *ptr1, int *ptr2){
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}
int partition(int values[], int start, int end){
	int pivot = values[start];
	/* first partition: all numbers <= pivot
	   second partition: all numbers > pivot */
	int left = start;
	int right = end;

	/* iteration */
	while (left < right) {
		while (left <= end) {
			if (values[left] > pivot) break;
			left++;
		}
		while (right >= start) {
			if(values[right] <= pivot) break;
			right--;
		}
		if (left < right) swap (&values[left], &values[right]);
	}
	/* swap with right */
	swap (&values[start], &values[right]);

	/* return */
	/* right is pointing to the end of the first partition */
	return right;
}

/*
   partition 1: 4, 3, 2, 1
   partition 2: 6, 8, 10, 12
   return value: 3
   */

void quicksort (int values[], int start, int end){
	int partition_point;
	if (start >= end) return; 

	partition_point = partition (values, start, end);
	quicksort (values, start, partition_point - 1 );
	quicksort (values, partition_point + 1, end);
}

int main() {
	int values[N]; 	int i, minIndex;

	// initialize the array
	for (i=0; i < N; i++)
		values[i] = rand() % MAXVAL;

	quicksort (values, 0, N - 1);
	print_array(values, 0, N-1);
}
