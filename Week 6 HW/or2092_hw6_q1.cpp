// or2092_hw6_q1.cpp
#include <iostream>
using namespace std;

int fib(int n);
// returns the n-th element of the fibonacci sequence

int main(){
	// Prompt for user input
	int num;
	cout << "Please enter a positive integer: ";
	cin >> num;

	// Output
	cout << fib(num) << endl;

	return 0;
}

int fib(int n)
{	// Assuming input range [0,inf)
	int sum = 0, fN_2 = 1, fN_1 = 1;
	if (n < 1)		// for n = 0
		return 0;
	else if (n >= 1 && n < 3)
		return 1;	// for n = 1 and n = 2
	else 
	{
		for (int i = 0; i < n - 2; i++)
		{	// fN_2 represents f(n-2), fN_1 represents f(n-1)
			sum = fN_2 + fN_1;
			fN_2 = fN_1;
			fN_1 = sum;
		}
		return sum;
	}
}
