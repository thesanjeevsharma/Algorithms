//interpolation search program - C++
// O(log log n)
//Sanjeev Sharma

#include <iostream>
using namespace std;

#define n 10

int interpolationSearch(int arr[], int length, int num){
	int start = 0, end = length - 1;

	while(start <= end && num >= start && num <= end){
		int pos = start + (((double)(num - start)/(arr[end] - arr[start])) * (num - arr[start]));

		if(arr[pos] == num) return pos;
		else if (arr[pos] > num) end = pos - 1;
		else start = pos + 1;

	}

	return -1;
}


int main(){
	int arr[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int num, length;

	cout << "Enter the element you're looking for." << endl;
	cin >> num;

	length = sizeof(arr)/sizeof(arr[0]);
	int res = interpolationSearch(arr, length, num);

	if(res == -1) cout << "No! Element is not present in the list." << endl;
	else cout << "Element is present at index " << res << "." << endl;

	return 0;
}
