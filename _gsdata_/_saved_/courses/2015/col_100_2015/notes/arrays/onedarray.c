#include<stdio.h>
#include<stdlib.h>

int find_min (int values[], int size){
	int i;
	int min = values[0];
	for (i=1; i < size; i++){
		if (values[i] < min)
			min = values[i];
	}
	return min;
}

int find_max (int values[], int size){
	int i;
	int max = values[0];
	for (i=1; i < size; i++){
		if (values[i] > max)
			max = values[i];
	}
	return max;
}

int main() {
	int values[20];
	int i;

	/* assign random values */
	srand(134);
	for(i=0; i < 20; i++)
		values[i] = rand() % 100;
		

	/* print the array */
	for(i=0; i < 20; i++)
		printf ("%d ",values[i]);
	printf ("\n");

	/* find the minimum */
	printf ("Minimum is %d, Maximum is %d \n", find_min(values,20), find_max(values,20));
}
