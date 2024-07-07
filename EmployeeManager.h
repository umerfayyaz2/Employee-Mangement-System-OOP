#ifndef EMPLOYEEMANAGER_H_INCLUDED
#define EMPLOYEEMANAGER_H_INCLUDED

#include "FullTimeEmployee.h"
#include "PartTimeEmployee.h"

class EmployeeManager
{
private:
    static int numberOfFullTimeEmployees;
    static int numberOfPartTimeEmployees;
    FullTimeEmployee **fullTimeEmployees;
    PartTimeEmployee **partTimeEmployees;

public:
    EmployeeManager();
    ~EmployeeManager();

    static int getNumberOfFullTimeEmployees();
    static int getNumberOfPartTimeEmployees();

    void clear();

    // crud
    void addEmployee();
    void updateEmployee();
    void deleteEmployee();
    void viewEmployee();

    void displayEmployees();

    // file handling
    void saveEmployees();

    void deletePartTimeEmployee();
    void deleteFullTimeEmployee();

    void loadEmployees();

    void updatePartTimeEmployee();
    void updateFullTimeEmployee();
};

#include "EmployeeManager.cpp"

#endif