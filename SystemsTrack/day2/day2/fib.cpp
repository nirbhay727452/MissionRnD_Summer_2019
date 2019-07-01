#include<stdio.h>
#include<stdlib.h>

int fibo(int n, int* a){
	if (a[n] != -1)
		return a[n];
	else
		a[n] = fibo(n - 1, a) + fibo(n - 2, a);
	return a[n];
}

/*
int main(){
	int n = 7;
	int *arr = (int*)malloc(sizeof(int)*(n+1));
	for (int i = 0; i <= n; i++)
		arr[i] = -1;
	arr[1] = 0;
	arr[2] = 1;
	printf("fibo number %d", fibo(n,arr));
	return 0;
	}
	*/