#include <stdio.h>
#include <math.h>

#define NUMROWS 40
#define NUMCOLS 40
#define RADIUS 15.0
#define THRESHOLD 0.35

int main(){
	int matrix[NUMROWS][NUMCOLS]; 
	int row,col;
	float crow,ccol,dist,diff;

	/* pre-compute for the circle */
	crow = ( (float) NUMROWS)/2.0;
	ccol = ( (float) NUMCOLS)/2.0;

	/* create the matrix */
	for (row=0; row < NUMROWS; row++) {
		for (col=0; col < NUMCOLS; col++) {

			/* this code is for the bounding box */
			if ( row == 0 || col == 0 || row == (NUMROWS - 1)
					|| col == (NUMCOLS -1))
				matrix[row][col] = 1;
			else 
				matrix[row][col] = 0;

			/* find the distance from the center for this point */
			dist = sqrtf((row-crow) * (row-crow) + (col-ccol) * (col-ccol));
			diff = fabsf (dist - RADIUS);
			if (diff < THRESHOLD)
				matrix[row][col] = 1;
		}
	}

	/* print the matrix */
	for (row=0; row < NUMROWS; row++) {
		for (col=0; col < NUMCOLS; col++) {
			if (matrix[row][col] == 0)
				printf ("  ");
			else
				printf ("* ");
		}
		printf ("\n");
	}
			
}
