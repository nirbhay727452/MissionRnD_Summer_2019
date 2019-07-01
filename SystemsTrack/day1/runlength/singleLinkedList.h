#include<stdlib.h>
#include<stdio.h>

struct node{
	int value;
	struct node* next;
};

struct node * createNode(int num){
	struct node*temp = (struct node*)malloc(sizeof(struct node));
	temp->value = num;
	temp->next = NULL;
	return temp;
}

int lenList(struct node* temp){
	int count = 0;
	while (temp != NULL)
		count++;
	return count;
}