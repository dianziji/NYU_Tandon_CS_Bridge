// Oscar Ramirez | or2092_hw11_q2.cpp : 
#include <iostream> 
using namespace std;

int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);

int main() {
	const int arrSize = 4;
	int arr[4] = { 2, -1, 3, 10 };	// Unsorted array, should print 114
	//int arr2[4] = { 1, 2, 3, 4 };	// Sorted array, should print 30
	//int arr3[4] = {5, 2, 7, -3};	// Unsorted array, should print 87
	//int arr4[4] = { 3, 3, 5, 5};	// Sorted, should print 68

	cout << sumOfSquares(arr, arrSize) << endl;
	if (isSorted(arr, arrSize))
		cout << "The array is sorted!" << endl;
	else
		cout << "The array is not sorted!" << endl;

	return 0;
}

int sumOfSquares(int arr[], int arrSize) {
	int ind = arrSize - 1;
	if (arrSize <= 0)	// base case: in the event that the set is empty
		return 0;
	else if (arrSize == 1) // or has a single element
		return arr[0] * arr[0];	
	else {
		return sumOfSquares(arr, ind) + (arr[ind] * arr[ind]);	//recursive call, otherwise
	}
}

bool isSorted(int arr[], int arrSize) {
	int ind = arrSize - 1;
	if (arrSize < 2)	// base case, less than 2 elements = sorted. Empty and single element sets are sorted.
		return true;
	if (arr[ind - 1] < arr[ind - 2])	// n <= n + 1 for all n
		return false;
	return isSorted(arr, arrSize - 1);
}
