#include<stdio.h>
#include<stdlib.h>
#ifndef _stack_h
#define _stack_h

int* createStack(int size);
void insertStack(int* stack, int value);
int popStack(int *stack);
int isEmpty(int* stack);

#endif