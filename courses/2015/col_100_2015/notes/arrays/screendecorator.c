#include <stdio.h>
#include <math.h>

#define ROWS 18
#define COLS 18
#define PI 3.1415

void init(int values[ROWS][COLS]){
	int i,j;
	for(i=0; i < ROWS; i++)
		for (j=0; j < COLS; j++)
			values[i][j] = 0;
}

void border(int values[ROWS][COLS]){
	int i,j;
	for(i=0; i < ROWS; i++) {
		for (j=0; j < COLS; j++) {
			if ( (i == 0) || (j == 0) || (i == ROWS-1) || (j == COLS - 1))
				values[i][j] = 1;
		}
	}
}

void print (int values[ROWS][COLS]){
	int i,j;
	for(i=0; i < ROWS; i++) {
		for (j=0; j < COLS; j++) {
			if (values[i][j] == 1)
				printf ("* ");
			else 
				printf ("  ");
		}
		printf ("\n");
	}
}

void circle(int values[ROWS][COLS], int radius){
	float originx, originy;
	originx = COLS/2;
	originy = ROWS/2;
	float angle, x, y;
	int xcord, ycord;

	for (angle=0; angle <= 10*PI; angle += 0.02){
		y = radius *   sin (angle);
		x = radius *   cos (angle);

		xcord = (int) (originx + x + 0.5);
		ycord = (int) (originy + y + 0.5);
		if ((xcord < 0) || (xcord >= COLS) || (ycord < 0) || (ycord >= ROWS))
			continue;
		values [xcord][ycord] = 1;
	}

}

int main() {
	int values[ROWS][COLS];

	/* initialize it */
	init(values);

	/* create a border */
	border (values);

	/* create a circle */
	circle (values, 5);

	/* create a circle */
	circle (values, 2);

	/* print */
	print(values);

}
