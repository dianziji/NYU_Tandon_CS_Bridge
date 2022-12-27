#include <iostream>
using namespace std;

void printArray(int arr[], int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		cout << arr[i] << " ";
	}
}
int* createIntegerSequence(int arrSize) {
	int* temp = new int[arrSize + 1];
	for (int i = 0; i < arrSize; i++)
		temp[i] = i;
	return temp;
}
int* createMemberCount(int arrSize) { // Creates array of 0's, size n+1
	int* temp = new int[arrSize + 1];	// using to tally members in the main array
	for (int i = 0; i <= arrSize; i++)
		temp[i] = 0;
	return temp;
}
int* findMissing(int arr[], int n, int& resArrSize) {
	int missingCount = 0;
	int* count = createMemberCount(n);
	int* integers = createIntegerSequence(n);
	for (int i = 0; i < n; i++) {
		count[arr[i]] += 1;	// tallies the number of times a number appears in the main array to the corresponding location in the count array
	}
	for (int i = 0; i <= n; i++) {
		if (count[i] == 0)
			missingCount++;	// counts the total number of missing integers
	}
	int* missing = new int[missingCount];
	for (int i = 0, j = 0; i <= n; i++) {
		if (count[i] == 0)
			missing[j++] = i;	// adds the missing number to the missing array, increments the index#
	}
	resArrSize = missingCount;
	delete[]count; count = nullptr;
	delete[]integers; integers = nullptr;
	return missing;
}
int main() {
	// Setting up dynamic array input
	int arrSize = 0;
	cout << "Please enter the logical size of the array:\n";
	cin >> arrSize;
	cout << "Please enter " << arrSize << " positive integer(s): \n";
	int* mainArr = new int[arrSize];
	for (int i = 0; i < arrSize; i++) {
		cin >> mainArr[i];
	}

	int resArrSize = 0;
	int* missingNumbers = findMissing(mainArr, arrSize, resArrSize);
	delete[]mainArr; mainArr = nullptr;	// Done with the user array

	cout << "Number of missing integers(resArrSize) = " << resArrSize;
	cout << "\nMissing integer(s): ";
	printArray(missingNumbers, resArrSize);
	cout << endl;


	return 0;
}