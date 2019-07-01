#include"intermediateLanguage.h"

static int size= 0;

void insertParsedResult(parsedResult * table, int insNumber, int OpCode, int Parameters[4])
{
	table[size].instructionNumber = size + 1;
	table[size].OpCode = OpCode;
	for (int i = 0; i < 4; i++)
	{
		table[size].parameters[i]=Parameters[i];
	}
	size++;
}

//for if else block
void updateParsedTable(parsedResult* table, int instNumber, int paramNumber, int paramValue)
{
	table[instNumber].parameters[paramNumber] = paramValue;
}