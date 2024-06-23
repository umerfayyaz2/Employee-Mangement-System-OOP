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
    void assignRole();

    void displayEmployees() const;
};

#endif