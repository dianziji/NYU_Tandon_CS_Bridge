#include <iostream>
using namespace std;

int jumpIt(int arr[], int arrSize);
int min(int a, int b);

int main() {
    //int arr[8] = {0, 3, 80, 6, 57, 10, 18, 27}; // test case 1 -> 46
    //int arr[8] = { 0, 56, 55, 54, 53, 52, 51, 50 }; // test case 2 -> 209
    //int arr[8] = { 0, 50, 51, 52, 53, 54, 55, 56 }; // test case 3  -> 212


    //cout << jumpIt(arr, arrSize) << "\n" << endl; // should output 19

    //cout << jumpIt(arr, 6); // should output 37
    //cout << jumpIt(arr, 8); // should output 37

    //cout << "Cheapest path = " << jumpIt(arr, 8) << endl;
    return 0;
}

int jumpIt(int arr[], int arrSize) {
    if (arrSize <= 3)
        return arr[arrSize - 1];
    return min(jumpIt(arr, arrSize - 1), jumpIt(arr, arrSize - 2)) + arr[arrSize - 1];
}
int min(int a, int b) {
    return (a < b) ? a : b;
}
