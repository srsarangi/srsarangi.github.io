#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "selsort.h"

int compare_int (void *va1, void *va2){
	int *x = (int *) va1;
	int *y = (int *) va2;

	if (*x < *y) return -1;
	if (*x == *y) return 0;
	else return 1;
}
int compare_str (void *va1, void *va2){
	char **x = (char **) va1;
	char **y = (char **) va2;
	
	return (strcmp(*x,*y));
}


void print_string_array(char *strarray[], int size){
	int i;
	for (i=0; i < size; i++)
		printf ("%s \n",strarray[i]);
}

/* extern
void selsort(void *values, int datasize, 
				int SIZE, int (*compare) (void *, void*)); */
void strexample(){
	/* first create an array of strings */
	char * strarray[5];
	int i;
	strarray[0] = "good";
	strarray[1] = "bad";
	strarray[2] = "great";
	strarray[3] = "badness";
	strarray[4] = "goodness";

	/* sort strings */
	selsort(strarray,sizeof(char *), 5, &compare_str);

	/* after sorting */
	print_string_array(strarray, 5); 
}

void intexample(){
	int iarray[] = {4,3,0,2};
	int i;
	selsort(iarray, sizeof (int) ,4, &compare_int);

	printf ("The array is: \n");
	for(i=0; i <4; i++)
		printf ("%d\n",iarray[i]); 
}

int main(){
	printf ("The results are \n");
	strexample();
	intexample();
}
