#include <stdio.h>

int main (){
	int values[] = {1,2,3,4,5,6,7,8};
	int i;

	*(values + 3) = 17;

	for (i=0; i < 8; i++)
		printf ("%d \n", *(values + i));
}
