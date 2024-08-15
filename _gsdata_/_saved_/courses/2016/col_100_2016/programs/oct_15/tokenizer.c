#include <stdio.h>
#include <string.h>

/* Problem: 
2011CS510228;Mahesh Kumar;1 */

int main(){
	char line[] = "2011CS510228;Mahesh Kumar;1";
	char entry[20], name[30];
	char *tok;
	int group;

	printf ("%s\n",line);
	/* breaks (or tokenizes) a string at the delimiting character (;) */
	/* get the entry number */
	tok = strtok(line, ";");
	strcpy(entry, tok);

	/* Name */
	/* for the subsequent fields after the first, give NULL as the first
	   argument */
	tok = strtok(NULL, ";");
	strcpy(name,tok);

	/* Group */
	tok = strtok (NULL, ";");
	group = atoi (tok); /* convert from string to integer */

	printf ("Entry num = %s, Name = %s, Group = %d\n",entry,name,group);


}

