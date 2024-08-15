#include <stdio.h>

/* arrays can be of many types
   character array --> string
   int array, float array, double array 

examples: 
	int array[10];
	float float_array[10];
	double double_array[10];
	char string[10];
*/

int main(){
	int ia[5] = {5,2,3,4,1};
	int i, max_elem, min_elem;

	/* find the maximum */
	max_elem = ia[0];
	for (i=0; i < 5; i++){
		if (ia[i] > max_elem)
			max_elem = ia[i];
	}

	printf ("The largest element is %d \n",max_elem);

	/* find the minimum */
	min_elem = ia[0];
	for (i=0; i < 5; i++){
		if (ia[i] < min_elem)
			min_elem = ia[i];
	}

	printf ("The smallest element is %d \n",min_elem);
}








