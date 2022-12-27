#include <iostream>
using namespace std;

void printArray(int arr[], int arrSize){
	for (int i = 0; i < arrSize; i++) {
		cout << arr[i] << " ";
	}
}
void oddsKeepEvensFlip(int arr[], int arrSize) {
	int index = 0;
	int* tempArr = new int[arrSize];
	for (int i = 0; i < arrSize; i++) { // Filling tempArr with the odd #s
		if ((arr[i] % 2) != 0){
			tempArr[index] = arr[i];
			index++;
		}
	}
	for (int i = arrSize - 1; i >= 0; i--) { // Filling tempArr with the remaining evens #s
		if ((arr[i] % 2) == 0){
			tempArr[index] = arr[i];
			index++;
		}
	}
	for (int i = 0; i < arrSize; i++) { // Replacing elements in the mainArr
		arr[i] = tempArr[i];
	}
	delete[]tempArr;
	tempArr = NULL;
}
int main(){
	int arrSize;
	cout << "Please enter the number of integer items: \n";
	cin >> arrSize;

	int* mainArr = new int[arrSize];
	cout << "Please enter " << arrSize << " integers, separated by spaces: \n";
	for (int i = 0; i < arrSize; i++) {
		cin >> mainArr[i];
	}

	oddsKeepEvensFlip(mainArr, arrSize);
	printArray(mainArr, arrSize);

	delete[] mainArr;
	mainArr = NULL;

	return 0;
}