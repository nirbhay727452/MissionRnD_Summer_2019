#include<stdio.h>
#include<stdlib.h>
#include "mergeSort.h"

char* numToString(int num){
	char* number = (char*)malloc(sizeof(char) * 10);
	int index = 4;
	number[0] = 't';
	number[1] = 'e';
	number[2] = 'm';
	number[3] = 'p';
	while (num > 0){
		number[index++] = num % 10 + '0';
		num /= 10;
	}
	number[index++] = '.';
	number[index++] = 't';
	number[index++] = 'x';
	number[index++] = 't';
	number[index] = '\0';
	return number;
}

FILE *  openFile(char **fname,int i,char* mode){
	*fname = numToString(i);
	FILE *fp = fopen(*fname, mode);
	return fp;
}


void fillBuffer(int * array, int index, int size, FILE *fp)
{
	if (fp == NULL)
	{
		printf("empty file pointer\n");
		return;
	}

	while (index<size && !feof(fp))
		fscanf(fp, "%d", &array[index++]);
}

void emptyBUffer(int * array, int index, int size, FILE *fp)
{
	if (fp == NULL)
	{
		printf("empty file pointer\n");
		return;
	}
	while (index < size && !feof(fp))
		fprintf(fp, "%d\n", array[index++]);

}

/*
int main(){
	int ramSize = 8;
	int inputFileSize = 16;
	int fileSize= ramSize / 4;
	int noFile = inputFileSize/fileSize,index;
	int size = 2;
	FILE** fp = (FILE**)malloc(sizeof(FILE*)*(noFile + 1));
	FILE *result = fopen("result.txt", "a+");
	FILE*inputFile = fopen("numbers.txt", "rb");
	char*fname;
	int *arr1 = (int*)malloc(sizeof(int) * 2);
	int *arr2 = (int*)malloc(sizeof(int) * 2);

	//creating file pointer arays
	for (int i = 0; i < noFile; i++){
		fp[i] = openFile(&fname, i,"wb");
	}

	index = 0;
	//reading and writing into temperory file
	for (int i = 0; i < noFile; i++)
	{
		fillBuffer(arr1, index, size,inputFile);
		mergeSort(arr1, 0, size-1);
 		emptyBUffer(arr1, index,size, fp[i]);
	}

	//closing files 
	for (int i = 0; i < noFile; i++){
		fclose(fp[i]);
	}
	fclose(result);
	fclose(inputFile);
	return 0;
}
*/