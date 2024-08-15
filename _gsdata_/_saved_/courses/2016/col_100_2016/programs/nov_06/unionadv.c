#include <stdio.h>
#include <string.h>

typedef union {
	int num;
	char str[100];
} entrynum;

int main(){
	entrynum en;
	en.num = 0xABCDEF12;

	printf ("%x\n",en.str[2]);

	strcpy (en.str, "hello");
	printf ("%x\n",en.num);

	printf ("%x%x%x%x\n",'l','l','e','h');
}
