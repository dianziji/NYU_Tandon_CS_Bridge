#include <iostream>
using namespace std;

const double QUARTER = .25, DIME = .1, NICKEL = .05, PENNY = .01;

int main()
{

    int dollars, cents, numOfQuarters, numOfDimes, numOfNickels, numOfPennies;
    double totalAmount;

    cout << "Please enter your amount in the format of dollars and cents, separated by a space:\n";
    cin >> dollars >> cents;

    totalAmount = dollars + (cents * PENNY);
    
    cout << totalAmount << '\n';

    numOfQuarters = totalAmount / QUARTER;
    totalAmount -= (numOfQuarters * QUARTER);

    numOfDimes = totalAmount / DIME;
    totalAmount -= (numOfDimes * DIME);

    numOfNickels = totalAmount / NICKEL;
    totalAmount -= (numOfNickels * NICKEL);

    numOfPennies = totalAmount / PENNY;
    totalAmount -= (numOfPennies * PENNY);

    cout << dollars << " dollars and " << cents << " cents are:\n";
    cout << numOfQuarters << " quarter(s), ";
    cout << numOfDimes << " dime(s), ";
    cout << numOfNickels << " nickel(s), and ";
    cout << numOfPennies << " penny/pennies\n";

    return 0;
}