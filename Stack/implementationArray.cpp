//stack program - C++
//Implementation using Array
//Sanjeev Sharma

#include <iostream>

using namespace std;

#define MAX 5

class Stack{
	int top;
	public:
	int arr[MAX];
	Stack(){ top = -1; }
	bool push(int x);
	int pop();
	bool isEmpty();
};

bool Stack::push(int x){
	if (top == MAX - 1){
		cout << "Stack overflow!" << endl;
		return false;
	} else {
		arr[++top] = x;
		return true;
	}
}

int Stack::pop(){
	if (top < 0){
		cout << "Stack underflow!" << endl;
		return 0; 
	}else{
		int x = arr[top--];
		return x; 
	}
}

bool Stack::isEmpty(){
	return (top < 0);
}

int main(){

	struct Stack s;
	cout << s.pop() << endl;

	s.push(1);
	s.push(2);
	s.push(3);

	cout << (s.isEmpty() ? "Empty" : "Not Empty") << endl;	

	return 0;
}


