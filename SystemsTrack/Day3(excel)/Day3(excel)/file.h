#include<stdio.h>
#include<stdlib.h>
#ifndef _file_h
#define _file_h

void writeData(char*fname, char*ch);
char* readData(char*fname);
FILE* openNewFileR(char * fname);
FILE* openNewFileW(char * fname);
void closeFile(FILE* fp);


#endif