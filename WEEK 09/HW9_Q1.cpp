#include <iostream>
#include <string>
using namespace std;

// Determines if the character is a letter
bool isAlpha(char c) { 
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return true;
	else
		return false;
}
// Given a string, returns all lower-case letters
void smallCase(string& str) {
	int bigCase = 'A', smallCase = 'a';
	int caseDiff = smallCase - bigCase;
	for (int index = 0; index < str.length(); index++) {
		if (str[index] >= 'A' && str[index] <= 'Z') {
			int caseDiff = 'a' - 'A';
			str[index] += caseDiff;
		}
	}
}
// Takes in a string, and an array representing the alphabet
void countInOrder(string str, int alphaArr[], int arrSize) {
	int wordCount = 0;
	// Assuming input from prompt, white space/punctuation != letter
	for (int index = 0; index < str.length(); index++) {
		if ((isAlpha(str[index]) == true) && (isAlpha(str[index + 1]) == false)) {
			wordCount++;
		}
	}
	cout << wordCount << "\tWords" << endl;

	// If letter occurs in str, adds 1 to the corresponding index# in alphabet[]
	for (int i = 0; i < str.length(); i++) {
		if (isAlpha(str[i])) {
			alphaArr[str[i] - 'a'] += 1;
		}
	}
	// If the value in the array is > 0; (if the letter appears in the string)
	char start = 'a';
	for (int i = 0; i < arrSize; i++) {
		if (alphaArr[i] > 0) {
			cout << alphaArr[i]  << "\t" << start << endl;
		}
		start++;
	}
}

int main() {
	const int ALPHABET_SIZE = 26;

	// Setting up Input
	string userInput;
	cout << "Please enter a line of text: ";
	getline(cin, userInput);

	// Ensuring lowercase, for ASCII math
	smallCase(userInput);

	// Initializing an array of 26 elements that = 0 for count
	int alphabet[ALPHABET_SIZE] = {};
	countInOrder(userInput, alphabet, ALPHABET_SIZE);

	return 0;
}