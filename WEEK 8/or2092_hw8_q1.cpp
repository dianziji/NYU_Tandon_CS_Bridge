// or2092_hw8_q1.cpp :
#include <iostream>
using namespace std;

// Declaring functions
int minInArray(int arr[], int arrSize);
// Given an arr (an array of integers), its logical size (arrSize), and a max value (valueToIndex)
// Returns the minimum value in arr
void printIndices(int arr[], int arrSize, int valueToIndex);
// Given an arr (an array of integers), its logical size (arrSize), and a value (valueToIndex)
// Returns the indices where the value is equal to that of valueToIndex

// Global const
// Basically, INT_MAX, but it hasn't been introduced if I recall correctly.
int MAX_INT = 2147483647;

int main() 
{	
	// Constant for array size, no numbers of the magic kind-- 
	const int MAX_LIMIT = 20;

	// Setting vars
	int arr[MAX_LIMIT], minValue;

	//Getting input
	cout << "Please enter 20 integers separated by a space: ";
	for (int i = 0; i < MAX_LIMIT; i++) {
		cin >> arr[i];
	}

	// Finding the minimum value, and then printing the indices with the value.
	minValue = minInArray(arr, MAX_LIMIT);
	cout << "The minimum value is " << minValue 
		 << ", and it is located in the following indices: "; 
	printIndices(arr, MAX_LIMIT, minValue);
	
	return 0;
}

int minInArray(int arr[], int arrSize) 
{
	// Initially I used another function maxInArray to find the max value within the given array,
	// but that meant giving this function a third parameter which goes against instructions.
	int min = MAX_INT;
	for (int i = 0; i < arrSize; i++) 
	{	// If the element in the array is less than min, min takes on that value
		if (arr[i] < min)
			min = arr[i];
	}
	return min;
}

void printIndices(int arr[], int arrSize, int valueToIndex) 
{
	for (int i = 0; i < arrSize; i++) 
	{	// In this case the value we are indexing is the smallest value of the array
		if (arr[i] == valueToIndex)
			cout << i << " ";
	}
}