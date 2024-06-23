#include "EmployeeManager.h"

#include "input_validation.h"
#include <iostream>
#include "FullTimeEmployee.h"
#include "PartTimeEmployee.h"

using namespace std;

EmployeeManager::EmployeeManager()
{
}

EmployeeManager::~EmployeeManager()
{
}

// crud
void EmployeeManager::addEmployee()
{
    int choice;
    while (true)
    {
        cout << "Enter 1 to add part time employee.\n"
                "Enter 2 to add full time employee.\n"
                "Your choice: ";
        int_validation(choice);
        switch (choice)
        {
        case 1:
        {
            Employee *employee_pt = new PartTimeEmployee();
            employees.push_back(employee_pt);
            return;
        }
        case 2:
        {
            Employee *employee_ft = new FullTimeEmployee();
            employees.push_back(employee_ft);
            return;
        }
        default:
            cout << "Invalid input, please try again.\n";
            break;
        }
    }
}

void EmployeeManager::updateEmployee()
{
}

void EmployeeManager::deleteEmployee()
{
}

void EmployeeManager::viewEmployee()
{
}

void EmployeeManager::assignRole()
{
}

void EmployeeManager::displayEmployees() const
{
}