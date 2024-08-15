#include <stdio.h>
#include <stdlib.h>

/* find the length of a string */
int mystrlen(char str[]){
	int i = 0;
	while (str[i] != '\0') i++;
	return i;
}

int is_palindrome (char str[]){
	int start = 0;
	int end = mystrlen(str) - 1;

	while (end > start) {
		if(str[start] != str[end]) 
			return 0; /* not a palindrome */
		end-- ;
		start++; 
	}
	return 1;
}

int main(){
	/* in place initialization */
	/* In every string, the last character is \0 (ASCII Code = 0) */

	char str[20]; 
	printf ("Enter string \n");
	scanf ("%s",str);

	printf ("Is the string a palindrome? %d", is_palindrome(str));
}
