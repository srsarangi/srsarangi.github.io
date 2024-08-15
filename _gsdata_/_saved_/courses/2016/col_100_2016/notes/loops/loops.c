#include <stdio.h>


int main(){
	int i;

	/* for loop */
	for(i=0; i<10; i++){
		printf ("%d \n",i);
	}

	/* while loop */
	i = 0;
	while (i <10){
		printf ("%d \n",i);
		i++;
	}

	/* do-while loop */
	i = 0;
	do {

		i++;
		printf ("%d \n",i);
	} while (i < 10); 

}


