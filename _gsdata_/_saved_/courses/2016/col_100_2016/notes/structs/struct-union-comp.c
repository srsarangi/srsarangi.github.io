#include <stdio.h>

struct mystruct {
	int a;
	double b;
	float c;
};

union myunion {
	int a;
	double b;
	float c;
};

int main() {
	struct mystruct M;
	union myunion U;

	printf ("%p %p %p \n", &M.a, &M.b, &M.c);
	printf ("%p %p %p \n", &U.a, &U.b, &U.c);
}
