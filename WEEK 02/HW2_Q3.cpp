#include <iostream>
using namespace std;

const int HOURS_PER_DAY = 24, MINUTES_PER_HOUR = 60, MINUTES_PER_DAY = 1440;

int main()
{
    int days_john_worked, hours_john_worked, minutes_john_worked, days_bill_worked, hours_bill_worked, minutes_bill_worked;
    int total_days_worked, total_hours_worked, total_minutes_worked;
    float totalTimeInMinutes, totalTime, remainingTimeInMinutes;
    int days, hours, minutes;


    cout << "Please enter the number of days John has worked: ";
    cin >> days_john_worked;
    cout << "Please enter the number of hours John has worked: ";
    cin >> hours_john_worked;
    cout << "Please enter the number of minutes John has worked: ";
    cin >> minutes_john_worked;
    cout << "\nPlease enter the number of days Bill has worked: ";
    cin >> days_bill_worked;
    cout << "Please enter the number of hours Bill has worked: ";
    cin >> hours_bill_worked;
    cout << "Please enter the number of minutes Bill has worked: ";
    cin >> minutes_bill_worked;

    total_days_worked = days_john_worked + days_bill_worked;                        // Days John worked + Days Bill worked.
    total_hours_worked = hours_john_worked + hours_bill_worked;                     // Hours John worked + Hours Bill worked.
    total_minutes_worked = minutes_john_worked + minutes_bill_worked;               // Minutes John worked + Hours Bill worked.
    totalTimeInMinutes = (total_days_worked * HOURS_PER_DAY * MINUTES_PER_HOUR) + 
        (total_hours_worked * MINUTES_PER_HOUR) + (total_minutes_worked);           // Lump sum of time worked by both John and Bill in minutes.

    remainingTimeInMinutes = totalTimeInMinutes;                                    // Creating starting point with the lump sum of time.

    days = static_cast<int>(remainingTimeInMinutes / MINUTES_PER_DAY);                           // From the lump sum of minutes, finding how many full (int) days can be extracted.
    remainingTimeInMinutes = remainingTimeInMinutes - (days * MINUTES_PER_DAY);     // Subtracting the total days (with the remainder) from the lump sum.

    hours = static_cast<int>(remainingTimeInMinutes / MINUTES_PER_HOUR);                         // From the lump sum of minutes, finding how many full (int) hours can be extracted.
    remainingTimeInMinutes = remainingTimeInMinutes - (hours * MINUTES_PER_HOUR);   // Subtracting the total hours (with the remainder) from the lump sum.

    minutes = remainingTimeInMinutes;   //The remaining time in minutes should be < 60 by this point

    cout << "\nThe total time both of them worked together is: " << days << " days, " << hours << " hours and " << minutes << " minutes." << endl; // Added a new line to mimic the output of the assignment sample.

    return 0;
}
