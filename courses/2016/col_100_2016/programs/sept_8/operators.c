#include <stdio.h>

/*
  * i++ means the following:
  * Let's say you have a statement of the following : x = i++
  * The compiler translates this to as follows: x = i; i = i + 1;
  * 
  * Consider: x = ++i
  * The compiler will translate to: i = i + 1; x = i;
  * i = i++ + (++i + --i); DON'T DO THIS OR SIMILAR STUFF
  * Some other operators
  * +=, -=, *=, /=, %=
  * x += y -> x = x + y
  * x %= y -> x = x % y
*/
void main(){
	int i = 0;

	printf ("Case i++ \n");
	printf ("%d \n",i++);
	printf ("%d \n",i);

	i = 0;
	printf ("Case ++i \n");
	printf ("%d \n",++i);
	printf ("%d \n",i);


}
