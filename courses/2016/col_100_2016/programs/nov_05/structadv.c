#include <stdio.h>
#include <stdlib.h>

/* type for a pair of integers */

typedef struct {
	int x;
	int y;
	float area;
} coord;

/* 
   Given a variable c of type coord
   coord* cp = &c --> x is a pointer to c
   To access any member variable of coord, we use the
expression: cp->x 

Rule: use the '.' operator, for a structure variable
	  use the '->' operator for a pointer to a structure */

void print_coord(coord* c){
	coord newc = *c;
	printf ("%d %d %g \n",newc.x, c->y, (*c).area);
}

int main(){
	coord* c1 = (coord *) malloc (sizeof(coord));
	c1->x = 3;
	c1->y = 4;
	c1->area = c1->x * c1->y;

	print_coord(c1);
	free(c1);
}
