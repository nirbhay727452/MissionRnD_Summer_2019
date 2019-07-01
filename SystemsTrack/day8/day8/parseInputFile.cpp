#include"parseInputFile.h"
int getFileSize(char* fname)
{
	FILE *fp = fopen(fname, "rb+");
	if (fp == NULL)
	{
		printf("file not opened");
		return -1;
	}
	int size = 0;
	char ch;
	while (!feof(fp))
	{
		ch = getc(fp);
		size++;
	}
	fclose(fp);
	return size;
}


//returns size of file
int readFile(char* fileData, char*fname)
{
	FILE* fp = fopen(fname, "rb+");
	if (fp == NULL)
	{
		printf("file not opened ");
		return;
	}
	int size = getFileSize(fname);
	fread(fileData, size, 1, fp);
	fclose(fp);
}

void getLine(char*line, char* data, int*index,int size){
	while (data[*index]!='\n' && *)
}

//return number of words in line
int parseLine(char*line, char** result, int *index)
{
	int row=0,col=0;
	while (line[*index] != '\n' && line[*index]!='\0')
	{
		col = 0;
		while (line[*index] != ' ' && line[*index]!='\0')
		{
			result[row][col] = line[*index];
			col++;
			index++;
		}
		result[row][col] = '\0';
		row++;
		if (line[*index] == '\0')
			return row;
		(*index)++;
	}
	return row;
}
