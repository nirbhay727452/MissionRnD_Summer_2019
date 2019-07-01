#include<stdio.h>
#include<stdlib.h>

int ** transpose(int ** matrix, int m, int n){
	if (m <= 1 && n <= 1)
		return matrix;
	int **result = (int **)malloc(sizeof(int *)*n);
	for (int i = 0; i < n; i++)
		result[i] = (int*)malloc(sizeof(int)*m);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++){
			result[j][i] = matrix[i][j];
		}
	}
	return result;
}

void print_matrix(int** matrix, int m, int n){
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++){
			printf("%d     ", matrix[i][j]);
		}
		printf("\n");
	}
}

/*
int main(){
	int m = 2, n = 3,num=1;
	int **matrix = (int **)malloc(sizeof(int *)*n);
	for (int i = 0; i < n; i++)
		matrix[i] = (int*)malloc(sizeof(int)*m);

	//generating matrix for input
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			matrix[i][j] = num++;

	print_matrix(matrix, m, n);//printing old matrix
	printf("\n\n\n\n\n");

	int**result = transpose(matrix, m, n);
	print_matrix(result, n, m);//printing result
	free(matrix);
	free(result);
	return 0;
	}
*/