#include<stdio.h>
#include<stdlib.h>
/*
int powe(int n){
	if(n==0)
		return 1;
	return 10 * powe(n - 1);
}
void print(int start,int max){
	if (start >= max)
		return;
	printf("%d\n", start);
	print(start + 1, max);
}


int main()
{
	print(0,powe(4));
	return 0;
}

*/

void print_backTrack(int *a, int size, int curr){
	if (curr<0 || curr>=size)
		return;
	if (a[curr] > 9)
		return print_backTrack(a, size, curr - 1);
	//print code
	a[curr]++;
	print_backTrack(a, size, curr + 1);
}
/*
int main(){
	int *arr = (int*)malloc(sizeof(int)*(2));
	print_backTrack(arr, 2, 1);
}

*/