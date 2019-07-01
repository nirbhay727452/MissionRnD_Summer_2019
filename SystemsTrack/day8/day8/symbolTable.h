#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#ifndef symbol
#define symbol

struct symbolTable
{
	char name[20];
	int address;
	int size;
};

typedef struct symbolTable symbolTable;

int getTokenAddress(symbolTable *table, char* tokenName);
void setSymbolTable(symbolTable *table, char* token, int tokenSize);
void printSystemTable(symbolTable *sTable);


#endif
