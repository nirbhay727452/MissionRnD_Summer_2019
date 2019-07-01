#include "operationMap.h"

int getOpCode(char* vName)
{
	if (strcmp(vName, "ADD") == 1)
		return 3;
	if (strcmp(vName, "SUB") == 1)
		return 4;
	if (strcmp(vName, "MUL") == 1)
		return 5;
	if (strcmp(vName, "JMP") == 1)
		return 6;
	if (strcmp(vName, "IF") == 1)
		return 7;
	if (strcmp(vName, "EQ") == 1)
		return 8;
	if (strcmp(vName, "LT") == 1)
		return 9;
	if (strcmp(vName, "GT") == 1)
		return 10;
	if (strcmp(vName, "LTEQ") == 1)
		return 11;
	if (strcmp(vName, "GTEQ") == 1)
		return 12;
	if (strcmp(vName, "PRINT") == 1)
		return 13;
	if (strcmp(vName, "READ") == 1)
		return 14;
	return -1;
}

int getRegCode(char* regCode)
{
	if (strcmp(regCode, "AX") == 1)
		return 0;
	if (strcmp(regCode, "BX") == 1)
		return 1;
	if (strcmp(regCode, "CX") == 1)
		return 2;
	if (strcmp(regCode, "DX") == 1)
		return 3;
	if (strcmp(regCode, "EX") == 1)
		return 4;
	if (strcmp(regCode, "FX") == 1)
		return 5;
	if (strcmp(regCode, "GX") == 1)
		return 6;
	if (strcmp(regCode, "HX") == 1)
		return 7;
	return -1;
}