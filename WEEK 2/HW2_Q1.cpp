#include <iostream>
using namespace std;

const float QUARTER = .25, DIME = .1, NICKEL = .05, PENNY = .01;

int main(){
    int number_of_coins;
    float total_amount = 0;
    
    cout << "Please enter number of coins : \n"
         << "# of quarters: ";
    cin >> number_of_coins;
    total_amount += (number_of_coins * QUARTER); // Adding the amount of money from quarters
    
    cout << "# of dimes: ";
    cin >> number_of_coins;
    total_amount += (number_of_coins * DIME); // Adding the amount of money from dimes

    cout << "# of nickels: ";
    cin >> number_of_coins;
    total_amount += (number_of_coins * NICKEL); // Adding the amount of money from nickels

    cout << "# of pennies: ";
    cin >> number_of_coins;
    total_amount += (number_of_coins * PENNY); // Adding the amount of money from pennies

    cout << "The total is " << static_cast<int>(total_amount) << " dollars and " // casting float into int to get whole dollars
         << (total_amount - static_cast<int>(total_amount)) / PENNY << " cents. \n"; // subtracting whole dollars from total to get cents, and converting to whole cents

    return 0;
}