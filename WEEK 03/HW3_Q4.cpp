#include <iostream>
using namespace std;

int main() {
    // Init
    const int FLOOR_ROUND = 1, CEILING_ROUND = 2, ROUND = 3;
    const int ONE = 1;
    float num;
    int roundMethod, intNum;

    // Input
    cout << "Please enter a Real number: " << endl;
    cin >> num;
    cout << "Choose your rounding method: \n1.Floor round \n2.Ceiling round \n3.Round to the nearest whole number" << endl;
    cin >> roundMethod;

    intNum = (int)num; // base line

    switch (roundMethod) {
    case FLOOR_ROUND:
        if (num >= 0)
            cout << intNum << endl;
        else
            cout << intNum - 1 << endl;
        break;
    case CEILING_ROUND:
        if (num >= 0)
            cout << intNum + 1 << endl;
        else
            cout << intNum << endl;
        break;
    case ROUND:
        if (num >= 0) {
            if ((num - intNum) < .5)   // If the decimal portion is < .5 we round towards 0.
                cout << intNum << endl;
            else                        // Otherwise, it must be >= .5 we round away from 0.
                cout << intNum + 1 << endl;
        }
        else {
            if (((num - intNum) * -1) < .5) // If the decimal portion is < -.5 we round away from 0.
                cout << intNum << endl;
            else                               // Otherwise, it's >= -.5 and we round towards 0.
                cout << intNum - 1 << endl;
        }
        break;
    default:
        cout << "You've entered an invalid number." << endl;
        break;
    }
    return 0;
}