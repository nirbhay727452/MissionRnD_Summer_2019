#include<stdio.h>
#include<stdlib.h>

int sumArray(int a[], int size,int start){
	if (start >= size)
		return 0;
	return a[start] + sumArray(a, size, start + 1);
}/*
int main(){
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int sum = sumArray(arr, 10, 0);
	printf("%d", sum);
	return 0;
}
*/