#include <stdio.h>
#include <string.h>

int main(){
	char str[] = "good morning";
	char value [] = "today is a good day: be happy";
	char key[] = "day";

	/* It finds the first location of the character
	   In this case the character is 'm'
	   Returns a pointer to it
	   We store the pointer in p */
	char *p = strchr (str, 'm');
	printf ("%s \n", p);

	/* search for a string within a string */
	p = strstr(value, key);
	printf ("%s \n",p); /* first occurrence */

	/* second occurrence */
	p = strstr (p + strlen(key), key); 
	printf ("%s \n",p); /* second occurrence */
}
