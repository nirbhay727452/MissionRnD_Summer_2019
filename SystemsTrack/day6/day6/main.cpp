#include<stdio.h>
#include<stdlib.h>
#include "fileSystem.h"
#include<string.h>


#define noOfHeader 10


struct node{
	char fname[16];
	int offset;
	int length;
	int full;
	int unused;
};

//writing metadata from disk
void writeMetaData(struct node* header, int noOfheader)
{
	FILE *hardDisk = fopen("hardDisk.hdd", "rb+");
	if (hardDisk == NULL)
	{
		printf("file not opened");
		exit(1);
	}
	for (int i = 0; i < noOfHeader; i++){
		if (fwrite(&header[i], sizeof(header[0]), 1, hardDisk) != 0)
			printf("%s   %d   %d\n", header[i].fname, header[i].offset, header[i].length);
	}
	fclose(hardDisk);
}


//returns numbers of metadata
void readMetaData(struct node* header)
{
	FILE *hardDisk = fopen("hardDisk.hdd", "rb+");
	if (hardDisk == NULL)
	{
		printf("file not opened");
		exit(1);
	}
	for (int i = 0; i < noOfHeader; i++){
		if (fread(&header[i], sizeof(header[0]), 1, hardDisk) != 0)
			printf("%s   %d   %d\n", header[i].fname, header[i].offset, header[i].length);
	}
	fclose(hardDisk);
}

void stringCopy(char* first, char* second){
	int index = 0;
	while (second[index] != '\0')
		first[index] = second[index];
	first[index] = '\0';
}

void insertMetaData(struct node *metaData, char* fname, int offset, int size)
{//function to update metadata
	for (int i = 0; i < noOfHeader; i++)
	{
		if (metaData[i].full == 0){
			strcpy(metaData[i].fname,fname);
			metaData[i].offset = offset;
			metaData[i].length = size;
			metaData[i].full = 1;
			return;
		}
	}
}

void listFiles(struct node*metaData)
{
	for (int i = 0; i < noOfHeader; i++)
		if (metaData[i].full == 1)
			printf("%s\t%d\n", metaData[i].fname, metaData[i].length);
}


void deleteFile(char* fname, struct node*metaData)
{
	for (int i = 0; i < noOfHeader; i++)
	{
		if (metaData[i].full == 1)
		{
			if (strcmp(fname, metaData[i].fname) == 0)
			{
				metaData[i].full = 0;
				return;
			}
		}
	}
	printf("file not found\n");
}


void writeFile(struct node *temp, int offset, char* fname)
{
	int size = 0;
	FILE *hardDisk = fopen("hardDisk.hdd", "rb+");
	if (hardDisk == NULL)
	{
		printf("file not opened");
		exit(1);
	}
	fseek(hardDisk, offset, SEEK_SET);
	FILE * tempFile = fopen(fname, "rb+");
	if (tempFile == NULL)
	{
		printf("file not opened");
		exit(1);
	}
	char ch;
	while (!feof(tempFile))
	{
		ch = fgetc(tempFile);
		fputc(ch, hardDisk);
		size++;
	}
	insertMetaData(temp, fname, offset, size);
	fclose(tempFile);
	fclose(hardDisk);
}

void readFile(char* fname, int offset, int size)
{
	FILE *hardDisk = fopen("hardDisk.hdd", "rb+");
	if (hardDisk == NULL)
	{
		printf("file not opened");
		exit(1);
	}
	fseek(hardDisk, offset, SEEK_SET);
	FILE * tempFile = fopen(fname, "rb+");
	if (tempFile == NULL)
	{
		printf("file not opened");
	}
	char ch = fgetc(hardDisk);
	for (int i = 0; i < size;i++)
	{
		fputc(ch, tempFile);
		ch = fgetc(hardDisk);
	}
	fclose(tempFile);
	fclose(hardDisk);

}

int findIndex(struct node* temp, char*fname)
{
	for (int i = 0; i < noOfHeader; i++)
	{
		if (temp[i].full == 1)
		{
			if (strcmp(temp[i].fname, fname) == 0)
			{
				return i;
			}
		}
	}
}

int findOffset(struct node * temp)
{
	for (int i = 0; i < noOfHeader; i++)
	{
		if (temp[i].full == 0){
			if (i == 0)
				return sizeof(temp)*(noOfHeader+1);
			return (temp[i - 1].offset+ temp[i-1].length);
		}
	}
}

void format(struct node* temp)
{
	for (int i = 0; i < noOfHeader; i++)
	{
		temp[i].full =0;
		temp[i].length = 0;
		temp[i].fname[0] = '\0';
	}
}


int main(){
	char *command = (char*)malloc(sizeof(char) * 10000);
	FILE * temp;
	struct node *metaData = (struct node*)malloc(sizeof(struct node)*noOfHeader);
	for (int i = 0; i < noOfHeader; i++){
		metaData[i].full = 0;
	}
	int offset, metadata,index;
	readMetaData(metaData);
	while (1)
	{
		printf(">>>");
		gets(command);
		char **parsedString = parseIt(command);
		if (isEqual(parsedString[0], "format"))
		{
			format(metaData);
		}
		else if (isEqual(parsedString[0], "copyto"))//read from disk//copy to file from disk
		{
			char *diskLocation = parsedString[1];
			char *fileName = parsedString[2];
			index = findIndex(metaData,diskLocation);
			temp = fopen(fileName, "wb");
			fclose(temp);
			readFile(fileName, metaData[index].offset, metaData[index].length);
		}
		else if (isEqual(parsedString[0], "copyfrom"))//write to disk //copy from file to disk
		{
			char *fileName = parsedString[1];
			char *targetName = parsedString[2];
			offset = findOffset(metaData) + 1;
			writeFile(metaData, offset,fileName);

		}
		else if (isEqual(parsedString[0], "ls"))
		{
			listFiles(metaData);
		}
		else if (isEqual(parsedString[0], "exit")){
			writeMetaData(metaData, noOfHeader);
		}
		else {
			printf("invalid file name\n");
		}

	}
	

	return 0;
}
