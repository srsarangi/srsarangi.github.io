#include <stdio.h>
#include <math.h>

#define NUMROWS 40
#define NUMCOLS 40
#define SMA 25.0
#define THRESHOLD 0.8

int main(){
	int matrix[NUMROWS][NUMCOLS]; 
	int row,col;
	float crow1,ccol1,crow2,ccol2,dist,dist1, dist2, diff;

	/* pre-compute for the circle */
	crow1 = ( (float) NUMROWS)/2.0;
	ccol1 = ( (float) NUMCOLS) * 0.33;
	crow2 = ( (float) NUMROWS)/2.0;
	ccol2 = ( (float) NUMCOLS) * 0.66;

	/* create the matrix */
	for (row=0; row < NUMROWS; row++) {
		for (col=0; col < NUMCOLS; col++) {

			/* this code is for the bounding box */
			if ( row == 0 || col == 0 || row == (NUMROWS - 1)
					|| col == (NUMCOLS -1))
				matrix[row][col] = 1;
			else 
				matrix[row][col] = 0;

			/* find the distance from both the centers to this point */
			dist1 = sqrtf((row-crow1) * (row-crow1) + (col-ccol1) * (col-ccol1));
			dist2 = sqrtf((row-crow2) * (row-crow2) + (col-ccol2) * (col-ccol2));
			dist = dist1 + dist2;

			diff = fabsf (dist - SMA);
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
