#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define E 2.718
#define PI 3.1415

/* 
	FILE * : pointer to a file data structure
fopen : open a file for reading or writing
fopen(<filename>, <mode>)
<mode> : r --> reading, w --> writing, a --> appending
   */

int main() {
	/* file open */
	FILE *ptr = fopen ("data","w");
	
	float radius = 2.0; 
	float originx = 3.0;
	float originy = 4.0;
	float angle;
	float x,y;

	for(angle = 0; angle <= 2 * PI; angle += 0.02){
		x = originx + radius * cos(angle);
		y = originy + radius * sin(angle);
		fprintf (ptr, "%f %f \n", x, y);
	}

	/* file close */
	fclose (ptr);
}



