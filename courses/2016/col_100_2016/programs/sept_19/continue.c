#include <stdio.h>

int main(){
	int i,j;
	printf ("i j \n");
	for (i=0; i < 3; i++){
		for (j=0; j < 3; j++){
			if (j == 1) 
				continue;
			printf ("%d %d \n",i,j);
		}
	}
}
