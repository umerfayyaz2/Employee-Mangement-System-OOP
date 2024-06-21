#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include <iostream>
#include "Person.h"  // Include the Person header file

using namespace std;

class Employee : public Person {  // Inherit from Person
protected:
    static int id;

public:
    Employee(); // Default constructor
    virtual ~Employee(); // Virtual destructor

    virtual int calculateSalary() ; // Pure virtual function, changed to int
    virtual void displayInfo(); // Virtual function

    int getId() const;

    static int getNextId();

    // Declare setData and printData as friend functions
    friend void setData(Employee& e);
    friend void printData(Employee& e);
};

#endif // EMPLOYEE_H_INCLUDED
