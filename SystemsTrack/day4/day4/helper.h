#include<stdio.h>
#include<stdlib.h>
#ifndef _helper_h
#define _helper_h

int stringLength(char * str);
char* getCommandName(char*command, int * spaceIndex);
void caseInsensitive(char* ch);
char* divideCommand(char* command, char**arguments);
void removeEqual(char** arguments);


#endif