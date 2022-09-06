// or2092_hw4_q5.cpp: 

#include <iostream>
using namespace std;

int main() {
    // Setting variables
    int n;

    // Getting input
    cout << "Please enter a positive integer: " << endl;
    cin >> n;

    // Top Half 
    // Row loop
    for (int row = n; row > 0; row--) {

        //Column loop
        for (int column = (2 * n - 1); column > 0; column--) {
            if (column >= (n - (row - 1)) && column <= (n + (row - 1)))
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }

    // Bottom Half 
    // Row loop
    for (int row = 1; row <= n; row++) {

        //Column loop
        for (int column = 1; column <= (2 * n - 1); column++) {
            if (column >= (n - (row - 1)) && column <= (n + (row - 1)))
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}