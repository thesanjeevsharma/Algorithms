//selection sort program - C++
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

void selectionSort(int arr[]){
	int min_idx;
	
	for(int i = 0; i < n - 1; i++){
		min_idx = i;
		for(int j = i + 1; j < n; j++) if(arr[j] < arr[min_idx]) min_idx = j;
		swap(arr[i], arr[min_idx]);
	}

}

int main(){
	int arr[n] = {4, 5, 3, 1, 2, 0};
	
	cout << "Following array will be sorted!" << endl;
	for (int x : arr){
		cout << x << " ";
	}	
	cout << endl;
	selectionSort(arr);
	for (int x : arr){
		cout << x << " ";
	}

	return 0;
}
