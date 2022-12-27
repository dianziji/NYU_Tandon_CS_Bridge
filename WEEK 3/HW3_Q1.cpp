#include <iostream>
using namespace std;

const float HALF = .5, MEMBER_DISCOUNT = .9, HUNDY = 100;

int main() {
    // Setting variables
    double firstItemPrice, secondItemPrice, basePrice;
    double subTotal, netTotal, taxRate, tax;
    char clubMember;

    //Getting input
    cout << "Enter price of first item: " << endl;
    cin >> firstItemPrice;
    cout << "Enter price of second item: " << endl;
    cin >> secondItemPrice;
    cout << "Does customer have a club card? (Y/N): " << endl;
    cin >> clubMember;
    cout << "Enter tax rate, e.g., 5.5 for 5.5% tax: " << endl;
    cin >> taxRate;

    // Base/initial net price
    basePrice = firstItemPrice + secondItemPrice;

    if (firstItemPrice > secondItemPrice)
        subTotal = firstItemPrice + (secondItemPrice * HALF);
    else
        subTotal = (firstItemPrice * HALF) + secondItemPrice;

    // Club card discount
    if (clubMember == 'Y' || clubMember == 'y')
        subTotal *= MEMBER_DISCOUNT;

    taxRate /= HUNDY;   //converting percent to decimal
    tax = subTotal * taxRate;
    netTotal = subTotal + tax;

    cout << "Base price: " << basePrice << endl;
    cout << "Price after discounts: " << subTotal << endl;
    cout << "Total price: " << netTotal << endl;

    return 0;
}