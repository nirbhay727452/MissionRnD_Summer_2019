#include<stdio.h>
#include<stdlib.h>
int climb_top(int*a, int n, int k){
	if (k<1 || n<1)
		return 0;
	if (a[n] != -1)
		return a[n];
	else{
		for (int i = 1; i <= k; i++)
			a[n] += climb_top(a, n - i, k);
		a[n]+=1;
	}
}
/*
int main(){
	int n = 3;
	int *arr = (int*)malloc(sizeof(int)*(n + 1));
	for (int i = 0; i <= n; i++)
		arr[i] = -1;
	arr[1] = 1;
	arr[2] = 2;
	printf("number of ways %d", climb_top(arr,n,3));
	return 0;
}
*/