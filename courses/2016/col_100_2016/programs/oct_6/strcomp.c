#include <stdio.h>
#include <string.h>

/* strcmp function
   strcmp (char *s1, char *s2) 
   if string s1 > string s2 : return value +ve
   if string s1 = string s2 : return value 0
   if string s1 < string s2 : return value -ve
   */

int main(){
	char* line1 = "abc";
	char * line2 = "def";
	int result = strcmp(line2, line1);

	printf ("%s %s -->result = %d\n",line1, line2, result);
}
