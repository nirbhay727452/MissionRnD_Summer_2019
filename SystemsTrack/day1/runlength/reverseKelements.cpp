#include<stdio.h>
#include"singleLinkedList.h"

/*
struct node* reverse(struct node* root, int k){
	if (root == NULL)
		return NULL;
	int count = 2;
	struct node* temp = root, *next=temp->next,*store;
	while (next!=NULL && count<=k)
	{
		store = next->next;
		next -> next = temp;
		temp->next = store;
		temp = next;
		next = store;
		count++;
	}
	return temp;
}

struct node* foo(int k, struct node* root1){
		struct node *temp = root1,*root=root1;
	if (root == NULL)
		return NULL;
	int count = 0,total=0;
	while (temp != NULL){
		temp = temp->next;
		count++;
	}
	struct node* new_node = NULL;
	while (count > 0){
		if (count < k && new_node==NULL)
			return root;
		else if (count < k){
			return new_node;
		}
		if (new_node == NULL){
			new_node = reverse(root, k);
			root = new_node;
			count -= k;
			total += k;
			temp = new_node;
		}
		else{
			for (int i = 0; i < total-1; i++)
				temp = temp->next;
			temp->next = reverse(root, k);
			count -= k;
			total += k;
		}
		for (int i = 0; i < k && i<count; i++)
			root = root->next;
	}
	return new_node;
}



int main()
{
	struct node* root;
	root = (struct node*)malloc(sizeof(struct node) * 100);
	root = createNode(1);
	struct node* temp = root;
	for (int i = 1; i <4; i++){
		temp->next = createNode(i + 1);
		temp = temp->next;
	}
	temp = root;
	while (temp != NULL){
		printf("%d   ", temp->value);
		temp = temp->next;
	}
	printf("\n");
	temp=foo(3, root);
	while (temp != NULL){
		printf("%d   ", temp->value);
		temp = temp->next;
	}
	return 0;
}
*/