// or2092_hw7_q2.cpp
#include <iostream>
#include <cmath>
using namespace std;

// Declaring functions
void analyzeDividors(int num, int& outCountDivs, int& outSumdivs);
bool isPerfect(int num);


int main()
{   // Setting up user input, and temp variables
    int userNum;
    int divCount, divSum;
    int firstSum, secondSum;
    cout << "Please enter an integer that is 2 or greater: ";
    cin >> userNum;
    
    // Outputs the perfect numbers between 2 and userNum
    cout << "\nThe perfect numbers in range [2, " << userNum << "] are:\n";
    for (int num = 2; num <= userNum; num++)
    {
        if (isPerfect(num) == true)
            cout << num << "\n";
    }

    // Outputs the amicable pairs between 2 and userNum
    cout << "\nThe pairs of amicable numbers in range [2, " << userNum << "] are:\n";
    for (int i = 2; i <= userNum; i++)
    {
        int count = 0, firstSum = i, secondSum = 0;
        analyzeDividors(i, divCount, firstSum);

        if (firstSum > i && firstSum <= userNum)
        {
            analyzeDividors(firstSum, divCount, secondSum);
            if (secondSum == i)
            {
                cout << secondSum << " and " << firstSum << "\n";
            }
        }
    }
    return 0;
}

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs)
{   // Finds proper divisors
    int divCountOne = 0, divCountTwo = 0, divSumOne = 0, divSumTwo = 0;
    for (int div = 1; div <= sqrt(num); div++)
    {   // Divisors from 1 to sqrt(n)
        if (num % div == 0)
        {
            divCountOne++;
            divSumOne += div;
        }
    }
    for (int div = sqrt(num); div > 1; div--)
    {   //divisors from sqrt(n) to n
        if (num % div == 0)
        {
            divCountOne++;
            divSumOne += (num / div);
        }
    }
    // sends out an updated divisor count and sum
    outCountDivs = divCountOne;
    outSumDivs = divSumOne;
}
bool isPerfect(int num)
{   // Checks for perfect numbers, i.e., if the number is equal to the sum of its proper divisors
    int countDivs = 0, sumDivs = 0;
    analyzeDividors(num, countDivs, sumDivs);
    if (sumDivs == num)
        return true;
    else
        return false;
}
