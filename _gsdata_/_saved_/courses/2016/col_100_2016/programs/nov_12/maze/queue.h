struct node_struct {
	struct node_struct *next;
	struct node_struct *prev;
	DTYPE val;
};

typedef struct node_struct *Node;

struct  queue_struct{
	Node head;
	Node tail;
};

typedef struct queue_struct* queue;

extern queue create_queue();
extern void enqueue (queue q, DTYPE v);
extern DTYPE dequeue (queue q);
extern int is_empty (queue q);
