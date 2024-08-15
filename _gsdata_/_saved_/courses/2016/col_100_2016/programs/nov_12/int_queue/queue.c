#include "defn2.h"
#include "queue.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

queue create_queue(){
	queue q = (queue) malloc (sizeof(struct queue_struct));
	q->head = NULL;
	q->tail = NULL;
	return q;
}

Node create_node(){
	Node n = (Node) malloc (sizeof (struct node_struct));
	n->next = NULL;
	n->prev = NULL;
	return n;
}
void enqueue (queue q, DTYPE v) {
	Node n = create_node();
	n->val = v;

	if (! is_empty(q)){
		q->tail->next = n;
		n->prev = q->tail;
		q->tail = n;
	} else {
		q->tail = n;
		q->head = n;
	}
}

DTYPE dequeue (queue q) {
	DTYPE val;
	assert (q->head != NULL);
	val = q->head->val;

	q->head = q->head->next;
	if (q->head != NULL) q->head->prev = NULL;

	return val;

}
int is_empty (queue q) {
	return (q->head == NULL);
}

void print_queue (queue q, void (*func)
		(DTYPE v)){
	Node n = q->head;
	while (n != NULL){
		(*func)(n->val);
		n = n->next;
	}
	printf ("\n");
}
