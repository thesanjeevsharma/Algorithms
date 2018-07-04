//linked list program - C++
//Sanjeev Sharma

#include <iostream>

using namespace std;

struct node{
	int data;
	node *next;
};

void printList(struct node* n){
	while(n != NULL){
		cout << n->data << " ";
		n = n->next;
	}
	cout << endl;
}

int main(){

	struct node* head = NULL;
	struct node* second = NULL;
	struct node* third = NULL;

	head = (struct node*)malloc(sizeof(struct node));
	second = (struct node*)malloc(sizeof(struct node));
	third = (struct node*)malloc(sizeof(struct node));

	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;
	
	printList(head);

	return 0;
}


