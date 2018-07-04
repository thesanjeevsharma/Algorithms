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

void push(struct node* &head, int item){
	struct node* new_node = (struct node *)malloc(sizeof(struct node));
	
	new_node->data = item;
	
	new_node->next = head;

	head = new_node;
}

void insertAfter(struct node* &head, int after, int item){
	struct node* new_node = (struct node *)malloc(sizeof(struct node));
	struct node* temp = head;	

	new_node->data = item;
	
	while(temp->next != NULL){
		if (temp->data == after){
			new_node->next = temp->next;
			temp->next = new_node;
			break;
		}
		temp = temp->next;
	}
}

void append(struct node* &head, int item){
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	struct node* temp = head;
	
	new_node->data = item;
	new_node->next = NULL;	

	while(temp->next != NULL){	
		temp = temp->next;	
	}

	temp->next = new_node;

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
	
	// 1->2->3
	printList(head);

	push(head, 0);
	
	// 0->1->2->3
	printList(head);

	insertAfter(head, 1, 1);
	
	// 0->1->1->2->3
	printList(head);

	append(head, 4);

	// 0->1->1->2->3->4
	printList(head);	

	return 0;
}


