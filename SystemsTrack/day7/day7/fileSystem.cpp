#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int isEqual(char *str1, char *str2)
{
	for (int i = 0; str1[i] != '\0'; i++)
	{
		if (str1[i] != str2[i])
			return 0;
	}
	return 1;
}
char ** parseIt(char *command)
{
	char *word = (char*)malloc(sizeof(char) * 100);
	int wordIndex = 0;

	char ** split = (char**)malloc(sizeof(char*) * 1000);
	for (int i = 0; i<100; i++)
		split[i] = (char*)malloc(sizeof(char) * 1000);

	int index = 0;

	for (int i = 0; command[i] != '\0'; i++)
	{
		if (command[i] != ' ')
		{
			word[wordIndex] = command[i];
			wordIndex++;
		}
		else
		{
			word[wordIndex] = '\0';
			wordIndex = 0;
			strcpy(split[index], word);
			index++;
		}
	}
	strcpy(split[index], word);

	return split;
}