#include <stdio.h>

/* 
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15

   */
int main(){
	int i, last, rowsize = 1, cnt=0;
	printf(" Enter the last number: ");
	scanf ("%d",&last);

	for(i=1; i<= last ; i++){
		printf ("%d ", i);
		cnt++;
		if(cnt == rowsize) {
			printf ("\n");
			rowsize++;
			cnt = 0;
		}
	}

	printf ("\n");
}
