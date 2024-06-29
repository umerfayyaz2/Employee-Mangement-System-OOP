#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include "person.h"

class Employee : public Person
{
protected:
    static int id;

public:
    Employee();          // Default constructor
    virtual ~Employee(); // Virtual destructor

    virtual int calculateSalary() const = 0; // Pure virtual function
    virtual void displayInfo();              // Virtual function

    int getId() const;

    static int getNextId();
};

#include "Employee.cpp"

#endif // EMPLOYEE_H_INCLUDED
