#include "dateType.h"
#include "input_validation.h"

dateType::dateType() : day(1), month(1), year(2000)
{
    // setDate();
}

dateType &dateType::operator=(const dateType &other)
{
    if (this == &other)
    {
        return *this; // Handle self-assignment
    }
    this->day = other.day;
    this->month = other.month;
    this->year = other.year;

    return *this;
}

dateType::~dateType() {}

int dateType::getDay() const
{
    return day;
}

int dateType::getMonth() const
{
    return month;
}

int dateType::getYear() const
{
    return year;
}

void dateType::printDate()
{
    cout << day << " / " << month << " / " << year;
}

bool dateType::check_leap_year() const
{
    if (year % 400 == 0)
        return true;

    if (year % 100 == 0)
        return false;

    return year % 4 == 0;
};

void dateType::setDate()
{
    while (true)
    {
        try
        {
            validate_input_int(month, "Enter month: ", "Invalid month, please try again...");
            if (month < 1 || month > 12)
                throw invalid_argument("Invalid month, please try again...");

            validate_input_int(year, "Enter year: ", "Invalid year, please try again...");
            if (year < 1980 || year > 2024)
                throw invalid_argument("Invalid year, please try again...");

            validate_input_int(day, "Enter day: ", "Invalid day, please try again...");
            if (day < 1 || day > 31)
                throw invalid_argument("Invalid day, please try again...");

            bool isValidDay = true;
            if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
                isValidDay = (day >= 1 && day <= 31);
            else if (month == 4 || month == 6 || month == 9 || month == 11)
                isValidDay = (day >= 1 && day <= 30);
            else if (month == 2)
            {
                if (check_leap_year())
                    isValidDay = (day >= 1 && day <= 29);
                else
                    isValidDay = (day >= 1 && day <= 28);
            }
            isValidDay = (day >= 1 && day <= 31);

            break;
        }
        catch (const invalid_argument &e)
        {
            cerr << "Error: " << e.what();
            cin.clear();
            clear_input_buffer();
        }
    }
}