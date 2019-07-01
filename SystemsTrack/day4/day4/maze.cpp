#include<stdio.h>
#include<stdlib.h>
#include "stack.h"
//homework is to find best path
//jump variation also

int  maze1(int input[][3], int start_x, int start_y, int end_x, int end_y, int row, int col)
{
	//in input 1==free and 0==block
	if (input[start_x][start_y] == 0)
		return 0;
	if (start_x < 0 || start_x >= row)
		return 0;
	if (start_y < 0 || start_y >= col)
		return 0;
	
	//covered or blocked states
	if (input[start_x][start_y] == 2)
		return 0;
	
	//blocking dead statess


	//checking final states
	if (start_x == end_x && start_y == end_y)
		return 1;
	
	input[start_x][start_y] = 2;
	
	if (maze1(input, start_x + 1, start_y, end_x, end_y, row, col) == 1)
		return 1;

	if (maze1(input, start_x, start_y + 1, end_x, end_y, row, col) == 1)
		return 1;

	if (maze1(input, start_x-1, start_y, end_x, end_y, row, col) == 1)
		return 1;

	if (maze1(input, start_x, start_y - 1, end_x, end_y, row, col) == 1)
		return 1;
	return 0;
}


/*
int main(){
	int row = 3, col = 3;
	int end_x = 2, end_y = 2;
	int solution[10] = { -1 };
	int input[3][3] = { { 1, 1, 1 }, { 0, 0, 1 }, {0,1,1} };
	if (maze1(input, 0, 0, end_x,end_y,row,col) == 0)
		printf("no solution\n");
	else
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (input[i][j] == 2)
					printf("(%i,%d)\n", i, j);
			}
		}
	return 0;
}

*/