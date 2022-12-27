#include <iostream>
#include <string>
using namespace std;

bool isAlpha(char c) {	// determining if char is a letter
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return true;
	else
		return false;
}
void giveLowerCase(string& str) {	// Passing a string and assigning all uppercase letters lowercase equivalents
	int upperCase = 'A', lowerCase = 'a';
	int diff = lowerCase - upperCase;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += diff;
	}
}
void alphabetIndexCount(string str, int arr[]) { // Counts each letter in the string, and increases corresponding index by 1
	for (int i = 0; i < str.length(); i++) {
		if (isAlpha(str[i])) {
			arr[str[i] - 'a'] += 1;
		}
	}
}
bool compareArray(int arr1[], int arr2[], int arrSize){ // size of both arrays should be the same
	bool equal = true;
	for (int i = 0; i < arrSize; i++) {
		if (arr1[i] != arr2[i])
			equal = false;
	}
	return equal;
}
int main() {
	// Total letters = 26
	const int ALPHABET_TOTAL = 26;

	// Setting up I/O
	string userStringOne, userStringTwo;
	cout << "Please enter the first string:\n";
	getline(cin, userStringOne);
	cout << "Please enter the second string:\n";
	getline(cin, userStringTwo);

	// Creating two separate arrays to store the alphabet count
	int alphabetArrOne[ALPHABET_TOTAL] = {};
	int alphabetArrTwo[ALPHABET_TOTAL] = {};

	// Getting strings in lowercase
	giveLowerCase(userStringOne);
	giveLowerCase(userStringTwo);

	// Getting alphabet count
	alphabetIndexCount(userStringOne, alphabetArrOne);
	alphabetIndexCount(userStringTwo, alphabetArrTwo);

	// If the letter counts are the same, its an anagram
	if (compareArray(alphabetArrOne, alphabetArrTwo, ALPHABET_TOTAL))
		cout << "\nThe two strings are anagrams.\n";
	else
		cout << "\nThe two strings are not anagrams.\n";

	return 0;
}