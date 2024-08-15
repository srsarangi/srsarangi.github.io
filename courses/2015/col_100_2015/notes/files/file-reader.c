#include <stdio.h>
#include <string.h>


int getLetterCount (char *buffer){
	int length = strlen(buffer);
	int idx = 0;
	char c;
	int count = 0;
	for(idx = 0; idx < length; idx++){
		c = buffer[idx];
		if ( (c == '.') || (c == '?') || (c == '!'))
			continue;
		count ++;
	}
	return count;
}
int isSentenceDelimiter(char *buffer){
	int length = strlen(buffer);
	int idx = 0;
	char c;
	for(idx = 0; idx < length; idx++){
		c = buffer[idx];
		if ( (c == '.') || (c == '?') || (c == '!'))
			return 1;
	}
	return 0;

}

int main() {
	char buffer[80];

	/* open the file */
	FILE *ptr = fopen ("para.txt", "r");
	int letterCount = 0;
	int wordCount = 0;
	int sentenceCount = 0;
	
	while (fscanf (ptr, "%s",buffer) != EOF) {
		wordCount ++;
		letterCount += getLetterCount(buffer);
		sentenceCount += isSentenceDelimiter(buffer);
	}

	fclose (ptr);

	printf ("Letter count = %d, Word count = %d, Sentence count = %d \n", 
			letterCount, wordCount, sentenceCount);
}
