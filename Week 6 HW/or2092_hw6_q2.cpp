// or2092_hw6_q2.cpp

#include <iostream>
using namespace std;

void printShiftedTriangle(int n, int m, char symbol);
// Prints a pine tree with n-lines, shifted m-spaces using the symbol of choice.

void printPineTree(int n, char symbol);
// Prints a sequence of n triangles of increasing sizes using symbol of choice.

const char SPACE = ' ';

int main()
{   
    // printShiftedTriangle(3, 4, '+');
    // for reference
    
    // Setting up input retrieval 
    int num;
    char symbol;
    cout << "Please enter the desired number of triangles (i.g., 1, 3, 7),\n"
         << "followed by the desired symbol (e.g., '*' or '+' or '$', etc),\n"
         << "separated by a space: ";
    cin >> num >> symbol;

    // Calling the function printPineTree using userInput
    printPineTree(num, symbol);
    
}

void printShiftedTriangle(int n, int m, char symbol)
{
    int starlimit = 1, spacelimit = n - 1;
    for (int row = 0; row < n; row++)
    {
        // Shift
        for (int col = 0; col < m; col++)
            cout << SPACE;
        // Space
        for (int col = 0; col < spacelimit; col++)
        {
            cout << SPACE;
        }
        // Symbol
        for (int col = 0; col < starlimit; col++)
        {
            cout << symbol;
        }
        cout << endl;
        spacelimit--;
        starlimit += 2;
    }
}

void printPineTree(int n, char symbol)
{
    int shiftLimit = n - 1;
    for (int tri = 2; tri <= n + 1; tri++)
    {   // Triangle loop
        printShiftedTriangle(tri, shiftLimit, symbol);
        shiftLimit--;
    }
}