#include "doubleLinkedList.h";
// can use two approaches to divide list
/*
void swapNodes(struct node* first, struct node* second){
	struct node* temp = first->prev;
	first->prev = second->prev;
	second->prev = temp;
	temp = first->next;
	first->next = second->next;
	second->next = temp;
}

void merge(struct node*root, struct node* mid, struct node*last){
	while (root != mid && mid->next != last){
		if (root->value > mid->next->value){
			swapNodes(root, mid->next);

		}

	}

}

void mergeSortDivide(struct node*root,  struct node* last){
	if (root == NULL || root==last)
		return;
	struct node*mid,*temp;
	int count = 0;
	while (temp != last)
	{
		temp = temp->next;
		count++;
	}
	for (int iter = 0; iter >= count / 2; iter++){
		temp = temp->prev;
	}
	mergeSortDivide(root, temp);
	mergeSortDivide(temp->next, last);
	merge(root, temp, last);
}
*/