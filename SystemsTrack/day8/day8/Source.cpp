#include<stdio.h>
#include<stdio.h>
#include"operationMap.h"
#include"parseInputFile.h"
#include "stack.h"
#include "symbolTable.h"
#include "intermediateLanguage.h"

int getAddress(char*var, symbolTable *Stable)
{
	if (var == NULL || var[0] == '\0')
		return -2;
	int regCode, varCode;
	if (var[1] == 'X')
	{
		regCode = getRegCode(var);
		return regCode;
	}
	varCode = getTokenAddress(Stable, var);
	return varCode;
}

void fillSymbolTable(symbolTable *sTable, char** commandData)
{
	if (strcmp(commandData[0], "CONST") == 0)
		setSymbolTable(sTable, commandData[1], 0);
	else
	{	
		int size;
		char* ch = (char*)malloc(sizeof(char) * 3);
		if (commandData[1][1] == '[')
		{
			size = commandData[1][2] - '0';
			ch[0] = commandData[1][0];
			ch[1] = '\0';
			setSymbolTable(sTable, ch, size);
		}
		else
		{
			printf("kkl  %s\n", commandData[1]);
			fflush(stdout);
			setSymbolTable(sTable, commandData[1], 1);
		}

	}
}

void fillIntermediateTable(char*fname,symbolTable *sTable, parsedResult *pResult)
{
	FILE* fp = fopen(fname, "rb+");
	int i,j;
	int noOfTokens,insNumber=1,OpCode,parameter[4];
	{
		noOfTokens = parseLine(fileData, commandData,index);
		if (strcmp(commandData[0], "DATA") == 0 || strcmp(commandData[0],"CONST")==1)
		{
			fillSymbolTable(sTable, commandData);
			continue;
		}

		OpCode = getOpCode(commandData[i]);
		for ( j = 0; j < noOfTokens; j++)
		{
			parameter[i] = getAddress(commandData[i], sTable);
		}
		for (j=noOfTokens; j <4;j++)
			parameter[j] = -2;
	}
	//insertParsedResult(pResult, lines, OpCode, parameter);
}






int main()
{
	char*fname = (char*)malloc(sizeof(char) * 20);
	//gets(fname);
	fname = "temp.txt";
	symbolTable *sTable = (symbolTable*)malloc(sizeof(symbolTable) * 26);
	parsedResult *presult = (parsedResult*)malloc(sizeof(parsedResult) * 40);
	fillIntermediateTable(fname, sTable, presult);
	printSystemTable(sTable);


	free(fileData);
	free(commandData);
	return 0;
  }




//setSymbolTable(sTable, "A", 2);
//getTokenAddress(sTable, "A");