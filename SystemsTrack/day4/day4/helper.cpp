#include<stdio.h>
#include<stdlib.h>
#include"helper.h"

int stringLength(char * str)
{
	int len = 0;
	while (str[len] != '\0')
		len++;
	return len;
}


void removeEqual(char** arguments)
{
	int index = 0, equalIndex = -1;
	while (*arguments[index] != '\0'){
		if (*arguments[index] == '=')
		{
			*arguments = *arguments + index + 1;
			return;
		}
	}

}

char* getCommandName(char*command, int * spaceIndex)
{
	char* commandName = (char*)malloc(sizeof(char) * 10);
	int index = 0, letter = 0, res_index = 0;
	if (command[index] != ' ' && command[index]!='=')
		letter = 1;
	while (command[index] != '\0')
	{
		if (letter == 0 && (command[index] != ' '&&command[index]!='='))
			letter = 1;
		else if ((letter == 1 && (command[index] == ' '||command[index]=='=')) || command[index] == '\0')
		{
			commandName[res_index] = '\0';
			return commandName;
		}
		else{
			commandName[res_index++] = command[index];
			if (letter == 0)
				letter = 1;
		}
		index++;
		(*spaceIndex) += 1;
	}
	commandName[res_index] = '\0';
	return commandName;
}

void caseInsensitive(char* ch)
{
	int index = 0;
	while (ch[index] != '\0'){
		if (ch[index] >= 65 && ch[index] <= 90)
			ch[index] = ch[index] + 32;
		index++;
	}
}

char* divideCommand(char* command, char**arguments)
{
	caseInsensitive(command);
	if (command[0] == '\0')
		return 0;
	int  spaceLocation = 0;
	char* commandName = getCommandName(command, &spaceLocation);
	int len = stringLength(command);
	if (spaceLocation < len)
		*arguments = getCommandName(&command[spaceLocation + 1], &spaceLocation);
	else
		*arguments = " ";
	return commandName;
}
