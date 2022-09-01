// or2092_hw6_q3.cpp

#include <iostream>
using namespace std;

double eApprox(int n);
// Approximates the  value of the mathimatical constant 'e', 
// with increasing accuracy.

int main()
{   // Return sample n = [1,15]
    cout.precision(30);
    for (int n = 1; n <= 15; n++)
    {
        cout << "n = " << n << '\t' << eApprox(n) << endl;
    }
    return 0;
}

double eApprox(int n)
{   // starting with 1, adding 1/n! with each iteration
    double sum = 1, factorial = 1;
    for (int s = 1; s <= n; s++)
    {
        factorial *= s;
        sum += 1.0 / factorial;
    }
    return sum;
}