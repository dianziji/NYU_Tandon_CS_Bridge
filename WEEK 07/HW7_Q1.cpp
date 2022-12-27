#include <iostream>
#include <string>
using namespace std;

// Declaring functions + constants
int printMonthCalendar(int numOfDays, int startingDay);
void printYearCalendar(int year, int startingDay);
string printMonth(int month);
int printNumOfDays(int month, int year);
int leapYearCheck(int year);

// Global constants
const char TAB = '\t';
const int DAYS_IN_A_WEEK = 7;
const int JANUARY = 1, FEBRUARY = 2, MARCH = 3, APRIL = 4, MAY = 5, JUNE = 6, JULY = 7, AUGUST = 8, SEPTEMBER = 9, OCTOBER = 10, NOVEMBER = 11, DECEMBER = 12;

int main() {
	// Setting up user input
	int yearInput, dayInput;
	cout << "Please enter the desired year (yyyy), and the day that starts the week (1 for Monday up to 7 for Sunday),\n"
		 << "separated by a space. (e.g., 2022 5) : ";
	cin >> yearInput >> dayInput;

	printYearCalendar(yearInput, dayInput);

	return 0;
}

int printMonthCalendar(int numOfDays, int startingDay)
{	// Prints the calendar for a single month
	cout << "Mon" << TAB << "Tue" << TAB << "Wed" << TAB << "Thr"
		<< TAB << "Fri" << TAB << "Sat" << TAB << "Sun" << endl;
	int startingSpaces, day;
	for (startingSpaces = 0; startingSpaces < startingDay - 1; startingSpaces++)
	{	// fills in spaces preceding the first day of the month
		cout << TAB;
	}
	for (day = 1; day <= numOfDays; day++)
	{	// fills in the days, introducing a new line at the end of the week, and at the end of the month
		cout << day << TAB;
		if (((startingSpaces + day) % DAYS_IN_A_WEEK == 0) || (day == numOfDays))
			cout << endl;
	}
	// returns the the last day, to be used as the start of the next month
	cout << endl;
	int dayOut = numOfDays + startingSpaces;
	return dayOut % DAYS_IN_A_WEEK;
}

void printYearCalendar(int year, int startingDay)
{	// Prints the calendar for a single year
	for (int month = 1; month <= 12; month++)
	{	// Loops through each month, printing the month/year, followed by the month calendar, sets the starting day equal to the (last day + 1)
		cout << printMonth(month) << year << endl;
		int numOfDays = printNumOfDays(month, year);
		startingDay = printMonthCalendar(numOfDays, startingDay) + 1;
	}
}

int leapYearCheck(int year)
{	// Checks for lear year
	if ((year % 4 == 0) && (year % 100 != 0))
		return true;
	else if (year % 400 == 0)
		return true;
	else
		return false;
}

string printMonth(int month)
{	// Takes an integer and outputs the month as a string
	string calendarMonth;
	switch (month) {
	case 1:
		calendarMonth = "January ";
		break;
	case 2:
		calendarMonth = "February ";
		break;
	case 3:
		calendarMonth = "March ";
		break;
	case 4:
		calendarMonth = "April ";
		break;
	case 5:
		calendarMonth = "May ";
		break;
	case 6:
		calendarMonth = "June ";
		break;
	case 7:
		calendarMonth = "July ";
		break;
	case 8:
		calendarMonth = "August ";
		break;
	case 9:
		calendarMonth = "September ";
		break;
	case 10:
		calendarMonth = "October ";
		break;
	case 11:
		calendarMonth = "November ";
		break;
	case 12:
		calendarMonth = "December ";
		break;
	}
	return calendarMonth;
}

int printNumOfDays(int month, int year)
{	// Takes a month and year, returns #of days in the month, checking for a leap year to change February between 28-29
	if (month == JANUARY || month == MARCH || month == MAY || month == JULY || month == AUGUST || month == OCTOBER || month == DECEMBER)
		return 31;
	else if (month == FEBRUARY)
	{
		if (leapYearCheck(year))
			return 29;
		else
			return 28;
	}
	else
		return 30;
}