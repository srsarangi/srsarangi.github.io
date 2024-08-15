#include <stdio.h>

int main(){
	int choice;
	scanf("%d",&choice);
	/* 0 --> English 1--> Spanish, 2 --> Hindi, 3 --> Russian 
	   anything else --> Go away */

	switch (choice){
		case 0:
			printf ("English \n");
			break;
		case 1:
			printf ("Spanish \n");
			break;
		case 2:
			printf ("Hindi \n");
			break;
		case 3:
			printf("Russian \n");
			break;
		default:
			printf ("Go away \n");
	}
}
