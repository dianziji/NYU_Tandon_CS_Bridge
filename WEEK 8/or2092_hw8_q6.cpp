// or2092_hw8_q6.cpp :
#include <iostream>
#include <string>
using namespace std;

// Declarations
bool isDigit(char n);
bool areDigits(string str, int start, int end);
int findDigit(string str, int indStart);
int findSpace(string str, int indStart);
string hideNumbers(string str);

// Constants for checking digits and spaces, and assigning crosses
const char SPACE = ' ', CROSS = 'x';
const int ZERO = '0', NINE = '9';

int main() {
	//Setting up i/o
	string userInput;
	cout << "Please enter a line of text: \n" << endl;
	getline(cin, userInput);
	userInput = hideNumbers(userInput);

	cout << userInput << endl;
	return 0;
}

bool isDigit(char c) {
	// Checks to see if character is within the range of digits using ASCII 
	if (c < ZERO || c > NINE) {
		return false;
	}
	return true;
}

bool areDigits(string str, int start, int end){
	// Runs a loop to check each char of a string is a digit
	// In hindsight, I could do away with isDigit, but the logic works out
	bool noNonNumberSeen = true;
	int k = (start + 1);
	while(noNonNumberSeen == true && (k) < end)
	{
		if (isDigit(str[k]))
			noNonNumberSeen = true;
		else
			noNonNumberSeen = false;
		k++;
	}
	return noNonNumberSeen;
}
int findDigit(string str, int indStart)
{	// Finds a number in the string, starting from the index value given
	for (int i = indStart; i < str.length(); i++)
		if (str[i] >= ZERO && str[i] <= NINE)
			return i;
	return -1;
}
int findSpace(string str, int indStart)
{	// Finds a space within the string, starting from the index value given
	for (int i = indStart; i < str.length(); i++)
		if (str[i] == SPACE)
			return i;
	return -1;
}

string hideNumbers(string str) 
{	// Hides any numbers that are not attached to nondigit characters
	int start = 0, spaceOne, spaceTwo;
	int firstDigit = findDigit(str, start);
	while (firstDigit > 0) {
		if (str[firstDigit - 1] == SPACE) {
			spaceOne = firstDigit - 1;
			spaceTwo = findSpace(str, firstDigit);
			if (areDigits(str, spaceOne, spaceTwo)) {
				for (int i = firstDigit; i < spaceTwo; i++) {
					str[i] = CROSS;
				}
			}
			start = spaceTwo + 1;
			firstDigit = findDigit(str, start);
		}
		else {
			start = findSpace(str, firstDigit);
			firstDigit = findDigit(str, start);
		}
	}
	return str;
}