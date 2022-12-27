// Oscar Ramirez | or2092_hw11_q1.cpp :
#include <iostream>
using namespace std;

const char star = '*', mark = '-';  // For my own sanity

void printTriangle(int n);
void printOppositeTriangles(int n);
void printRuler(int n);

int main(){
    int userInput;
    cout << "Please enter a positive integer: ";
    cin >> userInput;
    
    cout << "\n========= Section A =========\n";
    printTriangle(userInput);
    
    cout << "\n========= Section B =========\n";
    printOppositeTriangles(userInput);
    
    cout << "\n========= Section C =========\n";
    printRuler(userInput);

    return 0;
}

void printTriangle(int n) {
    if (n == 1) {   // Base Case
        cout << star << endl;
    }
    else {     //Recursive Case
        printTriangle(n - 1);   // Recursive function call
        for (int i = n; i > 0; i--)
            cout << star;
        cout << endl;
    }
}
void printOppositeTriangles(int n) {
    if (n == 1) {   // Base Case
        cout << star << "\n" << star << endl;
    } 
    else {  //Recursive Case
        for (int i = 0; i < n; i++) //descending
            cout << star;
        cout << endl;

        printOppositeTriangles(n - 1);  // Recursive function call

        for (int i = 0; i < n; i++) //ascending
            cout << star;
        cout << endl;
    }
}
void printRuler(int n) {
    if(n == 1){ // Base Case:
        cout << mark << endl;
    }
    else {
        printRuler(n - 1); 
        for (int i = 0; i < n; i++) // middle line, n marks
            cout << mark;
        cout << endl;
        printRuler(n - 1);
    }
}