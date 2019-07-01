#include<stdio.h>
#include<stdlib.h>
#ifndef _commandCheck_h
#define _commandCheck_h

//returns 1 if command name is valid, else 0
char* validCommand(char* command, int *commandNUmber, char**arguments);
int stringLength(char * str);
int stringCompare(char* first, char* second);
int validCommandName(char* commandname);
char* getArguments(char* command);
void print(struct node temp[][10]);
void export(struct node temp[][10], char * fname);
void caseInsensitive(char* ch);


#endif