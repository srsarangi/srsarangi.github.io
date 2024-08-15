#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defn.h"
#include "queue.h"

#define N 3

/******************************************************/
/* return 1 if it found a path, 0 if it did not find a path*/

int traverse (queue q, int visited[N][N], int maze[N][N], coord parents[N][N]){
	/* two arrays */
	int xdisps[] = {-1, 0, 1};
	int ydisps[] = {-1, 0, 1};
	int i, j;
	coord newcd;

	/* get the topmost co-ordinate */
	if (is_empty (q))
		return 0;
	coord top = dequeue (q);

	/* check if this is the destination */
	if (top.x == (N-1) && top.y == (N-1))
		return 1;

	for (i=0; i < 3; i++) {
		for (j=0; j < 3; j++){
			/* get the co-ordinates of the neighbor */
			newcd.x = top.x + xdisps[i];
			newcd.y = top.y + ydisps[j];

			/* check if this is a valid co-ordinate */
			if ( (newcd.x < 0) || (newcd.x >= N))
				continue;
			if ( (newcd.y < 0) || (newcd.y >= N))
				continue;

			/* check if it is a wall */
			if (maze[newcd.x][newcd.y] == 1)
				continue;

			/* check if it is already visited */
			if (visited[newcd.x][newcd.y] == 1)
				continue;

			/* co-ordinate is valid, not a wall, and not visited */
			visited[newcd.x][newcd.y] = 1;
			enqueue (q, newcd);
			parents[newcd.x][newcd.y] = top;
		}
	}

	if (traverse(q,visited, maze, parents))
		return 1;
	else
		return 0; /* did not find a path */
}
void print_maze (int maze[N][N]){
	int i,j;
	for (i=0; i < N; i++) {
		for (j=0; j < N; j++) {
			printf ("%d ",maze[i][j]);
		}
		printf ("\n");
	}
}

void print_path (coord parents[N][N], char *output_file){

	/* open the file */
	FILE *f = fopen (output_file, "w");

	/* do the processing */
	coord start = parents[N-1][N-1];
	fprintf (f,"%d,%d ", (N-1), (N-1));
	while (1){
		fprintf (f,"%d,%d ", start.x, start.y);
		if ( (start.x == 0) && (start.y == 0))
			break;
		start = parents[start.x][start.y];
	} 
	fprintf (f,"\n");
	fclose (f);
}
void print_parents (coord parents[N][N]){
	int i,j; coord c;
	for (i=0; i < N; i++){
		for (j=0; j < N; j++){
			c = parents[i][j];
			printf ("%d,%d ", c.x, c.y);
		}
		printf ("\n");
	}
}
void print_coord(coord c){
	printf ("%d,%d ",c.x,c.y); 
}

void read_maze(int maze[N][N], char *fname ){
	int i=0,j, num;
	/* open the file */
	FILE *f = fopen(fname, "r");
	char line[100]; char *token;

	while (fgets (line, 100, f) != NULL){
		token = strtok (line, " ");
		j = 0; /* 0th column */

		while (token != NULL){
			num = atoi (token);
			maze[i][j++] = num;
			token = strtok (NULL, " ");
		}

		i++; /* go to the next row */
	}

	/* close the file */
	fclose (f);
}
int main(int argc, char *argv[]){
	
	/* create the queue */
	queue q= create_queue();
	coord origin; int status;

	if (argc < 3){
		printf ("Usage: ./a.out <input_file with maze> <output_file> \n");
		exit(1);
	}
	/* create the maze */
	int maze[N][N]; 
	read_maze(maze, argv[1]);

	/* visited array to say that none of the cells have been visited */
	int visited[N][N]; coord parents[N][N];
	int i,j;
	for(i=0; i < N; i++)
		for(j=0; j < N; j++)
			visited[i][j] = 0;


	/* Insert the origin into the stack */
	origin.x = 0; origin.y = 0;
	enqueue(q, origin);
	visited[0][0] = 1;

	/* traverse the maze */
	status = traverse (q, visited, maze, parents);
	print_maze(maze);
	if (status == 1){
		printf ("A path was found: ");
		print_path(parents, argv[2]);
		printf ("Successfully wrote the path to %s \n", argv[2]);
	} else if (status == 0){
		printf ("No path was found\n");
	}
}
