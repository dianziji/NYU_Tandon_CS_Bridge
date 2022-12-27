#include <iostream>
#include <vector>
using namespace std;

void printVector(const vector<int>& v);
void printMinMaxVector(const vector<int>& v);
void findMinMax(const vector<int>& v, vector<int>& minMaxVector, const int& lowLeft, const int& highLeft, const int& highRight);
void minMaxRecursive(const vector<int>& v, vector<int>& minMaxVector, const int& low, const int& high);

int main() {
    // I'm sure my test cases won't catch my mistakes as well as yours :')
    // BaseCases =========================================================================================
    vector<int> baseCaseOne = {};                                       // Empty vector
    vector<int> minMaxVectorB1 = {};        

    vector<int> baseCaseTwo = { 3 };                                    // 1 value  | min =  3  | max =  3   
    vector<int> minMaxVectorB2 = {};        

    vector<int> baseCaseThree = { 6, 9 };                               // 2 values | min =  6  | max =  9
    vector<int> minMaxVectorB3 = {};   

    // TestCases =========================================================================================
    vector<int> testOne = { 5, 3, 1, 6, 4, 2 };                         // 6 values | min =  1  | max =  6
    vector<int> minMaxVectorOne = {};  

    vector<int> testTwo = { 7, 8, 2, 3 };                               // 6 values | min =  2  | max =  8
    vector<int> minMaxVectorTwo = {};  

    vector<int> testThree = { 8, 4, 10, 2, 3, 0, 5, 6 };                // 6 values | min =  0  | max = 10
    vector<int> minMaxVectorThree = {};      

    vector<int> testFour = { -1, 4, 6, 7, 9, 5, 11 };                   // 7 values | min = -1  | max = 11
    vector<int> minMaxVectorFour = {};   

    vector<int> testFive = { 7, 6, 18, 12, 9, 8, 14, 5, 4, 2, 6, 4 };   // 7 values | min =  2  | max = 18
    vector<int> minMaxVectorFive = {};      

    //====================================================================================================
    printVector(baseCaseOne);
    minMaxRecursive(baseCaseOne, minMaxVectorB1, 0, baseCaseOne.size());
    printMinMaxVector(minMaxVectorB1);
    cout << endl;

    printVector(baseCaseTwo);
    minMaxRecursive(baseCaseTwo, minMaxVectorB2, 0, baseCaseTwo.size());
    printMinMaxVector(minMaxVectorB2);
    cout << endl;

    printVector(baseCaseThree);
    minMaxRecursive(baseCaseThree, minMaxVectorB3, 0, baseCaseThree.size());
    printMinMaxVector(minMaxVectorB3);
    cout << endl;

    printVector(testOne);
    minMaxRecursive(testOne, minMaxVectorOne, 0, testOne.size());
    printMinMaxVector(minMaxVectorOne);
    cout << endl;

    printVector(testTwo);
    minMaxRecursive(testTwo, minMaxVectorTwo, 0, testTwo.size());
    printMinMaxVector(minMaxVectorTwo);
    cout << endl;

    printVector(testThree);
    minMaxRecursive(testThree, minMaxVectorThree, 0, testThree.size());
    printMinMaxVector(minMaxVectorThree);
    cout << endl;

    printVector(testFour);
    minMaxRecursive(testFour, minMaxVectorFour, 0, testFour.size());
    printMinMaxVector(minMaxVectorFour);
    cout << endl;

    printVector(testFive);
    minMaxRecursive(testFive, minMaxVectorFive, 0, testFive.size());
    printMinMaxVector(minMaxVectorFive);

    return 0;
}
void printVector(const vector<int>& v) {
    if (v.size() > 0) { // To avoid the extra line output by passing empty vectors
        for (int i : v)
            cout << i << ' ';
        cout << endl;
   }
}
// To be used with the min/max vector output from the recursive function
// Assumes that the first index (0) is the minimum value, and the second (1) is the maximum value
void printMinMaxVector(const vector<int>& v) {
    if (v.size() == 0) 
        cout << "Vector is empty. Minimum and maximum values N/A.\n";
    else if (v.size() == 1) // if 1 element, min = max
        cout << "Minimum and maximum value: " << v[0] << endl;
    else {  
        cout << "Minimum value: " << v[0] << '\t' << "Maximum value: " << v[1] << endl;
    }
}
void findMinMax(const vector<int>& v, vector<int>& minMaxVector, const int& lowLeft, const int& highLeft, const int& highRight) {
    int min, max;
    int lowRight, iRight, iLeft, iRes;

    lowRight = highLeft + 1;
    iLeft = lowLeft;
    iRight = lowRight;
    min = max = v[lowLeft];

    while (iLeft < iRight) {
        if (v[iLeft] < min) {
            min = v[iLeft];
        }
        if (v[iLeft] > max) {
            max = v[iLeft];
        }
        iLeft++;
    }
    while (iRight < v.size()) {
        if (v[iRight] < min) {
            min = v[iRight];
        }
        if (v[iRight] > max) {
            max = v[iRight];
        }
        iRight++;
    }
    minMaxVector.push_back(min);
    minMaxVector.push_back(max);
}
void minMaxRecursive(const vector<int>& v, vector<int>& minMaxVector, const int& low, const int& high) {
    int midIndex;

    if (v.size() == 0) {        // if empty, return
        return;
    }
    else if (v.size() == 1) {   // if 1 element, min = max
        minMaxVector.push_back(v[0]);
        return;
    }
    else if (v.size() == 2) {   // if 2, smaller -> [0], larger -> [1]
        if (v[0] < v[1]) {
            minMaxVector.push_back(v[0]);
            minMaxVector.push_back(v[1]);
        } else {
            minMaxVector.push_back(v[1]);
            minMaxVector.push_back(v[0]);
        }
    }
    else {                      // otherwise
        if (low == high)
            return;
        else {
            midIndex = (low + high) / 2;
            minMaxRecursive(v, minMaxVector, low, midIndex);
            minMaxRecursive(v, minMaxVector, midIndex + 1, high);
            findMinMax(v, minMaxVector, low, midIndex, high);
        }
    }
}