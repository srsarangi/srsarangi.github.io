#include <stdio.h>

/* 
1) Internally: all arrays are pointers
2) line is basically an integer pointer
3) The value of the pointer line is the same as &line[0]
*/

/* The output on my computer is: 
addr(line) = 0x22cae0, addr(line[0]) = 0x22cae0, addr(line[2]) = 0x22cae8
*/

int main(){
	int line[10];
	int *p = &line[0];

	printf ("addr(line) = %p, addr(line[0]) = %p, addr(line[2]) = %p \n",
			line,p,&line[2]);
}

