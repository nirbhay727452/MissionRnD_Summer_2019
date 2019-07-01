#include<stdio.h>
#include<stdlib.h>
#include "fileSystem.h"
#include<string.h>


#define noOfHeader 10


struct node{
	char *fname;
	int offset;
	int length;
	int empty;
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
	if(fwrite(&noOfheader, sizeof(int), 1, hardDisk)==0)
		printf("error in writing file\n");
	if(fwrite(&header, sizeof(header[0]), noOfheader, hardDisk)==0)
		printf("error in writing file\n");
	fclose(hardDisk);
}


//returns numbers of metadata
int readMetaData(struct node* header)
{
	FILE *hardDisk = fopen("hardDisk.hdd", "rb+");
	if (hardDisk == NULL)
	{
		printf("file not opened");
		exit(1);
	}
	int noOfheader;
	if(fread(&noOfheader, sizeof(int), 1, hardDisk)==0)
		printf("error in reading file\n");
	if(fread(&header, sizeof(header[0]), noOfheader, hardDisk)==0)
		printf("error in reading file\n");
	fclose(hardDisk);
	return noOfheader;
}

void insertMetaData(struct node *metaData, char* fname, int offset, int size)
{//function to update metadata
	for (int i = 0; i < noOfHeader; i++)
	{
		if (metaData[i].empty == 1){
			metaData[i].fname = fname;
			metaData[i].offset = offset;
			metaData[i].length = size;
			metaData[i].empty = 0;
			return;
		}
	}
}

void listFiles(struct node*metaData)
{
	for (int i = 0; i < noOfHeader; i++)
		if (metaData[i].empty==0)
			printf("%s\t%d\n", metaData[i].fname, metaData[i].length);
}


void deleteFile(char* fname, struct node*metaData)
{
	for (int i = 0; i < noOfHeader; i++)
	{
		if (metaData[i].empty == 0)
		{
			if (strcmp(fname, metaData[i].fname) == 0)
			{
				metaData[i].empty = 1;
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
	char ch=fgetc(tempFile);
	while (ch != EOF)
	{
		fputc(ch, hardDisk);
		ch = fgetc(tempFile);
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
		if (temp[i].empty == 0)
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
		if (temp[i].empty == 1){
			if (i == 0)
				return 300;
			return (temp[i - 1].offset+ temp[i-1].length);
		}
	}
}


int main(){
	char *command = (char*)malloc(sizeof(char) * 10000);
	FILE * temp;
	struct node *metaData = (struct node*)malloc(sizeof(struct node)*noOfHeader);
	for (int i = 0; i < noOfHeader; i++){
		metaData[i].fname= (char*)malloc(sizeof(char) * 16);
		metaData[i].empty = 1;
	}
	int offset, metadata,index;
	while (1)
	{
		printf(">>>");
		gets(command);
		char **parsedString = parseIt(command);
		if (isEqual(parsedString[0], "format"))
		{

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
		else{
			printf("invalid file name\n");
		}

	}
	

	return 0;
}
