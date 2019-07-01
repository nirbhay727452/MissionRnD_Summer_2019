#include<stdio.h>
#include<stdlib.h>
#include "commandCheck.h"
#include "commands.h"
#include "node.h"
# include"evaluation.h"

void init(struct node temp[10][10]){
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
	int noOfWorkingDays;
	int startWorkingHours;
	int endWorkingHours;
	char* inputCommand;
	while (1){
		printf("\n> ");
		gets(inputCommand);
		commandName = validCommand(inputCommand, &commandNumber, &arguments);
		switch (commandNumber)
		{
		case 0:
			//init();
			break;

		case 1:

			break;

		case 2:

			break;
		case 3:

			break;
		case 4:

			break;
		case 5:

			break;
		case 6:

			break;
		case 7:

		}
	}
	return 0;
}