#include <stdio.h>

/* type for a pair of integers */

struct coord {
	int x;
	int y;
	float area;
};

void print_coord(struct coord c){
	printf ("%d %d %g \n",c.x, c.y, c.area);
}

int main(){
	struct coord c1;
	c1.x = 3;
	c1.y = 4;
	c1.area = c1.x * c1.y;

	struct coord c2 = c1;

	print_coord(c2);

}
