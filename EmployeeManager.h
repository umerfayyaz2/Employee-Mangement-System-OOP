#ifndef EMPLOYEEMANAGER_H_INCLUDED
#define EMPLOYEEMANAGER_H_INCLUDED

#include "FullTimeEmployee.h"
#include "PartTimeEmployee.h"

class EmployeeManager
{
private:
    static int numberOfFullTimeEmployees;
    static int numberOfPartTimeEmployees;
    FullTimeEmployee **fullTimeEmployees; // Arrays of pointers allow for dynamic memory management and polymorphism, as each pointer can point to objects of different derived classes.
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