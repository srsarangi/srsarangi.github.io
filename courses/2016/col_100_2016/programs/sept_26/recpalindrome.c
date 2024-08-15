#include <stdio.h>
#include <string.h>

/* return 0 when not a palindrome
   and 1 when the word is a palindrome */
int check_palin(char line[], int start, int end){
	/* termination condition */
	if (start >= end) return 1;

	/* recursion */
	if (line[start] != line[end]) return 0;
	else return check_palin(line,start + 1, end - 1); /* smaller problem */
}

int main(){
	char line[20];
	int len;
	scanf("%s",line);
	len = strlen(line);
	printf ("Is the line a palindrome? %d \n",check_palin(line,0,len-1));
}
