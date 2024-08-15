#include <stdio.h>
#define N 6

/* binary search --> USE RECURSION */
int binsearch (int arr[], int start, int end, int elem){
	int mid = (start + end) / 2;
	/* termination condition */
	if(arr[mid] == elem)
		return mid;
	if (start >= end) return -1;

	/* recursion condition */
	if (elem > arr[mid]) 
		binsearch(arr, mid + 1, end, elem);
	else
		binsearch(arr, start, mid - 1, elem);
}

int main(){
	int arr[] =  { 1, 4, 7, 10, 13, 16};
	int elem;
	scanf ("%d",&elem);

	/* search within arr */
	int result = binsearch(arr,0, N-1,elem);
	printf ("The number found at location %d\n",result);
}

