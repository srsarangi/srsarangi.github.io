#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char str[], int start, int end){
	char c;
	/* termination condition */
	if (start >= end) return;

	/* recursion condition */
	c = str[start];  /* do the swap: str[start] and str[end] */
	str[start] = str[end];
	str[end] = c;

	reverse (str, start + 1, end - 1);
}

int main(){
	char str[] = "This is great";
	int i;
	int len = strlen(str);
	/* reverse and print */
	reverse(str, 0, len - 1);
	for(i=0; i < len ; i++)
		printf ("%c", str[i]);
	printf ("\n");
}
