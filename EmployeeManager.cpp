#include "EmployeeManager.h"

#include <iostream>
#include <fstream>
#include "input_validation.h"
#include "FullTimeEmployee.h"
#include "PartTimeEmployee.h"

#define MAX_EMPLOYEES 10

using namespace std;

int EmployeeManager::numberOfFullTimeEmployees = 0;
int EmployeeManager::numberOfPartTimeEmployees = 0;

EmployeeManager::EmployeeManager()
{
    fullTimeEmployees = new FullTimeEmployee *[MAX_EMPLOYEES];
    partTimeEmployees = new PartTimeEmployee *[MAX_EMPLOYEES];
}

void EmployeeManager::clear()
{
    for (int i = 0; i < numberOfFullTimeEmployees; i++)
    {
        delete fullTimeEmployees[i];
    }
    // delete[] fullTimeEmployees;
    // fullTimeEmployees = nullptr;
    numberOfFullTimeEmployees = 0;
    for (int i = 0; i < numberOfPartTimeEmployees; i++)
    {
        delete partTimeEmployees[i];
    }
    // delete[] partTimeEmployees;
    // partTimeEmployees = nullptr;
    numberOfPartTimeEmployees = 0;
}

EmployeeManager::~EmployeeManager()
{
    clear();
}

int EmployeeManager::getNumberOfFullTimeEmployees()
{
    return numberOfFullTimeEmployees;
}

int EmployeeManager::getNumberOfPartTimeEmployees()
{
    return numberOfPartTimeEmployees;
}

// crud
void EmployeeManager::addEmployee()
{
    loadEmployees();
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
            PartTimeEmployee *ptEmployee = new PartTimeEmployee();
            partTimeEmployees[numberOfPartTimeEmployees++] = ptEmployee;
            saveEmployees();
            return;
        }
        case 2:
        {
            FullTimeEmployee *ftEmployee = new FullTimeEmployee();
            fullTimeEmployees[numberOfFullTimeEmployees++] = ftEmployee;
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
    // clear();
    loadEmployees();
    int choice, empId;

    while (true)
    {
        validate_input_int(choice, "1. Update Full Time Employee\n2. Update Part Time Employee\nYour choice: ", "Invalid choice, please try again...");

        switch (choice)
        {
        case 1:
            validate_input_int(empId, "Enter employee id to update employee: ", "Invalid employee id, please try again...");

            for (int i = 0; i < numberOfFullTimeEmployees; i++)
            {
                if (fullTimeEmployees[i]->getId() == empId)
                {
                    fullTimeEmployees[i]->set_fulltime_employee_data();
                    saveEmployees();
                    return;
                }
            }
            cout << "No full time employee found against id " << empId << "\n";
            return;
        case 2:
            validate_input_int(empId, "Enter employee id to update employee: ", "Invalid employee id, please try again...");

            for (int i = 0; i < numberOfPartTimeEmployees; i++)
            {
                if (partTimeEmployees[i]->getId() == empId)
                {
                    partTimeEmployees[i]->set_partime_employee_details();
                    saveEmployees();
                    return;
                }
            }
            cout << "No part time employee found against id " << empId << "\n";
            return;
        default:
            cout << "Invalid choice, please enter between (1-2)...\n";
            break;
        }
    }
}

void EmployeeManager::deleteEmployee()
{
    loadEmployees();
    int choice, empId;

    while (true)
    {
        validate_input_int(choice, "1. Delete Full Time Employee\n2. Delete Part Time Employee\nYour choice: ", "Invalid choice, please try again...");

        switch (choice)
        {
        case 1:
            validate_input_int(empId, "Enter employee id to delete employee: ", "Invalid employee id, please try again...");

            for (int i = 0; i < numberOfFullTimeEmployees; i++)
            {
                if (fullTimeEmployees[i]->getId() == empId)
                {
                    delete fullTimeEmployees[i];
                    for (int j = i; j < numberOfFullTimeEmployees; j++)
                    {
                        fullTimeEmployees[j] = fullTimeEmployees[j + 1];
                    }
                    saveEmployees();
                    return;
                }
            }
            cout << "No full time employee found against id " << empId << "\n";
            return;
        case 2:
            validate_input_int(empId, "Enter employee id to delete employee: ", "Invalid employee id, please try again...");

            for (int i = 0; i < numberOfPartTimeEmployees; i++)
            {
                if (partTimeEmployees[i]->getId() == empId)
                {
                    delete partTimeEmployees[i];
                    for (int j = i; j < numberOfPartTimeEmployees; j++)
                    {
                        partTimeEmployees[j] = partTimeEmployees[j + 1];
                    }
                    saveEmployees();
                    return;
                }
            }
            cout << "No part time employee found against id " << empId << "\n";
            return;
        default:
            cout << "Invalid choice, please enter between (1-2)...\n";
            break;
        }
    }
}

