//binary search program - C++
// O(log n)
//Sanjeev Sharma

#include <iostream>
using namespace std;

#define n 10

int binarySearch(int arr[], int start, int end, int num){

		int mid;

		mid = (start + end)/2;
		cout << "Mid is " << mid << endl;

		if(start <= end){
			if(arr[mid] == num) return mid;
			else if(arr[mid] > num) return binarySearch(arr, start, mid - 1, num);
			else if(arr[mid] < num) return binarySearch(arr, mid + 1, end, num);
		}
		else return -1;

}


int main(){
	int arr[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int num, length;

	cout << "Enter the element you're looking for." << endl;
	cin >> num;

	length = sizeof(arr)/sizeof(arr[0]);
	int res = binarySearch(arr, 0, length-1, num);

	if(res == -1) cout << "No! Element is not present in the list." << endl;
	else cout << "Element is present at index " << res << "." << endl;

	return 0;
}
