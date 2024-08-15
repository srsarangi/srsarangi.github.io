#include <stdio.h>
#include <stdlib.h>

#define SIZE 50000

void print_array(int values[], int size){
	int i;
	/* print the array */
	for (i=0; i < size; i++)
		printf ("%d ",values[i]);
	printf ("\n");
}

void selsort(int values[]){
	int i,min,index, temp, ptr;
	for (ptr = 0; ptr < SIZE - 1; ptr++) {
		/* Ensure that all the element in the array
		   from 0 till ptr are in their right places */

		/* find the smallest number in the range: ptr to SIZE-1*/
		min = values[ptr];
		index = ptr;
		for (i=ptr; i < SIZE; i++){
			if (values[i] < min) {
				min = values[i];
				index = i;
			}
		}

		/* swap the first place with the slot 
		   where the min element was found */
		temp = values[index];
		values[index] = values[ptr];
		values[ptr] = temp;
	}
}

void main(){
	int arr[SIZE]; 
	int i;
	/* initialize */
	for (i=0; i < SIZE; i++)
		arr[i] = rand(); 

	/* sort and print */
	selsort(arr);
}
