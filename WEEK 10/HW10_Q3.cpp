#include <iostream>
#include <vector>
using namespace std;

void printArray(int arr[], int arrSize) {	// for debugging
	for (int i = 0; i < arrSize; i++) {
		cout << arr[i] << " ";
	}
}
void expandArray(int* arr, int& arrSize) {	// expanding an array when the userInput sequence reaches the last slot, but before filling said slot
	int newSize = arrSize * arrSize;
	int* temp = new int[arrSize];
	for (int i = 0; i < arrSize; i++) {
		temp[i] = arr[i];
	}
	arr = temp;
	arrSize = newSize;
	delete[]temp; temp = nullptr;
}
int* createArray(int& arrSize, int& newSize) {	// Prompt + Creating the array
	int i = 0;
	int* arrtemp;
	arrtemp = new int[arrSize];
	int userInput = 0;
	cout << "Please enter a sequence of positive integers, each in a separate line.\nEnd your input by typing -1.\n";
	while (userInput != -1) {
		if (i == arrSize - 1) {
			expandArray(arrtemp, arrSize);
		}

		cin >> userInput;
		if (userInput != -1) {
			arrtemp[i++] = userInput;
		}
	}
	newSize = i;
	return arrtemp;
}
void minimizeArray(int* arr, int& arrSize, int newSize) { // To get rid of garbage after expanding and array, or creating one with somewhat-arbitrary size
	int* temp = new int[newSize];
	for (int i = 0; i < newSize; i++) {
		temp[i] = arr[i];
	}
	arrSize = newSize;
	arr = temp;
	delete[]temp; temp = nullptr;
}
void printNumLines(int arr[], int arrSize, int numberToIndex) { // Prompt + 
	int numOfLocations = 0;
	int* temp = new int[arrSize];
	for (int i = 0; i < arrSize; i++) {
		temp[i] = 0;
	}
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] == numberToIndex)
			temp[numOfLocations++] = i + 1;	// if found in arr[i], shows in line (i + 1)
	}
	minimizeArray(temp, arrSize, numOfLocations); // creating an array of size numOfLocations, and changing arrSize to numOfLocations
	if (arrSize > 0) {
		cout << numberToIndex << " shows in line(s) ";
		for (int i = 0; i < arrSize; i++) {
			if (i == arrSize - 1)
				cout << temp[i] << ".";
			else
				cout << temp[i] << ", ";
		}
	}
	else {
		cout << numberToIndex << " does not show at all in the sequence.";
	}
	delete[]temp; temp = nullptr;
}
void main1() {
	int arrSize = 5, i = 0;
	int* arr = createArray(arrSize, i);
	minimizeArray(arr, arrSize, i);
	//printArray(arr, arrSize);
	int numSearch = 0;
	cout << "Please enter a number you want to search.\n";
	cin >> numSearch;
	printNumLines(arr, arrSize, numSearch);
}
void createSequence(vector<int>& userSequence) {
	int userInput = 0;

	cout << "Please enter a sequence of positive integers, each in a separate line. \nEnd your input by typing -1.\n";
	while (userInput != -1) {
		cin >> userInput;
		userSequence.push_back(userInput);
	}

}
void numSearch(vector<int> list) {
	int numToSearch = 0;
	vector<int> numLocation;

	cout << "Please enter a number you want to search: \n";
	cin >> numToSearch;
	for (int i = 0; i < list.size(); i++) {
		if (list[i] == numToSearch)
			numLocation.push_back(i + 1);	// line = index + 1
	}

	if (numLocation.size() > 0) {	// If the number is found at least once
		cout << numToSearch << " shows in line(s) ";
		for (int i = 0; i < numLocation.size(); i++) {
			if (i == numLocation.size() - 1)
				cout << numLocation[i] << ".";	// If its the last element
			else
				cout << numLocation[i] << ", ";
		}
	}
	else
		cout << numToSearch << " does not show at all in the sequence.";
}
void main2() {
	vector<int> userSequence; // Yay for vectors--
	createSequence(userSequence);	// User inputs their sequence
	numSearch(userSequence);	// User inputs number to search
}

int main() {
	cout << "Main 1: \n";
	main1();

	cout << "\n\nMain 2:\n";
	main2();

	return 0;
}