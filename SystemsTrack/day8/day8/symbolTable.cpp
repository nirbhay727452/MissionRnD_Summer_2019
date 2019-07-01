#include "symbolTable.h"

static int currentMemoryAddress = 0;
static int size=0;
void setSymbolTable(symbolTable *table, char* token, int tokenSize)
{
	fflush(stdout);
	printf("\nvhjvhvuhjmjhvname: %s  size : %d current memory: %d\n",token, size, currentMemoryAddress);
	strcpy(table[size].name, token);
	table[size].address = currentMemoryAddress;
	table[size].size = tokenSize;
	currentMemoryAddress += tokenSize;
	size++;
}

int getTokenAddress(symbolTable *table, char* tokenName)
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(table[i].name, tokenName) == 0)
			return table[i].address;
	}
	return -1;
}

void printSystemTable(symbolTable *sTable)
{
	for (int i = 0; i < size; i++)
	{

		printf("\n%s , %d , %d\n", sTable[i].name, sTable[i].address, sTable[i].size);
	}
}