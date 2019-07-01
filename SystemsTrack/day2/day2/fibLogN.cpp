#include<stdio.h>
#include<stdlib.h>

int** matrixMultiplication(int**a, int **b){
	int**result = (int**)malloc(sizeof(int*) * 2);
	for (int i = 0; i < 2; i++)
		result[i] = (int*)malloc(sizeof(int) * 2);
	result[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
	result[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];
	result[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0];
	result[1][1] = a[1][0] * a[0][1] + a[1][1] * b[1][1];
	return result;
}
/*
int**exponent(int **array, int exp){
	if (exp = 1)
		return array;
	int**x = exponent( array, exp / 2);
	if (exp==2)
		return matrixMultiplication(x, x);
}
*/