#include <stdio.h>
#include <stdlib.h>

#define N 500000
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
		printf ("%d %d \n", left, right);
		if (left < right) swap (&values[left], &values[right]);
		print_array(values, 0, 7);
	}
	/* return */
	/* right is pointing to the end of the first partition */
	return right;
}

/*
   partition 1: 4, 3, 2, 1
   partition 2: 6, 8, 10, 12
   return value: 3
   */

int main() {
	int values[] = {4, 6, 5, 1, 6, 2, 9, 0};
	int i, minIndex;

	// initialize the array
//	for (i=0; i < N; i++)
//		values[i] = rand() % MAXVAL;

	print_array(values, 0,  7);
	int pivotIndex = partition(values, 0, 7);
	print_array(values, 0, pivotIndex );
	print_array(values,pivotIndex + 1, 7 );
}
