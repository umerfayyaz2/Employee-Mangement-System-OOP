#ifndef EMPLOYEEMANAGER_H_INCLUDED
#define EMPLOYEEMANAGER_H_INCLUDED

#include "Employee.h"
#include <vector>

class EmployeeManager
{
private:
    vector<Employee *> employees;

public:
    EmployeeManager();
    ~EmployeeManager();

    // crud
    void addEmployee();
    void updateEmployee();
    void deleteEmployee();
    void viewEmployee();

    void displayEmployees() ;

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