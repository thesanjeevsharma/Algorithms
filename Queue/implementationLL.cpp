//queue program - C++
//Implementation using Linked List
//Sanjeev Sharma

#include <iostream>

#define SIZE 10

using namespace std;

//Node
struct QNode{
	int data;
	struct QNode* next;
};

//Queue
struct Queue{
	struct QNode* front;
	struct QNode* rear;
};

//Create Node
struct QNode* newNode(int item){
	struct QNode* new_node = (struct QNode*)malloc(sizeof(struct QNode));
	new_node->data = item;
	new_node->next = NULL;
	return new_node;
}

//Create Queue
struct Queue* createQueue(){
	struct Queue* new_queue = (struct Queue*)malloc(sizeof(Queue));
	new_queue->front = new_queue->rear = NULL;
	return new_queue;
}

void enQueue(struct Queue* &q, int item){

	struct QNode* new_node = newNode(item);
	
	if(q->rear == NULL){
		cout << "Queue inititated!" << endl;
		cout << "Added... " << item << endl;
		q->front = q->rear = new_node;
		return;	
	}

	cout << "Added... " << item << endl;
	q->rear->next = new_node;
	q->rear = new_node;

}

void deQueue(struct Queue* &q){
	
	if(q->front == NULL){
		cout << "Your queue looks empty!" << endl;
		return;
	}

	cout << "Removing element... " << q->front->data << endl;
	
	q->front = q->front->next;
	
	//Important Condition
	if(q->front == NULL) q->rear = NULL;	
}

int main(){

	struct Queue* q = createQueue();

	deQueue(q);
	enQueue(q, 1);
	enQueue(q, 2);
	enQueue(q, 3);
	enQueue(q, 4);
	deQueue(q);
	
	return 0;
}

