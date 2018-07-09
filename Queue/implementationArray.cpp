//queue program - C++
//Implementation using Array
//Sanjeev Sharma

#include <iostream>

#define SIZE 10

using namespace std;

class Queue{
	int *arr;
	int capacity;
	int front;
	int rear;
	int count;
	public:
	Queue(int size = SIZE);
	void dequeue();
	void enqueue(int x);
	bool isEmpty();
	bool isFull();
	void peek();
	int size();	
};

Queue::Queue(int size){
	arr = new int[size];
	capacity = size;
	front = 0;
	rear = -1;
	count = 0;	
}

void Queue::dequeue(){
	
	if(isEmpty()){
		cout << "Queue is empty!" << endl;
		return;
	}
	
	cout << "Removing.. " << arr[front] << endl;
	front = (front + 1) % capacity;
	count--;
}

void Queue::enqueue(int item){
		
	if(isFull()){
		cout << "Queue is already full." << endl;
		return;
	}	
	
	cout << "Inserting.. " << item << endl;

	rear = (rear + 1) % capacity;
	arr[rear] = item;
	count++;
}

bool Queue::isEmpty(){
	if(count == 0) return true;
	else return false;
}

bool Queue::isFull(){
	if(count == capacity) return true;
	else return false;
}

int Queue::size(){
	return count;
}

void Queue::peek(){
	if (isEmpty()){
		cout << "Empty!" << endl;
		return;	
	}
	
	cout << "Element is: " << arr[front] << endl;
}

int main(){

	Queue q;

	q.isEmpty();
	q.dequeue();
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.dequeue();
	q.peek();
	q.isEmpty();

	return 0;
}

