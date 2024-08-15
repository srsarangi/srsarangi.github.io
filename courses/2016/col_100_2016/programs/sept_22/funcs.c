#include <stdio.h>

/* 
	<return type> function_name (list of arguments) {
		...
	}

   */
/* Order of execution
   Call the add function
   Assign 3 to x
   Assign 4 to y
   Call printf x
   Call printf y
   add x + y
   return (x+y)
   Execute the printf in the main function */

int add (int x, int y){
	printf ("x is %d\n",x);
	printf ("y is %d\n",y);
	return (x+y);
}
int sub (int x, int y){
	printf ("x is %d\n",x);
	printf ("y is %d\n",y);
	return (x - y);
}
int main(){
	int func_ret_value = add(3,4) + sub (4,3);
	printf ("%d\n", func_ret_value);
}
