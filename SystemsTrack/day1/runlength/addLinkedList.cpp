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

struct node* addSLL(struct node* first, struct node* second){
	int len1 = 0, len2 = 0;
	struct node* temp = first, *result = NULL, *temp1;// *temp2;
	len1 = lenList(temp);
	temp = second;
	len2 = lenList(temp);
	int difference = len1 - len2;
	if (difference > 0){
		temp = first;
		for (int iter = 0; iter < difference; iter++){
			if (result == NULL)
			{
				result = createNode(temp->value);
				temp1 = result;
				temp = temp->next;
			}
			temp1->next = createNode(temp->value);
			temp = temp->next;
			temp1 = temp1->next;
		}
	}
	else{
		temp = first;
		for (int iter = 0; iter < difference; iter++){
			if (result == NULL)
			{
				result = createNode(temp->value);
				temp1 = result;
				temp = temp->next;
			}
			temp1->next = createNode(temp->value);
			temp = temp->next;
			temp1 = temp1->next;
		}
	}
	return result;
	}
int main()
{

    return 0;
}
