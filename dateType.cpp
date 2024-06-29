#include "dateType.h"
#include "input_validation.h"
#include <limits>
#include <cstdlib>

// Default constructor
dateType::dateType() : day(1), month(1), year(2000) {}

// Parameterized constructor
// dateType::dateType(int dd, int mm, int yyyy) : day(dd), month(mm), year(yyyy) {
//    dd = day;
//    mm = month;
//    yyyy = year;
//}

// Destructor
dateType::~dateType() {}

// Get the day
int dateType::getDay() const
{
    return day;
}

// Get the month
int dateType::getMonth() const
{
    return month;
}

// Get the year
int dateType::getYear() const
{
    return year;
}

void dateType::printDate()
{
    cout << day << " / " << month << " / " << year;
}

// Method To Check Leap Year :)
bool dateType::check_leap_year() const
{
    if (year % 400 == 0)
        return true;

    if (year % 100 == 0) // LEAP YEAR CALCULATION FORMULA APPLIED HERE
        return false;

    return year % 4 == 0;
};

// Set the day with validation

void dateType::setDay()
{
    int d;

    while (true)
    {

        try
        {
            cout << "Enter day (1-31): ";
            int_validation(d);
            system("cls");
            // Validate range after successful input
            if (d < 1 || d > 31)
            {
                throw invalid_argument("Invalid day. Please enter a day between 1 and 31.");
            }

            // If input is valid and in range, break the loop
            break;
        }
        catch (const invalid_argument &e)
        {
            system("cls");
            cerr << "Error: " << e.what() << endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    day = d;
}

// Set the month with validation
void dateType::setMonth()
{
    int m;

    while (true)
    {
        try
        {
            cout << "Enter month (1-12): ";
            int_validation(m);
            system("cls");

            if (m < 1 || m > 12)
            {
                throw invalid_argument("Invalid month. Please enter a month between 1 and 12.");
            }

            break;
        }

        catch (const invalid_argument &e)
        {
            system("cls");
            cerr << "Error: " << e.what() << endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    month = m;
}

// Set the year with validation
void dateType::setYear()
{
    int y;

    while (true)
    {
        try
        {
            cout << "Enter year (1970-2024): ";
            int_validation(y);
            system("cls");

            if (y < 1970 || y > 2024)
            {
                throw invalid_argument("Invalid year. Please enter a year between 1970 and 2024.");
            }

            break;
        }

        catch (invalid_argument &e)
        {
            system("cls");
            cerr << "Error: " << e.what() << endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    year = y;
}
