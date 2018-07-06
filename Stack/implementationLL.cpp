//stack program - C++
//Implementation using Linked List
//Sanjeev Sharma

#include <iostream>

using namespace std;

struct StackNode{
	int data;
	struct StackNode* next;
};

struct StackNode* newNode(){
	struct StackNode* new_node = (struct StackNode*)malloc(sizeof(struct StackNode));
	
	new_node->data = -1;
	new_node->next = NULL;
	
	return new_node;	

}

void push(struct StackNode* &head, int x){
	struct StackNode* new_node = newNode();

	new_node->data = x;
	new_node->next = head;
	head = new_node;

	cout << x << " pushed onto Stack." << endl;
}

bool isEmpty(struct StackNode* head){
	return !head;
}

int pop(struct StackNode* &head){

	if (isEmpty(head)) return -1;
	struct StackNode* temp = head;
	
	head = head->next;

	return temp->data;	
}

int peek(struct StackNode* head){
	if (isEmpty(head)) return -1;
	return head->data;
}

int main(){

	struct StackNode* head = NULL;
	
	cout << "Stack Empty: " << (isEmpty(head) ? "Yes" : "No") << endl;
	
	push(head, 1);
	push(head, 2);
	push(head, 3);

	cout << "Value poped: " << pop(head) << endl;

	cout << "Stack Empty: " << (isEmpty(head) ? "Yes" : "No") << endl;

	return 0;
}

