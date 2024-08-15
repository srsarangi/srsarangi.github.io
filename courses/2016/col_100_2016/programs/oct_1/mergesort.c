#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50000

/* Selection sort
   To find the minimum of n elements : n-1 comparisons, + 1 swap: n
   For doing selection sort on n-1 elements: n-1
   ...
   For sorting two elements: 2 
   T(n) = T(n-1) + n
   Total work: n + (n-1) + (n-2) + ... + 1 = n(n+1)/2 = (n^2 + n)/2 = O(n^2)
   You want so sort Aadhar card numbers for 10^9 Indians
   We require roughly: 10^18 steps
   Assume a computer does: 10^9 comparisons per second --> Need billion seconds
     You need: 31.7 years
   */

/* Merge sort:
IDEA: Divide an array into two equal halves. Sort each separately.
Then merge the two sorted arrays. 
       T(n) --> Time it takes to sort n elements
	   T(n) = 2 * T(n/2) + n

	   T(n) = n log(n)
	   T(n/2) = n/2 (log(n/2)) = n/2*log(n) - n/2
	   2T(n/2) = nlog(n) - n
	   2T(n/2) + n = n log(n) = T(n) (30 seconds, approx)

	   30 years --> 30 seconds (!!!)
*/
void merge (int arr[], int start, int mid, int end){
	/* two sorted arrays arr[start ... mid]
	   and arr[mid+1 ... end] merge them */
	int tempvals[MAX_SIZE];
	int ptr1, ptr2, ptrnew=0, idx;

	ptr1 = start;
	ptr2 = mid+1;

	/* compare both the sorted arrays element by element
	   move the element that is smaller to the new aray */
	while ( (ptr1 <= mid) && (ptr2 <= end)){
		/* compare elements at ptr1 and ptr2 */
		if (arr[ptr1] < arr[ptr2]){
			tempvals[ptrnew] = arr[ptr1];
			ptr1 ++; ptrnew++;
		} else {
			tempvals[ptrnew] = arr[ptr2];
			ptr2 ++; ptrnew++;
		}
	}
	/* at this point --> one of the pointers has reached the end */
	while (ptr1 <= mid){
		tempvals[ptrnew] = arr[ptr1];
		ptr1 ++; ptrnew++;
	} 
	while (ptr2 <= end){
		tempvals[ptrnew] = arr[ptr2];
		ptr2 ++; ptrnew++;
	}

	/* transfer back to arr */
	for (idx = start, ptrnew = 0; idx <= end; idx++, ptrnew++)
		arr[idx] = tempvals[ptrnew];
}

void merge_sort (int arr[], int start, int end){
	int mid = (start + end)/2;
	/* termination condition */
	if( start >= end) return;

	/* recurse */
	merge_sort(arr,start, mid); /* first half */
	merge_sort (arr, mid+1, end); /* second half */
	merge (arr, start, mid, end); /* do the merging */
}
void print_array (int arr[], int size){
	int i;
	for (i=0; i < size; i++)
		printf ("%d ",arr[i]);
	printf ("\n");
}
int main(){
	int arr[MAX_SIZE]; 
	int i;
	/* initialize */
	for (i=0; i < MAX_SIZE; i++)
		arr[i] = rand(); 

	/* sort and print */
	merge_sort (arr,0, MAX_SIZE - 1);
}
