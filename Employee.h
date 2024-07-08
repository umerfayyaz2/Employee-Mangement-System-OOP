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
     void displayInfo() const override;              // Virtual function

    const char *getJobRole();
    void setJobRole();

    int getId() const;
    void setId();

    static int getNextId();

    // friend ostream &operator<<(ostream &out, const Employee &emp);
};

// ostream &operator<<(ostream &out, const Employee &emp);

#include "Employee.cpp"

#endif // EMPLOYEE_H_INCLUDED
