#include <stdio.h>

/* 
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15

   */
int main(){
	int i, last, rowsize,j;
	printf(" Enter the last number: ");
	scanf ("%d",&last);

	i = 1;
	for(rowsize=1; i<= last ; rowsize++){
		for (j=0; (j < rowsize) && (i<=last); j++){
			printf ("%d ", i);
			i++;
		}
		printf ("\n");
	}
}
