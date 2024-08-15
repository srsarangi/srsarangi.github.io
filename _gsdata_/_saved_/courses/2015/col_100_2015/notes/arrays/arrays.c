#include <stdio.h>


void print_array (float values[]){
	int i;
	/* Print the values */
	for (i=0; i < 10; i++)
		printf ("values[%d] --> %g \n",i,  values[i]);
}

int main() {
	int i;

	/* An array is an ordered sequence of primitive data (int, float)*/
	/* type_name array_name [array_size] */
	/* Start counting from 0 */

	float values[15];

	/* In C we count from 0 */
	for (i=0; i < 10; i++)
		values[i] = i * i;

	/* print array */
	print_array(values);

}
