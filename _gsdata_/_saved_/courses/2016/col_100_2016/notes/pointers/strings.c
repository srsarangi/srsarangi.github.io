#include <stdio.h>
#include <stdlib.h>

/* 
   consider a string: ab
   storage in memory: 'a', 'b', '\0'
   strlen(ab) returns 2
   */

void joinstr (char *str1, char *str2) {
	int len1 = strlen (str1);
	int len2 = strlen (str2); 

	/* act of joining */
	int i;
	for	(i=0; i <= len2; i++)
		str1[len1 + i] = str2[i];
}

int main() {
	char str1[20];
	char str2[10];
	char *newstr;

	printf ("Enter string 1: ");
	scanf ("%s", str1);
	printf ("Enter string 2: ");
	scanf("%s", str2);

	/* concatenate two strings */
//	joinstr (str1, str2);
//	strcat (str1, str2);
//	printf ("concatenated string is %s \n", str1);

	/* compare two strings */
//	printf ("%d \n", strcmp(str1, str2));

	/* copy the string */
//	strcpy (str1, str2);

	/* strdup -- duplicate a string */
	newstr = strdup(str1);
	printf ("%s %s \n", str1, newstr);

}
