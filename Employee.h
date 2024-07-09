#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include "person.h"

class Employee : public Person
{
protected:
    int id;           // Unique ID for each employee
    static int count; // Static variable to keep track of the number of employees
    char jobRole[30]; // Job role of the employee

public:
    Employee();                      // Default constructor
    Employee(int);                   // Constructor with an integer parameter
    Employee(const Employee &other); // Copy constructor
    virtual ~Employee();             // Virtual destructor

    virtual int calculateSalary() const = 0; // Pure virtual function for calculating salary
    void displayInfo() const override;       // Override the displayInfo method from Person

    const char *getJobRole(); // Getter for jobRole
    void setJobRole();        // Setter for jobRole

    int getId() const; // Getter for id
    void setId();      // Setter for id

    static int getNextId(); // Static method to get the next employee ID

    // friend ostream &operator<<(ostream &out, const Employee &emp);
};

// ostream &operator<<(ostream &out, const Employee &emp);

#include "Employee.cpp"

#endif // EMPLOYEE_H_INCLUDED
