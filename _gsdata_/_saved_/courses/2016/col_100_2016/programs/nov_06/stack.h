struct stack_struct {
	int top;
	DTYPE elements[100];
};

typedef struct stack_struct* stack;

extern DTYPE top_stack (stack s); 
extern DTYPE pop_stack (stack s); 
extern void push_stack(stack s, DTYPE c);
extern int is_empty(stack s);
extern stack create_stack(); 
extern void print_stack(stack s, void (*func) (DTYPE));
