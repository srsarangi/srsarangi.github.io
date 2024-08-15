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

void inssort (int values[], int size) {
	int idx, jdx, newval, isInserted; 
	for ( idx = 1; idx < size ; idx++ ){
		// in every iteration we are assuming that values[0 .. (idx-1)] is sorted
		newval = values[idx];
		isInserted = 0;

		for (jdx = idx -1 ; jdx >=0; jdx --){
			if (values [jdx] > newval) {
				values [jdx + 1] = values [jdx];
			} else {
				values[jdx + 1] = newval;
				isInserted = 1;
				break;
			}
		}
		if (isInserted == 0) values[0] = newval;
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
	inssort(values, N);

	// print the sorted array
	printf ("\n");
//	print_array (values, N);
}


