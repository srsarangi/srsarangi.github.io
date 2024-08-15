#include <stdio.h>

/* What is a string? A string is a sequence of characters.
   How is it represented in C.
   Starting quote " ... sequence of characters " ending quote
   */

/* 
   %d --> decimal integer
   %f --> floating point (32 bits)
   %lf --> double (64 bits)
   %x --> hexadecimal integer
   %o --> octal integer 
   %g --> cleaner output for float and double
   %c --> character*/

/* Some other special characters
   \n --> new line
   \t --> tab
   */

int main() {
	/* Don't look above this line */
	char c;

	c = 'a';

	printf ("The character is %c \n", c);

	/* Don't look below this line */
}
