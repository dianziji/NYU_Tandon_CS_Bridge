// or2092_hw5_q1.cpp:
#include <iostream>
using namespace std;

int main(){
    int num;                                        // Setting Variables
    
    cout << "Please enter a positive integer: ";    // Getting input
    cin >> num;

    for (int x = 1; x <= num; x++) {                // Row
        for (int y = 1; y <= num; y++)               // Column
            cout << x * y << "\t";
        cout << endl;
    }
    return 0;
}