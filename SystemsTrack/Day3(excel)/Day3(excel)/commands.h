#include<stdio.h>
#include<stdlib.h>
#ifndef _commands_h
#define _commands_h


char* createString(char* value);
struct node get(struct node temp[][10], char*cell);
void set(struct node temp[][10], char*argumnents);
void import(struct node temp[][10], char *fname);
void save(struct node temp[10][10], int *imported, char**importedFileName);
int * parseArguments(char*arguments);

#endif