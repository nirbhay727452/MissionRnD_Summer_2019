#include<stdio.h>
#include<stdlib.h>
#include "helper.h"
#include"evaluation.h"
int main(){
	char* inputString = (char*)malloc(sizeof(char) * 100),*arguments,*variable;
	int result;
	int i = 0;
	while (1){
		gets(inputString);
		//variable = divideCommand(inputString, &arguments);
		//removeEqual(&arguments);
		//printf("variable %s\narguments %s\n", variable, arguments);
		result = expressionEvaluator(inputString);
		printf("%d\n", result);
	}
	return 0;
}