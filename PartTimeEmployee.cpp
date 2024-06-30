#include "PartTimeEmployee.h"
#include "input_validation.h"

#include <iostream>
using namespace std;

PartTimeEmployee::PartTimeEmployee()
{
    set_partime_employee_details();
}

PartTimeEmployee::~PartTimeEmployee()
{
}

int PartTimeEmployee::calculateSalary() const
{
    return static_cast<int>(hourlyRate * hoursWorked);
}

void PartTimeEmployee::displayInfo()
{
    Employee::displayInfo();
    cout << "Hourly Rate: " << hourlyRate << endl;
    cout << "Hours Worked: " << hoursWorked << endl;
    cout << "Salary: " << calculateSalary() << " $" << endl;
}

void PartTimeEmployee::setHourlyRate()
{
    while (true)
    {
        validate_input_double(hourlyRate, "Enter hourly rate (max range 80 $): ", "Invalid hourly rate, please try again...");

        if (hourlyRate >= 0 || hourlyRate <= 80)
            break;
    }
}

void PartTimeEmployee::setHoursWorked()
{
    while (true)
    {
        validate_input_int(hoursWorked, "Enter the hours worked (max 169 hours): ", "Invalid working hours, please try again...");

        if (hoursWorked > 0 || hoursWorked < 160)
            break;
    }
}

void PartTimeEmployee::set_partime_employee_details()
{
    cout << "Setting Part-Time Employee Details: " << endl;
    this->setName();
    this->setDOB();
    this->setPhoneNumber();
    this->setAddress();
    this->setHourlyRate();
    this->setHoursWorked();
    this->setAge();
}

double PartTimeEmployee::getHourlyRate() const
{
    return hourlyRate;
}

int PartTimeEmployee::getHoursWorked() const
{
    return hoursWorked;
}
