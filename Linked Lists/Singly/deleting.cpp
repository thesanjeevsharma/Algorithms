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

void deleteNode(struct node* &head, int item){
	struct node* temp = head;
	struct node* prev;

	if(temp->next != NULL && temp->data == item){
		head = temp->next;
		free(temp);
	}

	while(temp->next != NULL){
		if (temp->data == item){
			prev->next = temp->next;
			free(temp);
			break;
		}
		prev = temp;
		temp = temp->next;
	}
	
	

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

	append(head, 4);

	// 1->2->3->4
	printList(head);

	deleteNode(head, 1);
	
	// 2->3->4
	printList(head);

	deleteNode(head, 3);
	
	// 2->4
	printList(head);	

	return 0;
}


