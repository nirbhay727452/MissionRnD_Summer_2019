#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#ifndef intermediate
#define intermediate

struct intermediateCode
{
	int instructionNumber;
	int OpCode;
	int parameters[4];
};

typedef struct intermediateCode parsedResult;
void insertParsedResult(parsedResult * table, int insNumber, int OpCode, int Parameters[4]);

#endif