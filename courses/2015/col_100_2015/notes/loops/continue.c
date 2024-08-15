#include <stdio.h>


int main(){
	int i;
	for(i=0; i<20; i++){
		if( i%4 == 0) // number is even
			continue;
		printf ("%d \n",i);
	}
}
