#include <stdio.h>

#define CONST 0xFFFFFFFF
#define CONST2 0x40000
#define CONST3 234

int method1(int x) {
	int i = 1;
	int j = 0;
	for(j=0; j < 18; j++)
		i = i * 2;
	return (( (x&i) == 0) ? 0 : 1 );
}

int method2(int x){
	return ( ( (x & 0x40000) == 0) ?  0 : 1);

}
int main(){
	printf ("%d \n", method1(CONST));
	printf ("%d \n", method2(CONST));
}

