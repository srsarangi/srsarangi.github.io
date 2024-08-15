#include <stdio.h>
#include <string.h>

#define N 5

void print_string_array(char *strarray[], int size){
	int i;
	for (i=0; i < size; i++)
		printf ("%s \n",strarray[i]);
}

void sort_strings(char *strarray[], int size){
	int i,ptr, index;
	char *min, *temp;
	for (ptr = 0; ptr < size - 1; ptr++) {
		min = strarray[ptr];
		index = ptr;
		for (i=ptr; i < size; i++){
			if (strcmp(strarray[i], min) < 0) {
				min = strarray[i];
				index = i;
			}
		}

		/* swap  */
		temp = strarray[index];
		strarray[index] = strarray[ptr];
		strarray[ptr] = temp;
	}

}

int main(){
	/* first create an array of strings */
	char * strarray[N];
	int i;
	strarray[0] = "good";
	strarray[1] = "bad";
	strarray[2] = "great";
	strarray[3] = "badness";
	strarray[4] = "goodness";

	/* sort strings */
	sort_strings (strarray, N);

	/* after sorting */
	print_string_array(strarray, N);


			

}
