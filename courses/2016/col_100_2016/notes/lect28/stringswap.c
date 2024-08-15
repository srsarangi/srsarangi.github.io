#include <stdio.h>


void stringswap(char **str1ptr, char **str2ptr){
	char *temp;
	temp = *str1ptr;
	*str1ptr = *str2ptr;
	*str2ptr = temp;
}

int main() {
	char *str1 = "bad";
	char *str2 = "good";

	printf ("%s %s \n", str1, str2);
	stringswap (&str1, &str2);
	printf ("%s %s\n", str1, str2);
}
