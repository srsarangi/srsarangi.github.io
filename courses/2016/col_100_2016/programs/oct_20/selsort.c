#include <stdio.h>

void swap_byte (void *ptr1, void *ptr2) {
	char *cptr1 = (char *)ptr1;
	char *cptr2 = (char *) ptr2;
	char byte;

	byte = *cptr1;
	*cptr1 = *cptr2;
	*cptr2 = byte;
}

void selsort(void *values, int datasize, int SIZE, int (*compare) (void *, void*)){
	int i,index, ptr, j;
	char byte;
	void *min, *ptr1, *ptr2;

	for (ptr = 0; ptr < SIZE - 1; ptr++) {
		min = values + datasize * ptr; /* find values[ptr] */
		index = ptr;
		for (i=ptr; i < SIZE; i++){
				/* values[i] <=> *min */
			if ( (*compare) (values + i *datasize,min) < 0) { 
				min = 	values + i * datasize;
				index = i;
			}
		}
		/* Address of the first byte of values[i] is 
		   values + i * datasize */

		/* swap values[index] and values[ptr] */
		for (j=0; j < datasize; j++){
			 ptr1 = values + index * datasize + j;
			 ptr2 = values + ptr * datasize + j;
			 /* swap the bytes pointed to by ptr1 and ptr2 */
			 swap_byte(ptr1, ptr2);
		}
	}
}
