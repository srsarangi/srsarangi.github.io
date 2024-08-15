#include <stdio.h>

/* 
   * %s --> string (sequence of characters)
   * array[i] --> The ith element of the array (counting starts from 0)
   * Two ways of printing a character
   		* 1st way: Use %c -> prints the character
		* 2nd way: Use %d,%x,%o --> prints the ASCII code of the character
*/

void main(){
	char name[10]; /* an array (sequence) of 10 characters */
	int i;

	for(i=0; i<10; i++)
		name[i] = '-';

	scanf ("%s",name);
	printf ("The name is %s \n",name);

	for (i=0; i < 10; i++)
		printf ("name[%d] = 0x%x,%c\n",i,name[i],name[i]);
}
