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

void merge (int values[], int start, int mid, int end){
	/* start -- mid is sorted
	   mid+1 -- end is sorted
	   now you merge them */
	int newarr[N]; 
	int newIdx; 
	int idx1 = start, idx2 = mid + 1;

	for(newIdx = 0; newIdx < (end - start + 1); newIdx++){
		if (idx1 > mid) {
			newarr[newIdx] = values[idx2];
			idx2++;
			continue;
		}
		if (idx2 > end) {
			newarr[newIdx] = values[idx1];
			idx1++;
			continue;
		}
		if (values[idx1] < values[idx2]){
			newarr[newIdx] = values[idx1];
			idx1++;
		} else {
			newarr[newIdx] = values[idx2];
			idx2++;
		}
	}
	
	for (newIdx = start; newIdx <= end; newIdx++)
		values[newIdx] = newarr[newIdx - start];

}

void mergesort (int values[], int start, int end){
	int mid = (start + end)/2;

	/* termination */
	if (start == end) 
		return;

	/* recursion */
	mergesort (values, start, mid);
	mergesort (values, mid+1, end);
	merge (values, start, mid, end);
}

int main() {
	int values[N]; 
	int i, minIndex;
	srand (10);

	// initialize the array
	for (i=0; i < N; i++)
		values[i] = rand() % MAXVAL;

//	print_array(values, N);
	mergesort (values, 0, N-1);
//	print_array(values, N);
}


