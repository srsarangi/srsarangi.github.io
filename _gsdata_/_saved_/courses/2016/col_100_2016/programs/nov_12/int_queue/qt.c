#include <stdio.h>

#include "defn2.h"
#include "queue.h"

void func (int x){
	printf ("%d ",x);
}

int main(){
	queue q = create_queue();
	enqueue (q, 3);
	enqueue (q, 4);
	enqueue (q, 5);
	print_queue (q, func);

	dequeue (q);
	print_queue (q, func);

	enqueue (q, -1);
	dequeue(q);
	print_queue (q, func);
}
