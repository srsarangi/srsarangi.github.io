#include <stdio.h>

void myprintf (char *para){
	int index;
	char c;
	for(index = 0; ;index++ ){
		c = para[index];
		if (c == '\0')
			break;
		printf("%c",c);
	}
	printf ("\n");
}
int main(){
	char para[200];
	int index = 0;
	char c;
	for(index = 0; index< 200; index++){
		c = getchar();
		if (c == '#') {
			para[index] = '\0';
			break;
		}
		para[index] = c;
	}
	myprintf (para);
}

