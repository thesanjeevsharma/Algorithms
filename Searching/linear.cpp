//linear search program - C++
//Sanjeev Sharma

#include <iostream>
using namespace std;

#define n 10

int main(){
	int x[n] = {2, 4, 67, 34, 5, 78, 23, 11, 90, 44};
	int num;

	cout << "Enter the element you're looking for." << endl;
	cin >> num;

	for(int i = 0; i < n; i++){
		if (x[i] == num){
			cout << "Yes we have the element at index " << i << "." << endl;
			break;
		}
		else if (i == n - 1){
			cout << "No the element isn't there!" << endl;
			break;
		}
		else continue;
	}

	return 0;
}
