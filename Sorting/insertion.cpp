//insertion sort program - C++
// O(n^2)
//Sanjeev Sharma

#include <iostream>
using namespace std;

#define n 6

void insertionSort(int arr[]){
	int j, key;	
	for(int i = 1; i < n; i ++){
		j = i - 1;
		key = arr[i];
		while(j >= 0 && arr[j] > key){
			arr[j + 1] = arr[j];
			j = j - 1;		
		}
		arr[j + 1] = key;	
	}
}

int main(){
	int arr[n] = {4, 5, 3, 1, 2, 0};
	
	cout << "Following array will be sorted!" << endl;
	for (int x : arr){
		cout << x << " ";
	}	
	cout << endl;
	insertionSort(arr);
	for (int x : arr){
		cout << x << " ";
	}

	return 0;
}
