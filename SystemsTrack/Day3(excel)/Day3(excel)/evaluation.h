#include<stdio.h>
#include<stdlib.h>
#include "node.h"
#ifndef evaluation_h
#define evaluation_h

char* nextSymbol(char*ch);
int expressionEvaluator(char* expression,struct node temp[][10]);

#endif