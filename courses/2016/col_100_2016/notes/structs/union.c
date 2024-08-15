#include <stdio.h>

typedef union {
	char *name;
	int num;
	int coursecode;
} course ;

// _ _ _ _ 

int main() {
	course mycourse;

	mycourse.name = "col100";
	printf("%s \n", mycourse);

	mycourse.num = 100;
	printf ("%d \n",mycourse);

	mycourse.coursecode = 3;
	printf ("%d \n",mycourse);
}
