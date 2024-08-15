#include <stdio.h>

typedef union {
	int num;
	float flt;
} entrynum;

typedef struct{
	int num;
	float flt;
} es;

int main(){
	entrynum eunion;
	es estruct;

	printf ("%p %p\n", &eunion.num, &eunion.flt);
	printf ("%p %p\n", &estruct.num, &estruct.flt);

}
