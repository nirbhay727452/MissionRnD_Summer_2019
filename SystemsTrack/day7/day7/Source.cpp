#include<stdio.h>
#include<stdlib.h>
#include "fileSystem.h"
#include<string.h>


#define noOfHeader 30
#define blockSize 16384
#define totalBlock 6400

struct node{
	char fname[20];
	int startBlock;
	int noOfBuffer;
	int fileLength;
};


void stringCopy(char* first, char* second){
	int index = 0;
	while (second[index] != '\0')
		first[index] = second[index++];
	first[index] = '\0';
}

int getIndex(struct node* metaData, char*fname, int noOfFiles)
{
	for (int i = 0; i < noOfFiles; i++)
		if (strcmp(metaData[i].fname, fname))
			return i;
	printf("file not found\n");
	return -1;
}

int getFileSize(char* fname)
{
	int size = 0;
	FILE *fp = fopen(fname, "rb+");
	while (!feof(fp))
	{
		fgetc(fp);
		size++;
	}
	fclose(fp);
	return size;
}

//finds empty index in buffer
int findEmptyIndex(char* buffer, int size)
{
	int empty = 1;
	for (int i = 2; i < 6399; i++)
	{
		empty = 0;
		if (buffer[i] == 0 && buffer[i + 1] == 0)
		{
			empty++;
			if (empty >= size)
				return i;
		}
	}
	return -1;
}

//writing block from disk
void readBlock(char *buffer,int blockNumber)
{
	FILE *fp = fopen("hardDisk.hdd", "rb+");
	if (fp == NULL)
	{
		printf("error in opening file ");
		exit(1);
	}
	fseek(fp, blockNumber*blockSize, SEEK_CUR);
	fread(buffer, blockSize, 1, fp);
	fclose(fp);
}

//reading block from disks
void writeBlock(char *buffer, int blockNumber)
	{
	FILE *fp = fopen("hardDisk.hdd", "rb+");
	if (fp == NULL)
	{
		printf("error in opening file ");
		exit(1);
	}
	fseek(fp, blockNumber*blockSize, SEEK_CUR);
	fwrite(buffer, blockSize, 1, fp);
	fclose(fp);
}

void updateMetaData(struct node *metaData,char*fname ,int blockStart, int size , int noOfBlocks, int noOfFiles)
{
	metaData[noOfFiles + 1].fileLength = size;
	stringCopy(metaData[noOfFiles + 1].fname, fname);
	metaData[noOfFiles + 1].noOfBuffer = noOfBlocks;
	metaData[noOfFiles + 1].startBlock = blockStart;
	printf("%s   %d  %d  %d", metaData[noOfFiles + 1].fname, metaData[noOfFiles + 1].startBlock, metaData[noOfFiles + 1].noOfBuffer, metaData[noOfFiles + 1].fileLength);
}

void copyToDisk(char*fname, struct node* metadata,char*buffer,int * noOfFiles, char* bitMap)
{
	int fileSize = getFileSize(fname), index;
	FILE *src = fopen(fname, "rb+");
	if (src == NULL)
		printf("error in opening file\n");
	int block = 0;
	if (fileSize%blockSize == 0)
		block = fileSize / blockSize;
	else
		block = fileSize / blockSize + 1;



	index = findEmptyIndex(bitMap, block);
	//check for file size
	//update metadata and bitmap
	(*noOfFiles) += 1;
	updateMetaData(metadata, fname, index, fileSize, block,*noOfFiles);
	for (int i = 0; i < block; i++)
		bitMap[index] = 1;

	while (fileSize >blockSize)
	{
		memcpy(buffer, src, blockSize);
		fseek(src, blockSize, SEEK_CUR);
		writeBlock(buffer, index++);
		fileSize -= blockSize;
	}
	if (fileSize > 0 && fileSize < blockSize)
	{
		//fread(buffer,fileSize,1,src);
		//fseek(src, 0, SEEK_SET);
		memcpy(&buffer[0], src, fileSize);
		writeBlock(buffer, index);
	}
	//write metadata to disk
	memcpy(buffer, &metadata, sizeof(metadata));
	writeBlock(buffer, 0);
	fclose(src);
}


