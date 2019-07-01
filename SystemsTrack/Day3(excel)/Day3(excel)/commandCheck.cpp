#include<stdio.h>
#include<stdlib.h>
int stringLength(char * str)
{
	int len = 0;
	while (str[len] != '\0')
		len++;
	return len;
}

int stringCompare(char* first, char* second){
	int index = 0;
	if (stringLength(first) != stringLength(second))
		return 0;
	while (first[index] != '\0' || second[index] != '\0')
	{
		if (first[index] != second[index])
			return 0;
		index++;
	}
	return 1;
}

int validCommandName(char* commandname){
	char** commands = (char**)malloc(sizeof(char*) * 8);
	commands[0] = "set";
	commands[1] = "get";
	commands[2] = "print";
	commands[3] = "import";
	commands[4] = "export";
	commands[5] = "save";
	commands[6] = "new";
	commands[7] = "eval";

	int present = -1;
	for (int i = 0; i < 8; i++)
		if (stringCompare(commands[i], commandname) == 1)
			present = i;

	return present;
}




char* getCommandName(char*command, int * spaceIndex){
	char* commandName = (char*)malloc(sizeof(char) * 10);
	int index = 0, letter = 0,res_index=0;
	if (command[index] != ' ')
		letter = 1;
	while(command[index]!='\0')
	{
		if (letter == 0 && command[index] != ' ')
			letter = 1;
		else if ((letter == 1 && command[index] == ' ' && *spaceIndex==0)|| command[index]=='\0')
		{
			(*spaceIndex) += index;
			commandName[res_index] = '\0';
			return commandName;
		}
		else if (*spaceIndex != 0){
			if (command[index] == ' ')
			{
				continue;
			}
			else{
				commandName[res_index++] = command[index];
			}
		}
		else{
			commandName[res_index++] = command[index];
			if (letter == 0)
				letter = 1;
		}
		index++;
	}
	(*spaceIndex) += index;
	commandName[res_index] = '\0';
	return commandName;
}

void caseInsensitive(char* ch){
	int index = 0;
	while (ch[index] != '\0'){
		if (ch[index] >= 65 && ch[index] <= 90)
			ch[index] = ch[index] + 32;
		index++;
	}
}



char* validCommand(char* command,int *commandNUmber,char**arguments){
	caseInsensitive(command);
	if (command[0] == '\0')
		return 0;
	int  spaceLocation=0;
	char* commandName = getCommandName(command,&spaceLocation);
	*commandNUmber = validCommandName(commandName);
	if ( *commandNUmber== -1)
	{
		printf("\ninvalid command name");
		return 0;
	}
	int len = stringLength(command);
	if (spaceLocation < len)
		*arguments = getCommandName(&command[spaceLocation + 1], &spaceLocation);
	else
		*arguments = " ";
	return commandName;
}

