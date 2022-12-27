#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void obfuscateArray(int arr[], int arrSIZE);
void printArray(int arr[], int arrSize);
bool authenticate(int arr[], int arrSize, const int pin[], int pinSize, int userInput);

int main() {
	// Constants and Variables
	const int ARR_SIZE = 10, PIN_SIZE = 5; 
	const int PIN[PIN_SIZE] = {1, 0, 4, 6, 0};
	srand((time(0)));
	int userInput, arr[ARR_SIZE];
	obfuscateArray(arr, ARR_SIZE);

	// Setting up prompt and input
	cout << "Please enter your PIN according to the following mapping:\n"
		 << "PIN:\t0 1 2 3 4 5 6 7 8 9\n"
		 << "NUM:\t";
	printArray(arr, ARR_SIZE);
	cin >> userInput;
	
	// Authenticating predetermined pin with 
	if (authenticate(arr, ARR_SIZE, PIN, PIN_SIZE, userInput))
		cout << "Your PIN is correct\n";
	else
		cout << "Your PIN is not correct\n";
	
	return 0;
}

void obfuscateArray(int arr[], int arrSIZE){	
	// Creating an array with 10 randomized elements in range [1,3]
	for (int i = 0; i < arrSIZE; i++) {
		arr[i] = (rand() % 3) + 1;
	}
}
void printArray(int arr[], int arrSize){	
	// Prints the array
	for (int i = 0; i < arrSize; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}
bool authenticate(int arr[], int arrSize, const int PIN[], int pinSize, int userInput){	
	// Compares each digit to the corresponding element in the randomized/obfuscated array
	int userDigit, pinDigit;
	pinSize -= 1;
	while (userInput > 0) {
		userDigit = userInput % 10;
		pinDigit = PIN[pinSize];
		if (userDigit != arr[pinDigit])
			return false;
		pinSize -= 1;
		userInput /= 10;
	}
	return true;
}