#include <stdio.h>
#include <string.h>

/* Arrays and pointers are equivalent
   int[] <--> int*
   */
int main(){
	char *str = "hello"; /* str is a pointer as well as an array */
	printf ("%c \n", str[1]); /* str[1] <--> * (str + 1) */

	/* Interpretation: str is a pointer to a character
	   printf starts at the address in str
	   It prints the character at str, which is *str
	   Then it moves to location str + 1
	   Again prints the character there
	   ...
	   untill it encounters the \0 character. Then it stops */
	printf ("%s \n",str);
}
