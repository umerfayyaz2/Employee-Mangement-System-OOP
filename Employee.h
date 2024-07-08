#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include "person.h"

class Employee : public Person
{
protected:
    int id;
    static int count;
    char jobRole[30];

public:
    Employee(); // Default constructor
    Employee(int);
    Employee(const Employee &other);
    virtual ~Employee(); // Virtual destructor

    virtual int calculateSalary() const = 0; // Pure virtual function
    virtual void displayInfo();              // Virtual function

    const char *getJobRole();
    void setJobRole();

    int getId() const;
    void setId();

    static int getNextId();
};

#include "Employee.cpp"

#endif // EMPLOYEE_H_INCLUDED
