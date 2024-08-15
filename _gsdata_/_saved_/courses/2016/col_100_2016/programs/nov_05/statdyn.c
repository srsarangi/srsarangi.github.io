#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 
   Allocate bytes on the heap (global memory)
   void* malloc (int)
   */
char * stret(int choice){
	/* dynamic allocation */
	char *line = (char *) malloc (10 * sizeof(char)); 

	if (choice == 0)
		strcpy (line, "good");
	else
		strcpy (line, "bad");
	return line;
}

int main(){
	char *line1 = stret(0);
	char *line2 = stret(1);

	printf ("%s %s \n",line1, line2);

	/* free */
	free (line1);
	free (line2);
}
