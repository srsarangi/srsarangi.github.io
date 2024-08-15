#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "defn.h"
#include "llstack.h"

/* struct node_struct {
	DTYPE val;
	struct node_struct *next;
};

typedef struct node_struct* Node;

struct stack_struct {
	Node top;
}; */

stack create_stack() {
	stack s = (stack) malloc (sizeof( struct stack_struct));
	s->top = NULL;
	return s;
}

int is_empty(stack s){
	return (s->top == NULL);
}

void push_stack(stack s, DTYPE c){
	/* create a node */
	Node n = (Node) malloc (sizeof (struct node_struct));
	n->next = NULL;
	n->val = c;

	/* push it on the stack */
	if (is_empty(s)){
		s->top = n;
		return;
	}
	n->next = s->top;
	s->top = n;
}

DTYPE top_stack (stack s){
	assert (s->top != NULL);
	return s->top->val;
}

DTYPE pop_stack (stack s){
	assert (s->top != NULL);
	DTYPE val = s->top->val;
	s->top = s->top->next;
	return val;
}



void print_stack(stack s, void (*func) (DTYPE)){
	Node n = s->top;
	DTYPE val;
	while (n != NULL){
		val = n->val;
		(*func) (val);

		/* VERY IMPORTANT: for traversing a linked list */
		n = n->next;
	}
}
