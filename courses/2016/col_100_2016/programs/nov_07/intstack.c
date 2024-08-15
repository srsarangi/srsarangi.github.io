#include <stdio.h>
#include "defn2.h"
#include "stack.h"

void print_int(int x){
	printf ("%d ", x);
}

int main(){
	stack st = create_stack();
	push_stack (st, 3);
	push_stack (st, 4);

	print_stack(st, &print_int);

	pop_stack (st);
	print_stack(st, &print_int);

}
