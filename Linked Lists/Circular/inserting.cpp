//circular linked list program - C++
//Sanjeev Sharma

//traversing and inserting both here!

#include <iostream>

using namespace std;

struct node{
	int data;
	node *next;
};

void printList(struct node* head){
	struct node* temp = head;
	do{
		cout << temp->data << " ";
		temp = temp->next;
	}while(temp != head);
	cout << endl;
}

void push(struct node* &head, int item){
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	struct node* temp = head;

	new_node->data = item;
	new_node->next = head;

	while(temp->next != head){
		temp = temp->next;
	}

	temp->next = new_node;
	head = new_node;	
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
	third->next = head;
	

	// 1->2->3
	printList(head);

	push(head, 4);

	// 1->2->3->4
	printList(head);

	

	return 0;
}


