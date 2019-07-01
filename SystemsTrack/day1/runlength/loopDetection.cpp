#include "singleLinkedList.h"

struct node* detectLoop(struct node* root){
	struct node* fast = root, *slow = root;
	int loop = 0;
	while (fast != NULL || slow != NULL){
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			loop = 1;
			break;
		}
	}
	fast = root;
	if (loop){
		while (fast!=slow)
		{
			fast = fast->next;
			slow = slow->next;
		}
	}
	return fast;
}

int main(){
	struct node* root,*loop=NULL;
	root = (struct node*)malloc(sizeof(struct node) * 100);
	root = createNode(1);
	struct node* temp = root;
	for (int i = 1; i <10; i++){
		temp->next = createNode(i + 1);
		temp = temp->next;
		if (i == 5){
			loop = temp;
		}
	}
	temp->next = loop;
	temp = root;
	while (temp != NULL)
	{
		printf("%d  ", temp->value);
		temp = temp->next;
	}
	printf("\n\n");
	temp = detectLoop(root);
	printf("loop at %d", temp->value);
	return 0;
}