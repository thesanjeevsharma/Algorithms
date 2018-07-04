//bubble sort program - C++
// O(n^2)
//Sanjeev Sharma

#include <iostream>
using namespace std;

#define n 6

void swap(int &a, int &b){
	int temp;
	temp = a;
	a = b;
	b = temp;	
}

void bubbleSort(int arr[]){
	for(int k = 0; k < n; k++) 
	for (int i = 0; i < n - 1; i ++) 
	if (arr[i + 1] < arr[i]) swap(arr[i], arr[i + 1]);

}

int main(){
	int arr[n] = {4, 5, 3, 1, 2, 0};
	
	cout << "Following array will be sorted!" << endl;
	for (int x : arr){
		cout << x << " ";
	}	
	cout << endl;
	bubbleSort(arr);
	for (int x : arr){
		cout << x << " ";
	}

	return 0;
}
