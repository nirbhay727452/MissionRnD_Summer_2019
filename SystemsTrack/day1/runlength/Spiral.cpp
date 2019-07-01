#include<stdio.h>
#include<stdlib.h>
//two approaches
// recursive

/*
void print_spiral(int arr[][4], int m, int n){
	int m_start = 0, n_start = 0;
	while (m_start != m && n_start != n){
		for (int i = m_start; i < m; i++){
			printf("%d  ", arr[n_start][i]);
		}
			n_start++;
		for (int i = n_start; i < n; i++){
			printf("%d  ", arr[i][m-1]);
		}
		m--;
		for (int i = m-1; i>=m_start; i--){
			printf("%d  ", arr[n-1][i]);
		}
		n--;
		for (int i = n-1; i >=n_start; i--){
			printf("%d  ", arr[i][m_start]);
		}
		m_start++;
	}


}

int main(){
	//int arr[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	int arr[4][4] = { { 1, 2, 3, 4, 5 }, { 6, 7, 8, 9, 10 }, { 11, 12, 13, 14, 15 } };
	int m = 4, n = 4;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++){
			printf("%d     ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n\n\n\n");
	print_spiral(arr, 4,4);
	return 0;
}
*/