void copyFromDisk(char* src,char* dest, struct node*metadata, int *noOfFiles, char* bitmap,char* buffer, int* freeBlock)
{
	int index = getIndex(metadata, src, *noOfFiles);
	int size = metadata[index].fileLength;
	int blockNumber = metadata[index].startBlock;
	FILE * destination = fopen(dest, "w");
	fclose(destination);
	destination = fopen(dest, "rb+");
	if (destination = NULL)
		printf("error whie opening files\n");

	while (size>=blockSize)
	{
		readBlock(buffer, blockNumber);
		memcpy(destination, buffer, blockSize);
		size -= blockSize;
	}
	if (size > 0 && size < blockSize)
	{
		readBlock(buffer, blockNumber);
		memcpy(destination, buffer, size);
	}
}

void format(struct node* metadata,char*bitMap,int*noOFFiles,char* buffer, int* freeBlock)
{
	//also check for nooffiles and freeblock
	(*noOFFiles) = 0;
	for (int i = 2; i < totalBlock; i++)
		bitMap[i] = 0;
	memcpy(buffer,metadata , blockSize);
	writeBlock(buffer, 0);
	memcpy(buffer, bitMap, blockSize);
	writeBlock(buffer, 1);
}

void deleteFromDisk(char* fname, struct node* metadata, char*buffer, int*noOfFiles, int* freeBlocks,char* bitMap)
{
	int index = getIndex(metadata, fname, *noOfFiles);
	//updating bitmap
	int size = metadata[index].fileLength,bitMapIndex=metadata[index].startBlock;
	while (size > blockSize)
	{
		bitMap[index++] = 0;
	}
	if (size > 0 && size < blockSize)
		bitMap[index] = 0;

	//first files stored in 3rd index ie 2
	(*noOfFiles) -= 1;
	metadata[index].fileLength = metadata[*noOfFiles].fileLength;
	strcpy(metadata[index].fname, metadata[*noOfFiles].fname);
	metadata[index].noOfBuffer = metadata[*noOfFiles].noOfBuffer;
	metadata[index].startBlock = metadata[*noOfFiles].startBlock;
	(*freeBlocks) += 1;
}

void listFiles(struct node* metadata, int noOfFiles)
{
	for (int i = 0; i < noOfFiles; i++)
		printf("%s   %d  %d  &d", metadata[i].fname, metadata[i].startBlock, metadata[i].noOfBuffer, metadata[i].fileLength);
}

void readMetaData(struct node*temp,char*buffer)
{
	readBlock(buffer, 0);
	memcpy(temp, buffer, blockSize);
}


int main(){
	char *command = (char*)malloc(sizeof(char) * 10000);
	struct node *metaData = (struct node*)malloc(sizeof(struct node)*noOfHeader);
	//char buffer[blockSize];
	char *buffer=(char*)malloc(sizeof(char)*blockSize);
	char bitMap[6400] = { 0 },*src,*dest;
	bitMap[0] = 1, bitMap[1] = 1;
	int noOFFiles=0,freeBlocks=6398;
	
	while (1)
	{
		printf("\n>>>");
		gets(command);
		char **parsedString = parseIt(command);
		if (isEqual(parsedString[0], "ls"))
		{
			listFiles(metaData,noOFFiles);
		}
		else if(isEqual(parsedString[0], "copytodisk"))
		{
			src = parsedString[1];
			copyToDisk(src, metaData, buffer, &noOFFiles, bitMap);
			freeBlocks -= 1;
		}
		else if (isEqual(parsedString[0], "copyfromdisk"))
		{
			src=parsedString[1];
			dest= parsedString[2];
			copyFromDisk(src, dest, metaData, &noOFFiles, bitMap, buffer, &freeBlocks);
		}
		else {
			printf("invalid file name\n");
		}

	}


	return 0;
}
