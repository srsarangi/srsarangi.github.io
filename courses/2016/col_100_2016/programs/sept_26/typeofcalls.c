#include <stdio.h>

/* 
   pass by value --> For non-array variables, the values are copied
              when we call a function. Thus, there is no way for a 
			  callee function to modify the values of the variables of 
			  the caller
	pass by reference --> This is for array variables. If the callee modifies
				some element in the array. The caller will be able to see it. 
*/

void func (int val, int line[4]){
	val = -1;
	line[0] = -1;
}

int main(){
	int line[4] = {1,2,3,4};
	func (line[1],line);

	printf ("%d %d\n",line[1],line[0]);
}
