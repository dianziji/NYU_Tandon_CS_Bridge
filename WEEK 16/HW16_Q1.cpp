#include <iostream>
#include <fstream>
#include <string>
#include <stack>
using namespace std;

void openInputFile(ifstream& inFile);
// Given a container variable of type ifstream, 
// connects the program to the file named by the user
bool symbolBalanceChecker(ifstream& inFile);
// Given a file to read
// Checks to see that all square brackets, parentheses, and curly braces match
void findBegin(ifstream& inFile);
// Given a file to read
// Leaves the pointer after the first instance of "begin"
bool isUpper(char c);
// Checks to see if c is an upper case Letter
string lowerCase(const string& str);
// Given a string, returns a copy with all lower case letters

const char startingBrace = '{', startingBracket = '[', startingParenthesis = '(';
const char endingBrace = '}',	endingBracket = ']', endingParenthesis = ')';
// For mine own sake.

int main() {
	ifstream inFile;			// intialize
	openInputFile(inFile);		// open/connect
	findBegin(inFile);			// point to after "begin"

	if (symbolBalanceChecker(inFile))	// check if symbols are balanced
		cout << "File IS balanced.";
	else
		cout << "File IS NOT balanced.";

	return 0;
}

void openInputFile(ifstream& inFile) {
	string filename;
	char ans;
	cout << "Please enter the file name: ";
	cin >> filename;
	inFile.open(filename);
	while (!inFile) {
		cout << filename << " has failed to open. Would you like to try another file name? (Y/N): ";
		cin >> ans;
		if (ans == 'n' || ans == 'N')
			exit(1);
		cout << "Please enter the file name: ";
		cin >> filename;
		inFile.clear();
		inFile.open(filename);
	}

}
bool isUpper(char c) {
	return (c >= 65 && c <= 90);
}
string lowerCase(const string& str) {
	if (str.length() == 0)
		return str;
	string temp;
	char up = 'A', low = 'a';
	int diff = up - low;
	for (int i = 0; i < str.length(); i++) {
		if (isUpper(str[i]))
			temp += str[i] - diff;
		else
			temp += str[i];
	}
	return temp;
}
void findBegin(ifstream& inFile) {
	string start;
	while (inFile >> start) {
		lowerCase(start);	
		if (start == "begin")	
			return;				
	}
	cout << "File does not contain begin." << endl;
	exit(1);
}
bool symbolBalanceChecker(ifstream& inFile) {
	stack<char> symbols;
	string currentStr;
	while (inFile >> currentStr) {
		if (lowerCase(currentStr) == "end") {
			break;
		}
		for (int i = 0; i < currentStr.length(); i++) {
			if (currentStr[i] == startingBrace || currentStr[i] == startingBracket
			|| currentStr[i] == startingParenthesis) {
				symbols.push(currentStr[i]);
			}
			else if ((currentStr[i] == endingBrace && symbols.top() == startingBrace)
			|| (currentStr[i] == endingBracket && symbols.top() == startingBracket)
			|| (currentStr[i] == endingParenthesis && symbols.top() == startingParenthesis)) {
				symbols.pop();
			}
			else if ((currentStr[i] == endingBrace && symbols.top() != startingBrace)
			|| (currentStr[i] == endingBracket && symbols.top() != startingBracket)
			|| (currentStr[i] == endingParenthesis && symbols.top() != startingParenthesis)){
				return false;
			}
		}
	}
	if (symbols.size() == 0) // if balanced, stack size should = 0
		return true;
	else					 // otherwise the stack could have open(s) without matching close(s)
		return false;
}