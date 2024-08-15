#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0 

struct Node_struct{
	char c; /* ( ) [ ] */
	struct Node_struct *next;
};

typedef struct Node_struct Node;

/* takes the stack top as input */
char peek (Node *top) {
	if (top == NULL)
		return -1; /* means that the stack is empty */
	else 
		return top->c;
}

/* pop function */
/* input : stack top
   output: new stack top */
Node* pop (Node *top){
	if (top == NULL)
		return NULL; /* stack is empty */
	else 
		return top->next;
}

/* push function */
/* input : stack top, new character
   output: new stack top */

Node *push (Node *top, char newchar){
	/* allocate a new node first */
	Node *node = (Node *) malloc (sizeof(Node));
	node->c = newchar; 

	/* push */
	node->next = top;
	return node; /* new stack top */
}

int matches(char prevchar, char nextchar){
	if ( (prevchar == '(') && (nextchar == ')'))
		return TRUE;
	if ( (prevchar == '[') && (nextchar == ']'))
		return TRUE;
	return FALSE;
}

int isEmpty(Node *top){
	if (top == NULL)
		return TRUE;
	else 
		return FALSE;
}

int main(){
	char line[30];
	int i,len;
	char c,topchar;

	/* create an empty stack */
	Node *stack = NULL;

	/* read the paranthesis string from standard input */
	scanf ("%s",line);

	/* iterate through every character in line */
	len = strlen(line);
	for(i=0; i < len; i++){
		/* read the character */
		c = line[i];

		if (isspace(c))
			continue;
		else if ( (c == '(') || (c == '['))
			stack = push (stack, c);
		else { 
			/* closing bracket  ) ] */
			topchar = peek(stack);
			if (matches(topchar, c)){
				stack = pop(stack);
			} else {
				printf ("Parantheses not balanced \n");
				return;
			}
		}
	}

	/* reached the end */
	if (isEmpty(stack))
		printf ("Parantheses are balanced \n");
	else
		printf ("Parantheses not balanced \n");
}












