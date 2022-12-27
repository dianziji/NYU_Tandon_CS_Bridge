#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float discriminant, solution_one, solution_two;
    float a, b, c;

    cout << "Please enter value of a: " << endl;
    cin >> a;
    cout << "Please enter value of b: " << endl;
    cin >> b;
    cout << "Please enter value of c: " << endl;
    cin >> c;

    discriminant = (b * b) - (4 * a * c);
    solution_one = ((-b) - sqrt(discriminant)) / (2 * a);
    solution_two = ((-b) + sqrt(discriminant)) / (2 * a);

    cout.setf(ios::fixed);          // Referencing p.55 from 
    cout.setf(ios::showpoint);      // Problem Solving with C++
    cout.precision(1);              // to format the decimal 

    if ((a == 0) && (b == 0) && (c == 0))
        cout << "There are an infinite number of solutions." << endl;
    else if (a == 0)
        cout << "This equation has no solutions." << endl;
    else {
        if (discriminant > 0)
            cout << "This equation has two real solutions x = " << solution_one << " and x = " << solution_two << endl;
        else if (discriminant == 0)
            cout << "This equation has a single real solution x = " << solution_one << endl; //In this case, solu
        else
            cout << "This equation has no real solutions." << endl;
    }

    return 0;
}