#include "FullTimeEmployee.h"
#include "input_validation.h"

#include <iostream>
using namespace std;

FullTimeEmployee::FullTimeEmployee() : Employee(), monthlySalary(0) {}

FullTimeEmployee::~FullTimeEmployee() {}

void FullTimeEmployee::set_fulltime_employee_data()
{
    this->setName();
    this->setDOB();
    this->setPhoneNumber();
    this->setAddress();
    this->setMonthlySalary();
    this->setAge();
}

int FullTimeEmployee::calculateSalary() const
{
    return monthlySalary;
}

void FullTimeEmployee::displayInfo()
{
    Employee::displayInfo();
    cout << "Monthly Salary: " << monthlySalary << " $" << endl;
}

void FullTimeEmployee::setMonthlySalary()
{
    while (true)
    {

        validate_input_int(monthlySalary, "Enter the salary (max 60k $): ", "Invalid salary, please try again...");

        if (monthlySalary > 0 || monthlySalary <= 60000)
            break;
    }
}

int FullTimeEmployee::getMonthlySalary() const
{
    return monthlySalary;
}
