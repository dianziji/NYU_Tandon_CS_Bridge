#include <iostream>
#include <string>
using namespace std;

int main() {
    // Setting Variables
    string user_name;
    int graduation_year, current_year, years_left;
    int freshman = 4, sophomore = 3, junior = 2, senior = 1;

    cout << "Please enter your name: " << endl;
    cin >> user_name;
    cout << "Please enter your graduation year: " << endl;
    cin >> graduation_year;
    cout << "Please enter current year: " << endl;
    cin >> current_year;

    // Finding the difference
    years_left = graduation_year - current_year;

    if (years_left >= 5)
        cout << user_name << ", you are not in college yet!" << endl;
    else if (years_left == freshman)
        cout << user_name << ", you are a Freshman" << endl;
    else if (years_left == sophomore)
        cout << user_name << ", you are a Sophomore" << endl;
    else if (years_left == junior)
        cout << user_name << ", you are a Junior" << endl;
    else if (years_left == senior)
        cout << user_name << ", you are a Senior" << endl;
    else
        cout << user_name << ", you have already graduated" << endl;

    return 0;
}