#include "PartTimeEmployee.h"
#include <iostream>
#include <stdexcept>
#include "input_validation.h"
#include <limits>

using namespace std;

PartTimeEmployee::PartTimeEmployee() : Employee(), hourlyRate(0), hoursWorked(0) {}

PartTimeEmployee::~PartTimeEmployee() {}

int PartTimeEmployee::calculateSalary() const
{
    return static_cast<int>(hourlyRate * hoursWorked);
}

void PartTimeEmployee::displayInfo()
{
    Employee::displayInfo();
    cout << "Hourly Rate: " << hourlyRate << endl;
    cout << "Hours Worked: " << hoursWorked << endl;
}

void PartTimeEmployee::setHourlyRate()
{
    double rate;

    while (true)
    {
        try
        {
            cout << "Enter the Hourly Rate Here (max range 80 $): ";
            double_validation(rate);

            // Validate the input to ensure it's a double
            if (cin.fail())
            {
                throw invalid_argument("Input is not a valid number.");
            }

            // Validate the rate value
            if (rate < 0 || rate > 80)
            {
                throw invalid_argument("Enter Hourly Rate in a valid range (0 to 80 $): ");
            }

            // If the input is valid, break out of the loop
            break;
        }
        catch (const invalid_argument &e)
        {
            cerr << "Error: " << e.what() << " Please enter a valid hourly rate." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    hourlyRate = rate;
}

void PartTimeEmployee::setHoursWorked()
{
    int hours;

    while (true)
    {
        try
        {
            cout << "Enter the Hours Worked (max 160 hours): ";
            int_validation(hours);

            // Validate the input to ensure it's an integer
            if (cin.fail())
            {
                throw invalid_argument("Input is not a valid integer.");
            }

            // Validate the hours worked value
            if (hours < 0 || hours > 160)
            {
                throw invalid_argument("Enter Hours Worked in a valid range (0 to 160): ");
            }

            // If the input is valid, break out of the loop
            break;
        }
        catch (const invalid_argument &e)
        {
            cerr << "Error: " << e.what() << " Please enter a valid number of hours worked." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    hoursWorked = hours;
}

void PartTimeEmployee::set_partime_employee_details()
{
    cout << "Setting Part-Time Employee Details: " << endl;
    setName();
    setDOB();
    setPhoneNumber();
    setAddress();
    setHourlyRate();
    setHoursWorked();
}

double PartTimeEmployee::getHourlyRate() const
{
    return hourlyRate;
}

int PartTimeEmployee::getHoursWorked() const
{
    return hoursWorked;
}
