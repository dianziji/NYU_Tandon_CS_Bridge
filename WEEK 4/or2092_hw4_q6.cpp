// or2092_hw4_q6.cpp

#include <iostream>
using namespace std;

int main(){
	// Setting Variables
	int n, currNum;
	int evenCount = 0, oddCount = 0;
	
	// Getting input
	cout << "Please enter a positive integer: " << endl;
	cin >> n;

	// Counting Loop
	for (int i = 1; i <= n; i++) {
		currNum = i;

		// Counting odd/even Loop
		for (int numOfDigits = 1; currNum > 0; numOfDigits++) {
			if (currNum % 2 == 0) {
				evenCount++;
			}
			else {
				oddCount++;
			}
			currNum /= 10;
		}

		// Printing i iff even digits > odd digits
		if (evenCount > oddCount) {
		cout << i << endl;
		}

		// Resetting counts
		oddCount = 0;
		evenCount = 0;
	}
		
	return 0;
}