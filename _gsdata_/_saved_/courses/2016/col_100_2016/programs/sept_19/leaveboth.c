#include <stdio.h>

int main(){

	int i,j;
	int leaveboth = 0;
	for (i=0; i < 3; i++){
		for (j=0; j < 3; j++){
			if ( (i == 2) && (j == 1)) {
				leaveboth = 1;
				break;
			}
			printf ("%d %d \n",i,j);
		}
		if (leaveboth == 1) break;
	}
	printf ("I am a free man \n");
}
