#include "EmployeeManager.h"

#include <iostream>
#include <fstream>
#include "input_validation.h"
#include "FullTimeEmployee.h"
#include "PartTimeEmployee.h"

using namespace std;

EmployeeManager::EmployeeManager() {}

EmployeeManager::~EmployeeManager() {}

// crud
void EmployeeManager::addEmployee()
{
    int choice;
    while (true)
    {
        cout << "Enter 1 to add part time employee.\n"
                "Enter 2 to add full time employee.\n";

        validate_input_int(choice, "Your choice: ", "Invalid choice, please try again...");

        switch (choice)
        {
        case 1:
        {
            Employee *ptEmployee = new PartTimeEmployee();
            employees.push_back(ptEmployee);
            saveEmployees();
            return;
        }
        case 2:
        {
            Employee *ftEmployee = new FullTimeEmployee();
            employees.push_back(ftEmployee);
            saveEmployees();
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
    int empId;
    validate_input_int(empId, "Enter employee id to view employee: ", "Invalid employee id, please try again...");

    for (auto emp : employees)
    {
        if (emp->getId() == empId)
        {
            emp->setData();

            return;
        }
    }

    std::cout << "No employee found against id " << empId << "\n";
}

void EmployeeManager::deleteEmployee()
{
    int empId;
    validate_input_int(empId, "Enter employee id to view employee: ", "Invalid employee id, please try again...");

    for (int i = 0; i < employees.size(); i++)
    {
        if (employees[i]->getId() == empId)
        {
            employees.erase(employees.begin() + i);
            return;
        }
    }

    std::cout << "No employee found against id " << empId << "\n";
}

void EmployeeManager::viewEmployee()
{
    int empId;
    validate_input_int(empId, "Enter employee id to view employee: ", "Invalid employee id, please try again...");

    for (auto emp : employees)
    {
        if (emp->getId() == empId)
        {
            emp->displayInfo();
            return;
        }
    }

    std::cout << "No employee found against id " << empId << "\n";
}

void EmployeeManager::displayEmployees()
{
    loadEmployees();
    if (employees.size() == 0)
    {
        cout << "No employees currently.\n ";
        return;
    }

    for (auto emp : employees)
    {
        emp->displayInfo();
        cout << "\n---------------------------\n";
    }
}

void EmployeeManager::saveEmployees()
{
    ofstream fout("Employees.dat", ios::binary | ios::app);
    if (!fout)
    {
        cerr << "Error openning file Employees.dat\n";
        return;
    }
    try
    {
        for (int i = 0; i < employees.size(); ++i)
        {
            fout.write(reinterpret_cast<const char *>(&employees[i]), sizeof(employees));
            if (!fout)
            {
                throw ios_base::failure("Error writing to file");
            }
        }
    }
    catch (const ios_base::failure &e)
    {
        cerr << "File write error: " << e.what() << endl;
    }
    catch (...)
    {
        cerr << "Unknown error occurred while saving employees." << endl;
    }
    fout.close();
}

void EmployeeManager::deletePartTimeEmployee()
{
}

void EmployeeManager::deleteFullTimeEmployee()
{
}

void EmployeeManager::loadEmployees()
{
    std::ifstream fin("Employees.dat", ios::binary);
    if (!fin)
    {
        std::cerr << "Error: Unable to open teacher file.\n";
        return;
    }

    employees.clear();
    Employee *temp;
    try
    {
        while (fin.read(reinterpret_cast<char *>(temp), sizeof(employees)))
        {
            employees.push_back(temp);
        }
    }
    catch (const ios_base::failure &e)
    {
        cerr << "File read error: " << e.what() << endl;
    }
    catch (...)
    {
        cerr << "Unknown error occurred while loading teachers." << endl;
    }

    fin.close();
}

void EmployeeManager::updatePartTimeEmployee()
{
}

void EmployeeManager::updateFullTimeEmployee()
{
}
