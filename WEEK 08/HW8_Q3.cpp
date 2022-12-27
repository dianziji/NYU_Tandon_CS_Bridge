#include <iostream>
using namespace std;

void reverseArray(int arr[], int arrSize);
// Given an array (arr) and its size (arrSize)
// Reverses the order of the items in the array
void removeOdd(int arr[], int& arrSize);
// Given an array (arr) and its size (arrSize)
// Removes odd elements, and updates the size with the remaining number of even items
void splitParity(int arr[], int& arrSize);
// Given an array (arr) and its size (arrSize)
// Changes the order of the array so that all odd numbers come before the even numbers
void printArray(int arr[], int arrSize);
// Given an array (arr) and its size (arrSize)
// Prints each item in line

int main() {
	// Leaving the main program incase I accidentally delete a ) again...
	int arrOne[5] = { 9, 2, 14, 12, -3 };
	int arrOneSize = 5;

	int arrTwo[5] = { 21, 12, 6, 7, 14 };
	int arrTwoSize = 5;

	int arrThree[5] = { 3, 6, 4, 1, 21 };
	int arrThreeSize = 5;

	printArray(arrOne, arrOneSize); // b4
	reverseArray(arrOne, arrOneSize);
	printArray(arrOne, arrOneSize); // after

	cout << "\n";

	printArray(arrTwo, arrTwoSize); // b4
	removeOdd(arrTwo, arrTwoSize);
	printArray(arrTwo, arrTwoSize); // after

	cout << "\n";

	printArray(arrThree, arrThreeSize); // b4
	splitParity(arrThree, arrThreeSize);
	printArray(arrThree, arrThreeSize); // after

	return 0;
}

void reverseArray(int arr[], int arrSize) {
	for (int i = 0, j = arrSize - 1; i < arrSize / 2; i++, j--) {
		int p = arr[i];
		arr[i] = arr[j];
		arr[j] = p;
	}
}
void removeOdd(int arr[], int& arrSize) {
	int count = 0;
	for (int i = 0, j = 0; j < arrSize; j++) {
		if (arr[j] % 2 == 0) {
			arr[i] = arr[j];
			i++;
			count++;
		}
	}
	arrSize = count;
}
void splitParity(int arr[], int& arrSize) { // Swaps if even
	for (int i = 0, j = arrSize - 1; i < arrSize; i++, j--) {
		if (i >= j) {
			break;
		}
		else if (arr[i] % 2 == 1 && arr[j] % 2 == 1) {
			j++;
		}
		else if (arr[i] % 2 == 0 && arr[j] % 2 == 0) {
			i--;
		}
		else if (arr[i] % 2 == 0 && arr[j] % 2 == 1) {
			int p = arr[i];
			arr[i] = arr[j];
			arr[j] = p;
		}
	}
}
void printArray(int arr[], int arrSize) {
	for (int i = 0; i < arrSize; i++)
		cout << arr[i] << ' ';
	cout << endl;
}