// or2092_hw4_q4.cpp: 

#include <iostream>
#include <cmath>
using namespace std;

const float THIRD = 1.0 / 3.0;

int main() {
    // a)   Reading the length of the sequence
    // Setting Variables
    int i;
    float geoMeanA;
    int numOne, numTwo, numThree;

    // Getting input
    cout << "Please enter the length of the sequence: " << endl;
    cin >> i;
    cout << "Please enter your sequence: " << endl;
    cin >> numOne >> numTwo >> numThree;
    

    geoMeanA = pow((numOne * numTwo * numThree), (THIRD));
    cout << "The geometric mean is: " << geoMeanA << "\n" << endl;
   
    // b) Reading until the user inputs -1
    // Setting Variables
    int prod = 1, num = 1;
    int count = 0;
    float geoMeanB;
    
    
    cout << "Please enter a non-empty sequence of positive integers, each one in a separate line.\n"
         << "End your sequence by typing -1:" << endl;
    // Assuming valid input, num > 0. -1 will break the loop.
    while (num > 0){
        cin >> num;
        if (num == -1)
            break;
        else {
            prod *= num;
            count++;
        }
    }

    geoMeanB = pow(prod, (1.0 / count));
    cout << "The geometric mean is: " << geoMeanB;

    return 0;
}