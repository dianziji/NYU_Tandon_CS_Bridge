#include <iostream>
#include <string>
using namespace std;

int main() {
	// Setting variables
	string stringOne, stringTwo, stringThree;

	// Getting input
	cout << "Please enter your full name: \n";
	cin >> stringOne >> stringTwo >> stringThree;

	// If the user inputs Last_Name, we'll leave the input relatively untouched
	if (stringOne.find(",") != string::npos) {
		cout << stringOne << " " << stringTwo << " " << stringThree[0] << "." << endl;
	} // Otherwise, we'll assume its in default First/Middle/Last order and print 3, 1 2.
	else
		cout << stringThree << ", " << stringOne << " " << stringTwo[0] << "." << endl;

	return 0;
}