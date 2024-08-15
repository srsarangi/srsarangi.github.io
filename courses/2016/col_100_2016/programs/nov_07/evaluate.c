#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "defn.h"
#include "stack.h"

/* create two global stacks */
stack numstack, opstack;

int compute_priority(char op){
	switch (op){
		case '+':
		case '-':
			return 0;
		case '*':
		case '/':
			return 1;
		case '$':
			return -5;
		default:
			printf ("You should never have come here, %c \n", op);
			exit (1);
	}
}

int perform_operation (int x, int y, char op){
	switch (op){
		case '+':
			return (x+y);
		case '-':
			return (x-y);
		case '*':
			return (x * y);
		case '/':
			return (x / y);
		default:
			printf ("Sir, you have a bug, %c \n", op);
			exit (1);
	}
}
void print_operator (opnum t){
	printf ("%c ", t.op);
}
void print_operand (opnum t){
	printf ("%d ", t.num);
}


void print_stacks(){
	printf ("************ Contents of the stacks *********\n");
	printf ("Numbers: ");
	print_stack(numstack, &print_operand);
	printf ("Operators: ");
	print_stack(opstack, &print_operator);
}

/* process the operator */
void process_operator (char op){
	opnum t, top1, top2, resnum; char top_op;
	int result; int u1, u2;

	/* if the operator stack is empty, you push the operator */
	if (is_empty (opstack)) {
		t.op = op;
		push_stack (opstack, t);
		return;
	}

	/* take a look at the top of the operator stack */
	top_op = (top_stack (opstack)).op;
	
	while (compute_priority (op) <= compute_priority (top_op) ){
		/* evaluate the top two elements of the stack */
		top2 = pop_stack(numstack);
		top1 = pop_stack(numstack);
		pop_stack(opstack);

		result = perform_operation (top1.num, top2.num, top_op);

		/* push the result back on the num stack */
		resnum.num = result;
		push_stack (numstack, resnum);

		/* compute the operator for the opstack top */
		if (is_empty(opstack)) {
			break;
		}
		top_op = (top_stack (opstack)).op;

	}

	/* insert the operator in the operator stack */
	t.op = op;
	push_stack (opstack, t);
}

/* line contains the expression, evaluate it, return the result */
int process (char* line){
	char *token;
	opnum topnum;
	char op;
	int mode = 0; /* mode = 0 (operand), mode = 1 (operator) */

	/* tokenize the string */
	token = strtok(line, " ");
	do  {
		/* 1 iteration for each token */
		if (mode == 0) {
			mode = 1; /* expect an operator next time */

			/* push the number into the numstack*/
			topnum.num = atoi(token); 
			push_stack (numstack, topnum);

		} else if (mode == 1){
			mode = 0; /* next time expect an operand */
			op = token[0];
			
			process_operator(op);
		}

	} while( (token = strtok (NULL, " ")) != NULL); 

	/* some entires might still be left in the num and opstacks */
	process_operator ('$');

	/* return the top of the numstack */
	return  (top_stack(numstack).num);
}


int main(){
	int result;
	/* input expression */
	/* ALWAYS HAVE A SPACE BETWEEN NUMBERS AND OPERATORS */
	char line[] = "10 + 2 / 2 + 2 * 3 + 8 / 2";
	printf ("The expression is: %s\n",line);

	/* create the stacks */
	numstack = create_stack();
	opstack = create_stack();

	/* process the line */
	result = process(line);
	printf ("The result is %d \n", result);
}

