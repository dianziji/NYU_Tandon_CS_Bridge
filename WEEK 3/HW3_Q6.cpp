#include <iostream>
#include <string>
using namespace std;

int main() {
    // Setting variables
    const double WEEKDAY_RATE = .40, WEEKNIGHT_RATE = .25, WEEKEND_RATE = .15;
    int callDuration, callCost, hour, minutes;
    string day;
    char temp;
    float ratePerMinute;

    // Input
    cout << "Please enter the time that the call started in 24-hour notation (00:00):" << endl;
    cin >> hour >> temp >> minutes;
    cout << "Please enter the day of the week as one of the following two characters (Mo, Tu, We, Th, Fr, Sa, Su):" << endl;
    cin >> day;
    cout << "Please enter the length of the call in minutes:" << endl;
    cin >> callDuration;

    if (day == "Sa" || day == "Su")
        ratePerMinute = WEEKEND_RATE;
    else {
        if (hour >= 8 && hour < 18)
            ratePerMinute = WEEKDAY_RATE;
        else if (hour == 18)
            if (minutes == 0)                   // Since 6:00 PM is included in the day time
                ratePerMinute = WEEKDAY_RATE;
            else                                // 6:01 >
                ratePerMinute = WEEKNIGHT_RATE;
        else
            ratePerMinute = WEEKNIGHT_RATE;
    }

    callCost = callDuration * ratePerMinute;

    cout << "The cost of the call is: $" << callCost << endl;

    return 0;
}