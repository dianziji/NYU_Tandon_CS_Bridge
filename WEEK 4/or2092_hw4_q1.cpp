#include <iostream>
using namespace std;

int main() {
	// Setting variables
	int n, limit = 1;

	// While loop
	cout << "a) Using a while loop" << endl;
	// Getting input
	cout << "Please enter a positive integer: ";
	cin >> n;

	while (limit <= n) {
		cout << limit * 2 << endl;
		limit++;
	}

	// For loop
	cout << "b) Using a for loop" << endl;
	// Getting input
	cout << "Please enter a positive integer: ";
	cin >> n;

	for (limit = 1; limit <= n; limit++)
		cout << limit * 2 << endl;

	return 0;
}