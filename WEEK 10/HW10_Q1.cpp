#include <iostream>
#include <string>
using namespace std;

bool isNotSymbol(char c) {		// I didn't want to exclude words with hyphens or apostrophes either
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == ' ' || c == '\'' || c == '-');
}
string removeSymbols(string str) {
	int newSize = 0;
	int notSymbol = 0;
	for (int i = 0; i < str.length(); i++) {
		if (isNotSymbol(str[i]) || str[i] == ' ')
			newSize++;
	}
	string temp = "";
	for (int i = 0; i <= newSize; i++) {
		if (isNotSymbol(str[i]) || str[i] == ' ')
			temp += str[i];
	}
	return temp;
}
int wordCount(string str) {
	int numOfSpaces = 0;
	unsigned int start = 0;
	while (str.find(' ', start) != string::npos) {
		numOfSpaces++;
		start = (str.find(" ", start) + 1);
	}
	if (str[0] == ' ')	// Accounts for a string whose first character is a space;
		numOfSpaces--;
	return numOfSpaces + 1;
}
string* createWordsArray(string sentence, unsigned int& outWordsArrSize) {
	outWordsArrSize = wordCount(sentence);
	string word = "";
	unsigned int wordEnd = 0, wordStart = 0, wordArrInd = 0;
	outWordsArrSize = wordCount(sentence);
	string* temp = new string[outWordsArrSize];
	for (int i = 0; i < outWordsArrSize; i++) {
		if (sentence.find(' ', wordStart) != string::npos) {
			wordEnd = sentence.find(' ', wordStart);
			word = sentence.substr(wordStart, (wordEnd - wordStart));
			temp[wordArrInd] = word;
			wordArrInd++;
			wordStart = wordEnd + 1;
		}
		else {
			word = sentence.substr(wordStart, (sentence.length() - wordStart));
			temp[wordArrInd] = word;
		}
	}
	return temp;
}
void printWords(string str[], int strSize) {
	cout << "Words: ";
	for (int i = 0; i < strSize; i++) {
		cout << str[i] << " ";
	}
	cout << endl;
}
void printStringArrayPrompt(string str[], int arrSize) {
	cout << "Words Array: ";
	for (int i = 0; i < arrSize; i++) {
		if (arrSize == 1)
			cout << "[\"" << str[i] << "\"]";
		else if (i == 0)
			cout << "[\"" << str[i] << "\", ";
		else if (i == arrSize - 1)
			cout << "\"" << str[i] << "\"]" << endl;
		else
			cout << "\"" << str[i] << "\", ";
	}
}
int main() {
	// Input
	unsigned int wordCount;
	string sentence = "";
	cout << "Please enter a sentence: ";
	getline(cin, sentence);

	// Remove symbols, if any, and split words within the string
	string cleanSentence = removeSymbols(sentence);
	string* sentenceArr = createWordsArray(cleanSentence, wordCount);
	
	// Output
	cout << "Word Count: " << wordCount << endl;
	printWords(sentenceArr, wordCount);
	printStringArrayPrompt(sentenceArr, wordCount);

	return 0;
}