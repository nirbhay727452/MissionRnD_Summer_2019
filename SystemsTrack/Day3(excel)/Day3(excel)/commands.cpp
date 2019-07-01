#include "commands.h"
#include "node.h"
#include "evaluation.h"
char* createString(char* value){
	char* ch = (char*)malloc(sizeof(char) * 10);
	int index = 0;
	while (value[index] != '\0')
	{
		ch[index] = value[index];
		index++;
	}
	ch[index] = '\0';
	return ch;
}

int stringToNumber(char*ch){
	int num = 0,index=0;
	while (ch[index] != NULL && ch[index]!=' '&& ch[index]!= '=')
	{
		num = (num * 10) + (ch[index] - '0');
		index++;
	}
	return num;
}



int * parseArguments(char*arguments)
{
	int * array = (int*)malloc(sizeof(int) *2);
	if (arguments[0] >= 97)
		array[0] = arguments[0] - 97;
	else
		array[0] = arguments[0] - 65;
	array[1] = stringToNumber(&arguments[1]);
	
	int index = 2;
	while (arguments[index++] != '\0')
	{
		if (arguments[index] == ' ' )
			continue;
		else if (arguments[index] == '=')
		{
			arguments += index;
			return array;
		}
	}
	return array;
}

char* checkFilename(char*fname){
	int index = 0, dotavailable = 0;
	while (fname[index] != '\0'){
		if (fname[index] == '.')
			dotavailable = 1;
		index++;
	}
	if (dotavailable == 0)
	{
		fname[index++] = '.';
		fname[index++] = 'c';
		fname[index++] = 's';
		fname[index++] = 'v';
		fname[index] = '\0';
	}
	return fname;
}



void set(struct node temp[][10], char*argumnents)
{
	int *arg = parseArguments(argumnents);
	temp[arg[0]][arg[1]].value = expressionEvaluator(argumnents,temp);
	temp[arg[0]][arg[1]].expression = argumnents;
}


struct node get(struct node temp[][10], char*arguments){
	int *array = parseArguments(arguments);
	return temp [array[0]] [array[1]];
}

void print(struct node temp[][10]){
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf("%d\t", temp[i][j].value);
		}
		printf("\n");
	}
}

void export(struct node temp[][10], char * fname)
{
	fname = checkFilename(fname);
	FILE *fp = fopen(fname, "wb");
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			fprintf(fp, "%d,", temp[i][j].value);
		}
		fprintf(fp, "%d\n", temp[i][9].value);
	}

	fclose(fp);
}

void import(struct node temp[][10], char *fname)
{
	fname = checkFilename(fname);
	FILE *fp = fopen(fname, "r");
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			fscanf(fp, "%d,", &temp[i][j].value);
		}
	}
	fclose(fp);
}

void save(struct node temp[10][10],int *imported, char**importedFileName){
	if (*imported == 0){
		printf("no file to save\n");
		//scanf("%s",&*importedFileName);
	}
	else 
	export(temp, *importedFileName);
}