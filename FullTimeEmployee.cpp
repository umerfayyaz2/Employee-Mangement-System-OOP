#include "FullTimeEmployee.h"
#include "input_validation.h"
#include <iostream>
#include <stdexcept>
#include <limits>

using namespace std;

FullTimeEmployee::FullTimeEmployee() : Employee(), monthlySalary(0) {}

FullTimeEmployee::~FullTimeEmployee() {}

void set_fulltime_employee_data(FullTimeEmployee &employee)
{
    employee.setName();
    employee.setDOB();
    employee.setPhoneNumber();
    employee.setAddress();
    employee.setAge();
    employee.setMonthlySalary();
}

int FullTimeEmployee::calculateSalary() const
{ // Corrected: Removed override here
    return monthlySalary;
}

void FullTimeEmployee::displayInfo()
{
    Employee::displayInfo();
    cout << "Monthly Salary: " << monthlySalary << " $" << endl;
}

// void FullTimeEmployee::setMonthlySalary()
// {   int salary;
//     while (while)
//     {
//         try
//         {
//             cout << "Enter The Salary Here: ";

//             int_validation(salary);

//             break;
//         }
//         catch (invalid_argument &e)
//         {
//             cerr << "Error" << e.what() << "Please enter a valid salary";
//             cin.clear();
//             cin.ignore(numeric_limits<streamsize>::max(), '\n');
//         }
//     }

//     if (monthlySalary < 0 )
//     {
//         throw invalid_argument("Monthly salary cannot be negative.");
//     }
//     monthlySalary = salary;
// }

void FullTimeEmployee::setMonthlySalary()
{
    int salary;

    while (true)
    {
        try
        {
            cout << "Enter the Salary Here ( max range 60k $) : ";
            int_validation(salary);

            // Validate the input to ensure it's an integer
            if (cin.fail())
            {
                throw invalid_argument("Input is not a valid integer.");
            }

            // Validate the salary value
            if (salary < 0 || salary > 60000)
            {
                throw invalid_argument("Enter Monthly Salary in a valid range ( max range 60k $): ");
            }

            // If the input is valid, break out of the loop
            break;
        }
        catch (const invalid_argument &e)
        {
            cerr << "Error: " << e.what() << " Please enter a valid salary in terms of number: " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    monthlySalary = salary;
}

int FullTimeEmployee::getMonthlySalary() const
{
    return monthlySalary;
}
