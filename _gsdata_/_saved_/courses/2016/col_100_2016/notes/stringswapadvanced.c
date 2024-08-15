#include <stdio.h>
#include <string.h>
void stringswap(char **str1ptr, char **str2ptr){
	char *temp;
	temp = *str1ptr;
	*str1ptr = *str2ptr;
	*str2ptr = temp;
}

void useStringSwap(){
	char *one, *three;
	char bytes[] = {'o','n','e','\0','t','h','r','e','e','\0'};
	one = &bytes[0];
	three = &bytes[4];
	char dest[8];

	printf ("%s %s \n", one, three);

	/* try a string swap */
	stringswap (&one, &three);

	printf ("%s %s \n", one, three);

}
void useStrCpy(){
	char *one, *three;
	char bytes[] = {'o','n','e','\0','t','h','r','e','e','\0'};
	one = &bytes[0];
	three = &bytes[4];
	char dest[8];

	printf ("%s %s \n", one, three);

	/* try a string swap */
	strcpy(dest,three);
	strcpy(three,one);
	strcpy (one, dest);

	printf ("%s %s \n", one, three);
}


int main(){
	useStrCpy();
	useStringSwap();
}
