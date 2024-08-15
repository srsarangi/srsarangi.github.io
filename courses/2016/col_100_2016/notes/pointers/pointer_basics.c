#include <stdio.h>


/* & (variable) returns its starting address. Return type is a pointer
   * (pointer variable) returns the value stored at the pointer's location */

/* operation of the form: *(pointer variable) = value
   We are putting the value in the variable that the pointer points to */

int main() {
	int x = 5;
	int *ptr = &x;
	int **ptrptr = &ptr;
	int y = *ptr; 
	int *addry = &y; 

	printf ("x = %d, pointer(x) = %p, y = %d, pointer(y) = %p \n ", x, ptr, y, addry); 

	/* scanf */
	scanf ("%d", ptr);
	printf ("x = %d \n", x);

	/* setting the value at a pointer's location */
	*ptr  = 8;
	printf ("x = %d \n", x);

	/* where is ptr stored ? */
	printf ("ptr is stored at %p, *ptrptr = %p \n", ptrptr, *ptrptr);

}
