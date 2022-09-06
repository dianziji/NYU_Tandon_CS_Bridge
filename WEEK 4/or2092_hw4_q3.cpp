// or2092_hw4_q3.cpp:

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	// Setting variables
	int digit, num, temp, bits = 0;

	// Getting input
	cout << "Enter decimal number: " << endl;
	cin >> num;
	// Starting output
	cout << "The binary representation of " << num << " is ";
	temp = num;

	while (temp > 0) {
		temp /= 2;
		bits++;
	}
	// Accounting for 0 as an input, though a valid positive integer input should be > 0
	if (num != 0) {
		for (int i = bits - 1; i >= 0; i--) {
			int digit = num / int(pow(2, i));
			cout << digit;
			num %= int(pow(2, i));
		}
	}
	else
		cout << num;
	return 0;
}