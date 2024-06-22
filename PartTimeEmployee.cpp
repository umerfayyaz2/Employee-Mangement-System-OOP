#include "PartTimeEmployee.h"
#include <iostream>
#include <stdexcept>

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

void PartTimeEmployee::setHourlyRate(double rate)
{
    if (rate < 0)
    {
        throw invalid_argument("Hourly rate cannot be negative.");
    }
    hourlyRate = rate;
}

void PartTimeEmployee::setHoursWorked(int hours)
{
    if (hours < 0)
    {
        throw invalid_argument("Hours worked cannot be negative.");
    }
    hoursWorked = hours;
}

double PartTimeEmployee::getHourlyRate() const
{
    return hourlyRate;
}

int PartTimeEmployee::getHoursWorked() const
{
    return hoursWorked;
}