void EmployeeManager::viewEmployee()
{
    loadEmployees();
    int choice, empId;

    while (true)
    {
        validate_input_int(choice, "1. View Full Time Employee\n2. View Part Time Employee\nYour choice: ", "Invalid choice, please try again...");

        switch (choice)
        {
        case 1:
            validate_input_int(empId, "Enter employee id to view employee: ", "Invalid employee id, please try again...");

            for (int i = 0; i < numberOfFullTimeEmployees; i++)
            {
                if (fullTimeEmployees[i]->getId() == empId)
                {
                    // fullTimeEmployees[i]->displayInfo();
                    cout << *fullTimeEmployees[i];
                    return;
                }
            }
            cout << "No full time employee found against id " << empId << "\n";
            return;
        case 2:
            validate_input_int(empId, "Enter employee id to update employee: ", "Invalid employee id, please try again...");

            for (int i = 0; i < numberOfPartTimeEmployees; i++)
            {
                if (partTimeEmployees[i]->getId() == empId)
                {
                    // partTimeEmployees[i]->displayInfo();
                    cout << *partTimeEmployees[i];
                    return;
                }
            }
            cout << "No part time employee found against id " << empId << "\n";
            return;
        default:
            cout << "Invalid choice, please enter between (1-2)...\n";
            break;
        }
    }
}

void EmployeeManager::displayEmployees()
{
    loadEmployees();

    cout << "Displaying employees..." << endl;
    cout << "Number of full-time employees: " << numberOfFullTimeEmployees << endl;
    cout << "Number of part-time employees: " << numberOfPartTimeEmployees << endl;

    if (numberOfFullTimeEmployees == 0 && numberOfPartTimeEmployees == 0)
    {
        cout << "No full time and part time employees currently.\n";
        return;
    }

    for (int i = 0; i < numberOfFullTimeEmployees; i++)
    {
        fullTimeEmployees[i]->displayInfo();
        cout << "\n---------------------------\n";
    }

    for (int i = 0; i < numberOfPartTimeEmployees; i++)
    {
        partTimeEmployees[i]->displayInfo();
        cout << "\n---------------------------\n";
    }
}

void EmployeeManager::saveEmployees()
{

    ofstream fout("FullTimeEmployees.dat", ios::binary | ios::trunc);
    if (!fout)
    {
        cerr << "Error opening file FullTimeEmployees.dat for writing\n";
        return;
    }

    for (int i = 0; i < numberOfFullTimeEmployees; i++)
    {
        fout.write(reinterpret_cast<const char *>(fullTimeEmployees[i]), sizeof(FullTimeEmployee));
        if (!fout)
        {
            cerr << "Error writing full-time employee " << i << " to file\n";
            fout.close();
            return;
        }
    }
    fout.close();

    // Save Part Time Employees
    ofstream fout2("PartTimeEmployees.dat", ios::binary | ios::trunc);
    if (!fout2)
    {
        cerr << "Error opening file PartTimeEmployees.dat for writing\n";
        return;
    }

    for (int i = 0; i < numberOfPartTimeEmployees; i++)
    {
        fout2.write(reinterpret_cast<const char *>(partTimeEmployees[i]), sizeof(PartTimeEmployee));
        if (!fout2)
        {
            cerr << "Error writing part-time employee " << i << " to file\n";
            fout2.close();
            return;
        }
    }
    fout2.close();

    clear();
}

void EmployeeManager::loadEmployees()
{
    clear();

    // Load Full Time Employees
    ifstream fin("FullTimeEmployees.dat", ios::in | ios::binary);
    if (fin)
    {
        FullTimeEmployee temp(1);
        while (fin.read(reinterpret_cast<char *>(&temp), sizeof(FullTimeEmployee)))
        {
            FullTimeEmployee *employee = new FullTimeEmployee(temp);
            fullTimeEmployees[numberOfFullTimeEmployees++] = employee;
        }
        fin.close();
    }
    else
    {
        cerr << "FullTimeEmployees.dat file not found or couldn't be opened." << endl;
    }

    // Load Part Time Employees
    ifstream fin2("PartTimeEmployees.dat", ios::in | ios::binary);
    if (fin2)
    {
        PartTimeEmployee temp2(1);
        while (fin2.read(reinterpret_cast<char *>(&temp2), sizeof(PartTimeEmployee)))
        {
            PartTimeEmployee *employee = new PartTimeEmployee(temp2);
            partTimeEmployees[numberOfPartTimeEmployees++] = employee;
        }
        fin2.close();
    }
    else
    {
        cerr << "PartTimeEmployees.dat file not found or couldn't be opened." << endl;
    }
}