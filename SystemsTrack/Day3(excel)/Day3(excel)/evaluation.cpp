#include<stdio.h>
#include<stdlib.h>
#include "evaluation.h"
#include "stack.h"
#include "node.h"
#include "commands.h"

int value(char* exp, struct node temp[][10]){
	int* location = parseArguments(exp);
	if (temp[location[0]][location[1]].valuePresent == 1)
		return temp[location[0]][location[1]].value;
	return(value(temp[location[0]][location[1]].expression, temp));
}


char* nextSymbol(char*ch){
	int index = 0, res_index = 0, number = 0,variable=0;
	char* result = (char*)malloc(sizeof(char) * 10);
	while (ch[index] != '\0'){
		if (ch[index] == ' ')
		{
			index++;
			continue;
		}
		//checking for variables
		if (ch[index] >= 97 && ch[index] <= 127 || variable==1){
			if (ch[index] >= 97 && ch[index] <= 127)
			{
				result[res_index++] = ch[index];
			}

			if (ch[index] >= 48 && ch[index] <= 57){
				result[res_index++] = ch[index];
			}
			if (ch[index] == '+' || ch[index] == '-' || ch[index] == '*' || ch[index] == '/')
				break;
			variable = 1;
		}
		if (variable == 0)
		{
			if ((ch[index] == '+' || ch[index] == '-' || ch[index] == '/' || ch[index] == '*' || ch[index] == '(' || ch[index] == ')') && number == 0)
			{
				result[res_index++] = ch[index];
				break;
			}

			if (ch[index] >= 48 && ch[index] <= 57){
				result[res_index++] = ch[index];
				number = 1;
			}

			if (!(ch[index] >= 48 && ch[index] <= 57) && number == 1)
				break;
		}
		index++;
	}
	result[res_index] = '\0';
	return result;
}

int stringToInt(char* string){
	int index = 0, result = 0;
	while (string[index] != '\0')
	{
		result *= 10;
		result += string[index++] - '0';
	}
	return result;
}

int evaluate(int op1, int op2, char operand)
{
	if (operand == '+')
		return op1 + op2;
	else if (operand == '-')
		return op2 - op1;
	else if (operand == '*')
		return op1*op2;
	else if (operand == '/')
		return op1 / op2;

}

int preecedence(char ch){
	if (ch == '+' || ch == '-')
		return 0;
	if (ch == '*' || ch == '/')
		return 1;
	if (ch == '(')
		return -1;
}

int lengthNumber(int num)
{
	int len = 0;
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return len - 1;
}
int lenstr(char *ch){
	int len = 0;
	while (ch[len] != '\0')
		len++;
	return len - 1;
}
int expressionEvaluator(char* expression,struct node temp[][10]){
	int index = 0, immediateOperator = 0, op1, op2, result, var = 0;
	char *currentSymbol, op = '0';
	int * numberStack = createStack(100);
	int* operatorStack = createStack(50);
	while (expression[index] != '\0')
	{
		currentSymbol = nextSymbol(expression + index);//modify length
		//checking variable
		if (currentSymbol[0] >= 97 && currentSymbol[0] <= 127)
		{
			var = 1;
			index += lenstr(currentSymbol);
		}
		else var = 0;
		//checking left paranthesis
		if (currentSymbol[0] == '(')
		{
			insertStack(operatorStack, currentSymbol[0]);
			immediateOperator = 0;
		}
		//checking for * and /
		else if (currentSymbol[0] == '*' || currentSymbol[0] == '/' || currentSymbol[0] == '+' || currentSymbol[0] == '-')
		{
			while (isEmpty(operatorStack) == 0)
			{
				op = popStack(operatorStack);
				if (preecedence(currentSymbol[0]) > preecedence(op))
				{
					insertStack(operatorStack, op);
					break;
				}
				op1 = popStack(numberStack);
				op2 = popStack(numberStack);
				result = evaluate(op1, op2, op);
				insertStack(numberStack, result);
			}
			insertStack(operatorStack, currentSymbol[0]);
			immediateOperator = 1;
		}

		//handling right paranthesis
		else if (currentSymbol[0] == ')')
		{
			op = popStack(operatorStack);
			while (op != '('){
				op1 = popStack(numberStack);
				op2 = popStack(numberStack);
				result = evaluate(op1, op2, op);
				insertStack(numberStack, result);
				op = popStack(operatorStack);
			}
			immediateOperator = 0;
		}

		//handling integers
		else if ((currentSymbol[0] == '+' || currentSymbol[0] == '-') && immediateOperator !=0)
		{
			immediateOperator = currentSymbol[0];

		}

		else if (currentSymbol[0] >= 48 && currentSymbol[0] <= 57 || var==1)
		{
			if (var==1)
				op1 = value(currentSymbol, temp);
			else
				op1 = stringToInt(currentSymbol);
			insertStack(numberStack, op1);
			index += lengthNumber(op1);
			immediateOperator = 0;
		}
		index++;
	}

	while (isEmpty(operatorStack) == 0)
	{
		op = popStack(operatorStack);
		op1 = popStack(numberStack);
		op2 = popStack(numberStack);
		result = evaluate(op1, op2, op);
		insertStack(numberStack, result);
	}
	return popStack(numberStack);
}