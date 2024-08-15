#include <stdio.h>

struct complexnum{
	float real;
	float imag;
};

typedef struct complexnum cnum;

void add (cnum *a, cnum *b, cnum *c){
	c->real = a->real + b->real;
	c->imag = a->imag + b->imag;
}

void printcomplexnum(cnum c){
	printf ("%g + i%g \n",c.real,c.imag);
}
int main(){
	cnum a;  
	cnum b;
	cnum c;

	scanf("%f %f",&a.real, &a.imag);
	scanf("%f %f",&b.real, &b.imag);
	
	add(&a,&b, &c);
	printcomplexnum(c);
}
