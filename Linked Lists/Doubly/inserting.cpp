//doubly linked list program - C++
//Sanjeev Sharma

#include <iostream>

using namespace std;

struct node{
	int data;
	node *next;
	//extra previous pointer
	node *prev;
};

void printList(struct node* n){
	while(n != NULL){
		cout << n->data << " ";
		n = n->next;
	}
	cout << endl;
}

void push(struct node* &head, int item){
	struct node* new_node = (struct node*)malloc(sizeof(struct node));

	new_node->data = item;
	new_node->next = head;
	new_node->prev = NULL;

	head = new_node;
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
	new_node->prev = temp;
}

void insertBefore(struct node* &head, int before, int item){
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	struct node* temp = head; 
	struct node* follow;

	new_node->data = item;

	if(temp->prev == NULL && temp->data == before){
		push(head, item);
		return;
	}
	
	while(temp->next != NULL){
		if(temp->data == before){
			new_node->prev = temp->prev;
			temp->prev = new_node;
			new_node->next = temp;
			follow->next = new_node;
			break;
		}
		follow = temp;
		temp = temp->next;
	}
}

void insertAfter(struct node* &head, int after, int item){
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	struct node* temp = head;

	new_node->data = item;

	while(temp->next != NULL){
		if(temp->data == after){
			new_node->next = temp->next;
			new_node->prev = temp;
			temp->next->prev = new_node;
			temp->next = new_node;
			break;
		}
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
	head->prev = NULL;

	second->data = 2;
	second->next = third;
	second->prev = head;

	third->data = 3;
	third->next = NULL;
	third->prev = second;
	
	// 1->2->3
	printList(head);

	push(head, 0);

	// 0->1->2->3
	printList(head);

	append(head, 4);

	// 0->1->2->3->4
	printList(head);

	insertBefore(head, 2, 2);

	// 0->1->2->2->3->4
	printList(head);

	insertBefore(head, 0, 0);

	// 0->0->1->2->2->3->4
	printList(head);

	insertAfter(head, 3, 4);

	// 0->0->1->2->2->3->4->4
	printList(head);

	return 0;
}


