// Oscar Ramirez | or2092_hw11_q3.cpp :
#include <iostream>
using namespace std;

int minValue(int a, int b);
//Given two int values, returns the min
int minInArray1(int arr[], int arrSize);
int minInArray2(int arr[], int low, int high);

int main() {
	int arr[10] = { 9, -2, 14, 12, 3, 6, 2, 1, -9, 15 };
	int res1, res2, res3, res4;

	res1 = minInArray1(arr, 10);
	res2 = minInArray2(arr, 0, 9);
	cout << res1 << "=" << res2 << endl; //should both be -9

	res3 = minInArray2(arr, 2, 5);
	res4 = minInArray1(arr + 2, 4); //arr+2 is equivalent to &(arr[2])
	cout << res3 << "=" << res4 << endl; //should both be 3

	return 0;
}

int minValue(int a, int b) {
	if (a > b)	// if b smaller
		return b;	// return b
	else
		return a;	// otherwise a <= b, so return a
}
int minInArray1(int arr[], int arrSize) {
	int ind = arrSize - 1;
	if (arrSize <= 1)	// Base Case: if array size < 2
		return arr[0];
	else {
		int minV = arr[ind];
		return minValue(minV, minInArray1(arr, arrSize - 1));
	}
}
int minInArray2(int arr[], int low, int high) {
	if (low == high)	// Base Case: low index = high index
		return arr[high];
	else {
		int minV = arr[low];
		return minValue(minV, minInArray2(arr, low + 1, high));
	}
}