#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char ipaddr[] = "199.201.26.324";
	int length = strlen(ipaddr);
	int idx;
	int components[4];
	char *ptr = & ipaddr[0];
	int tempIdx = 0;

	for (idx = 0; idx < length; idx++){
		if (ipaddr[idx] == '.') {
			ipaddr[idx] = '\0';
			components[tempIdx++] = atoi(ptr);
			ptr = ipaddr + idx + 1;
		}
	}
	components[tempIdx++] = atoi(ptr);


	printf ("%d %d %d %d \n", components[0], components[1], components[2], components[3]);
}
