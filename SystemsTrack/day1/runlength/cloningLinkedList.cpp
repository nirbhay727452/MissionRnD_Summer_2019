#include<stdio.h>
#include<stdlib.h>
#include<map>
/*
struct node{
	int value;
	struct node*next;
	struct node* random;
};

struct node*create_node(int num){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->value = num;
	temp->next = NULL;
	temp->random = NULL;
	return temp;
}

struct node* clone(struct node* root){
	if (root == NULL)
		return;
	struct node* next, *temp = root,*old_temp,*new_temp;
	while (temp != NULL){
		next=temp->next;
		temp->next = create_node(temp->value);
		temp->next->next = next;
		temp = next;
	}
	old_temp = root;
	new_temp = root->next;
	while (old_temp != NULL){
		new_temp->random = old_temp->random->next;
		old_temp = new_temp->next;
		new_temp = old_temp->next;
	}
	old_temp = root;
	new_temp = root->next;
	temp = new_temp;
	while (old_temp != NULL){
		old_temp->next = new_temp->next;
		new_temp = old_temp->next;
	}
	return temp;
}








*/

/*
int main(){
	std::map<int, int> m;
	m.insert(std::pair<int, int>(5, 25));
	m.insert(std::pair<int, int>(6, 36));
	std::map<int, int>::iterator i;
	i = m.find(6);
	printf("%d",i->second);
	i = m.find(5);
	printf("\n%d", i->second);
	return 0;
}
*/