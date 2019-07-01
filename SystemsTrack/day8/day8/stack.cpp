#include<stdio.h>
#include<stdlib.h>
#include "stack.h"


int* createStack(int size)
{
	int *stack = (int*)malloc(sizeof(int)*size);
	for (int i = 0; i < size; i++)
		stack[i] = -1;
	return stack;
}

void insertStack(int* stack, int value)
{
	int index = 0;
	while (stack[index] != -1)
		index++;
	stack[index] = value;
	return;
}

int popStack(int *stack)
{
	int pop = 0;
	int index = 0;
	while (stack[index] != -1)
		index++;
	pop = stack[index - 1];
	stack[index - 1] = -1;
	return pop;
}

int isEmpty(int* stack)
{
	if (stack[0] == -1)
		return 1;
	return 0;

}