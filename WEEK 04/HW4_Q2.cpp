#include <iostream>
#include <string>
using namespace std;

int main() {
	// Setting variables
	int num, tempNum;
	string romanNum, M, D, C, L, X, V, I;

	// Getting input
	cout << "Enter decimal number:" << endl;
	cin >> num;

	// Taking out 1000s
	tempNum = num;
	if (tempNum >= 1000) {
		while (tempNum >= 1000) {
			tempNum -= 1000;
			M += "M";
		}
	}
	// Taking out 500 once
	if (tempNum >= 500) {
		tempNum -= 500;
		D += "D";
	}

	// Taking out 100 remaining
	if (tempNum >= 100) {
		while (tempNum >= 100) {
			tempNum -= 100;
			C += "C";
		}
	}

	// Taking out 50 once
	if (tempNum >= 50) {
		tempNum -= 50;
		L += "L";
	}

	// Taking out 10 remaining
	if (tempNum >= 10) {
		while (tempNum >= 10) {
			tempNum -= 10;
			X += "X";
		}
	}

	//Taking out 5 once
	if (tempNum >= 5) {
		tempNum -= 5;
		V += "V";
	}

	// Taking out 1 remaining
	if (tempNum > 0) {
		while (tempNum >= 1) {
			tempNum -= 1;
			I += "I";
		}
	}

	// Final output
	romanNum = M + D + C + L + X + V + I;
	cout << num << " is " << romanNum << endl;

	return 0;
}