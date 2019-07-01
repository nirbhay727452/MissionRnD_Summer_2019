#include<stdio.h>
#include<stdlib.h>
#include"file.h"

void writeData(char*fname, char*ch){
	FILE *fp = fopen(fname, "wb");
	if (!fp)
		printf("error in opening file");
	for (int i = 0; ch[i] != '\0'; i++)
		fputc(ch[i], fp);
	fclose(fp);
}

char* readData(char*fname){
	FILE *fp = fopen(fname, "r");
	char*ch = (char*)malloc(sizeof(char) * 100);
	int index = 0;
	char c;
	while (c = getc(fp) != EOF)
		ch[index++] = c;
	fclose(fp);
	ch[index] = '\0';
	return ch;
}

FILE* openNewFileR(char * fname){
	FILE *fp = fopen(fname, "rb");
	if (fp == NULL){
		printf("error in opening %s in read format\n ", fname);
		exit(1);
	}
	return fp;
}

FILE* openNewFileW(char * fname){
	FILE *fp = fopen(fname, "wb");
	if (fp == NULL){
		printf("error in opening %s in write format\n ", fname);
		exit(1);
	}
	return fp;
}

void closeFile(FILE* fp){
	fclose(fp);
}