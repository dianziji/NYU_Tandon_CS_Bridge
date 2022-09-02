// or2092_hw8_q2.cpp :
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str);
// Given a string str containing a word
// Returns true if and only if str is a palindrome

int main() {
	// Setting up I/O
	string userStr;
	cout << "Please enter a word: \n";
	cin >> userStr;

	if (isPalindrome(userStr))
		cout << userStr << " is a palindrome";
	else
		cout << userStr << " is not a palindrome";
	return 0;
}


bool isPalindrome(string str)
{
	string reversedStr = "";
	for (int i = str.length() - 1; i >= 0; i--)
	{	// Concatenating the elements of the string from right to left
		reversedStr += str[i];
	}
	if (str == reversedStr) // If the word is the same backwords
		return true;
	else
		return false;
}