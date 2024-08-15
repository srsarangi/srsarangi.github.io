#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int num;
	int wt;
	int code;
}bogey;

bogey* alloc_bogey_stack(){
	bogey b = {0, 0, 17};
	return &b;
}

bogey* alloc_bogey_heap(){
	bogey *b = (bogey *) malloc (sizeof(bogey));
	b->code = 17;
	return b;
}

void pollute_stack(){
	bogey b = {3, 4, 5};
}

void main(){
	bogey* ptr = alloc_bogey_stack();
	pollute_stack();
	printf ("%d \n",ptr->code); // returns 5: ERROR

	ptr = alloc_bogey_heap();
	pollute_stack();
	printf ("%d \n",ptr->code); // returns 17: CORRECT


}
	
