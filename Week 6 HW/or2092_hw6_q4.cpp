// or2092_hw6_q4.cpp

#include <iostream>
using namespace std;

void printDivisors(int num);
// Given a positive integer num, 
// prints all of num's divisors in an ascending order
// separated by spaces.

int main()
{
    // Setting up user input retrieval.
    int userInput;
    cout << "Please enter a positive integer >= 2: ";
    cin >> userInput;

    // Calling the function using user input.
    printDivisors(userInput);
}

void printDivisors(int num)
{    
    for (int d = 1; d < sqrt(num); d++)     // Finds divisors up until sqrt(n)
    {
        if (num % d == 0) 
        {
            cout << d << " ";
        }
    }
    for (int d = sqrt(num); d > 0; d--) {   // Finds divisors from sqrt(n) to n

        if (num % d == 0)
            cout << num / d << " ";
    }    
}