#include <stdio.h>
#include <stdlib.h>

/* Execute this command as a superuser
 echo 0 > /proc/sys/kernel/randomize_va_space
 Compile as: gcc stack_break.c -fno-stack-protector
 */

void secret (){
	printf ("Hi, you are hacked \n");
	exit(1);
}
void foo(){
	int buffer[5];
	int j; char *ptr;
	for (j=0; j < 5; j++) buffer[j] = 14;
	printf ("The current return address is: %x \n",buffer[10]);
	buffer[10]= (int) (&secret);
}

int main(){
	int sum = 1;
	foo();
	sum = sum + 3;
	printf ("The value of sum is %d \n", sum);
}
