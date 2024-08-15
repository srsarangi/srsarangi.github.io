#include <stdio.h>
#include <math.h>

#define THRESHOLD 1e-5

int main(){
	float f = pow(2,30);
	float g = pow (2,3);
	float h = pow (2,30);

	float result = f - (h + g);
	printf ("%g \n",result);

}
