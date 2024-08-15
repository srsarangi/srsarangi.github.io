#include <stdio.h>
#include <stdlib.h>
#include "defn.h"
#include "stack.h"

#define N 3

/******************************************************/
/* return 1 if it found a path, 0 if it did not find a path*/

int traverse (stack st, int visited[N][N], int maze[N][N]){
	/* two arrays */
	int xdisps[] = {-1, 0, 1};
	int ydisps[] = {-1, 0, 1};
	int i, j;
	coord newcd;

	/* get the topmost co-ordinate */
	coord top = top_stack (st);

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
			push_stack (st, newcd);
			if (traverse (st, visited, maze) == 1)
				return 1;
			pop_stack(st); /* removing newcd from the stack */
		}
	}
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

void print_coord(coord c){
	printf ("%d,%d ",c.x,c.y); 
}

int main(){
	/* create the stack */
	stack st = create_stack();
	coord origin; int status;

	/* create the maze */
	int maze[N][N]  = { {0, 0, 1},
		                {0, 1, 0},
						{1, 1, 0}};

	/* visited array to say that none of the cells have been visited */
	int visited[N][N];
	int i,j;
	for(i=0; i < N; i++)
		for(j=0; j < N; j++)
			visited[i][j] = 0;


	/* Insert the origin into the stack */
	origin.x = 0; origin.y = 0;
	push_stack(st, origin);
	visited[0][0] = 1;

	/* traverse the maze */
	status = traverse (st, visited, maze);
	print_maze(maze);
	if (status == 1){
		printf ("A path was found: ");
		print_stack(st,&print_coord);
	} else if (status == 0){
		printf ("No path was found\n");
	}
}
