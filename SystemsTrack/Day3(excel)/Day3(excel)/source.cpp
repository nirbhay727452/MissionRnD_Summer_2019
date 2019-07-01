#include<stdio.h>
#include<stdlib.h>
#include "file.h"
#include "commandCheck.h"
#include "commands.h"
#include "node.h"
# include"evaluation.h"
#include "stack.h"

void load(struct node temp[10][10]){
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			temp[i][j].valuePresent = 1;
			temp[i][j].expression = NULL;
			temp[i][j].value = 0;
		}
	}
}

int main(){
	char* inputCommand = (char*)malloc(sizeof(char) * 100);
	char* importedFileName, *commandName,*arguments=(char*)malloc(sizeof(char)*100);
	struct node temp[10][10];
	struct node tempStruct;
	int valid, imported = 0,commandNumber,result;
	load(temp);
	while (1){
		printf("\n> ");
		gets(inputCommand);
		commandName = validCommand(inputCommand,&commandNumber,&arguments);
		switch (commandNumber)
		{
			case 0:
				set(temp, arguments);
				break;

			case 1:
				tempStruct=get(temp, arguments);
				printf("%d", tempStruct.value);
				break;

			case 2:
				print(temp);
				break;
			case 3:
				import(temp, arguments);
				imported = 1;
				importedFileName = arguments;
				break;
			case 4:
				export(temp, arguments);
				break;
			case 5:
				save(temp, &imported, &importedFileName);
				break;
			case 6:
				save(temp, &imported, &importedFileName);
				load(temp);
				break;
			case 7:
				result=expressionEvaluator(arguments,temp);
				printf("%d", result);
		}
	}
	return 0;
}