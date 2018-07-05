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

void deleteNode(struct node* &head, int item){
	struct node* temp = head;
	
	// If first node
	if(temp->data == item){
		temp->next->prev = NULL;
		head = temp->next;
		free(temp);
		return;
	}

	//If any other node
	while(temp->next != NULL){
		if(temp->data == item){
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			free(temp);
			return;
		}
		temp = temp->next;
	}

	//If last node
	if(temp->data == item){
		temp->prev->next = NULL;
		free(temp);
		return;
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

	append(head, 4);

	// 1->2->3->4
	printList(head);

	deleteNode(head, 4);

	// 1->2->3	
	printList(head);

	return 0;
}


