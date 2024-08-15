#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "defn.h"
#include "stack.h"

stack create_stack() {
	stack s = (stack) malloc (sizeof(struct stack_struct));
	s->top = -1;
	return s;
}

int is_empty(stack s){
	return (s->top == -1);
}

void push_stack(stack s, DTYPE c){
	assert (s->top < 100);
	s->top ++;
	s->elements[s->top] = c;
}

DTYPE pop_stack (stack s){
	assert (s->top >= 0); 
	DTYPE c = s->elements[s->top];
	s->top --;
	return c;
}

DTYPE top_stack (stack s){
	assert (s-> top >= 0);
	return s->elements[s->top];
}

void print_stack(stack s, void (*func) (DTYPE)){
	int i;
	DTYPE c;
	for (i=0; i <= s->top; i++) {
		c = s->elements[i];
		(*func) (c);
	}
	printf ("\n");
}
