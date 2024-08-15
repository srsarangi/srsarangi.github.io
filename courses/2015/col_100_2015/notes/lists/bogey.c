#include <stdio.h>
#include <stdlib.h>

struct bogey_struct{
	int num;
	int weight;
	int code;

	/* add a pointer to the next bogey */
	struct bogey_struct *next;

	/* to make this a doubly linked list */
	struct bogey_struct *prev;
};

typedef struct bogey_struct bogey;

void print_train(bogey *engine){
	bogey *temp = engine;
	while (temp != NULL) {
		printf ("%d ",temp->num);
		temp = temp->next;
	}
	printf ("\n");

}

void destroy_train(bogey *engine){
	bogey *temp = engine;
	bogey *ttemp;
	while (temp != NULL) {
		ttemp = temp;
		temp = temp->next;
		free(ttemp);
	}

}
/* stack --> It is an area of memory that saves local variables of functions. When you
   return from a function, all the local variables are destroyed.

   heap --> It is an area of memory that saves data (variables/structures). Data lives across
   function calls */

/* malloc function takes as input --> number of bytes
   it returns --> pointer to the first byte of the allocated data on the heap */


bogey* make_train(){
	bogey* engine = (bogey *) malloc (sizeof(bogey));
	engine->num = 0;

	bogey* bogey1 = (bogey *) malloc (sizeof(bogey));
	bogey1->num = 1;

	bogey* bogey2 = (bogey *) malloc (sizeof(bogey));
	bogey2->num = 2;

	/* connect the bogies */
	engine->next = bogey1;
	bogey1->next = bogey2;
	bogey2->next = NULL;

	return engine;
}

/* 
	insert an element after bogey with number, num
   */

void insert_new_bogey(bogey *engine, bogey *newBogey, int num){
	bogey *temp = engine;

	while (temp != NULL) {
		if (temp->num == num) {
			newBogey->next = temp->next;
			temp->next = newBogey;
			return;
		}
		temp = temp->next;
	}
}

bogey * insertAtBeginning(bogey* newBogey, bogey *engine){
	newBogey->next = engine;
	return newBogey;
}

/* the deleted bogey will not be the engine, assume: engine exists */
/* avoid expressions of the type: temp->next->num
why: You do not know if temp->next is NULL or not */

void delete_bogey(bogey *engine, int num){
	bogey *temp = engine->next;
	bogey *oldTemp = engine;

	while(temp != NULL) {
		if (temp->num == num){
			/* go ahead with the deletion */
			oldTemp->next = temp->next;
			return;
		}
		oldTemp = temp;
		temp = temp->next;
	}
}

int main(){
	bogey *engine = make_train();
	
	/* insert bogey between 1 and 2 */
	bogey *bt1 = (bogey *) malloc (sizeof(bogey));
	bogey *bt2 = (bogey *) malloc (sizeof(bogey));
	bogey *newEngine = (bogey *) malloc (sizeof(bogey));
	bt1->num = 17;
	insert_new_bogey(engine, bt1, 1);

	/* insert bogey at the end */
	bt2->num = 19;
	insert_new_bogey(engine, bt2, 2);

	/* insert a new engine */
	newEngine->num = -1;
	engine = insertAtBeginning (newEngine, engine);
	
	/* print the train */
	print_train(engine);

	/* delete bogey #17 */
	delete_bogey(engine,17);
	print_train(engine);

	/* delete bogey #19 */
	delete_bogey(engine,19);
	print_train(engine);

}






