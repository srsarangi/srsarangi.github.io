#include <stdio.h>
#include <string.h>


int main(){
	char str1[]  = "good";
	char str2[] = "bad";
	char dest[10];
	int i;

	/* string functions */
	/* strlen --> length of the string */
	printf ("%d %d\n",strlen(str1), strlen(str2));

	/* string compare */
	/* in strcmp the sign of the result matters
	   +ve --> str1 > str2
	   0 --> str1 and str2 are the same string
	   -ve --> str1 < str2 */
	printf ("%d\n",strcmp(str1,str2));

	/* copy of a string (content) */
	/* You are copying the contents of str1 into dest */
	strcpy(dest, str1); /* dest should have enough space to store the string */
	printf ("Destination string = %s \n",dest);

	/* join (concatenate) two strings --> strcat */
	strcat (dest, str2); /* dest = join (dest, str2) */
	printf ("Joined string = %s \n",dest);

	/* Experiment 1*/
	strcpy (dest, str2);
	for (i=0; i < 10; i++)
		printf ("%c \n",dest[i]);
	printf ("compare (dest,str2) = %d\n", strcmp(dest, str2));
}
