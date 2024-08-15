#include <stdio.h>

/* preprocessor directive
   gcc -E <file name> */

#define NUMROWS 10
#define NUMCOLUMNS 10

/* global variable */
int glob_var = -1;

/* In C all arrays are passed by reference */
void initialize_array(int mat[NUMROWS][NUMCOLUMNS], int rows, int cols){
	/* passed by reference */
	int i, j;
	for (i=0; i < rows; i++)
		for (j=0; j < cols; j++)
			mat[i][j] = glob_var;
}

void initialize_variable (int y){
	/* passed by value */
	y = 5;
}

int main() {
	int values[NUMROWS][NUMCOLUMNS]; 
	int i,j;
	int x = 0;

	/* array */
	initialize_array(values, NUMROWS, NUMCOLUMNS);

	for (i=0; i < NUMROWS; i++) {
		for (j=0; j < NUMCOLUMNS; j++) {
			printf ("%d ", values[i][j]);
		}
		printf ("\n");
	}
	/* variable */
	initialize_variable (x);
	printf ("%d \n", x);

}
