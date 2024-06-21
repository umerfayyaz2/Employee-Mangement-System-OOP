#ifndef FULLTIMEEMPLOYEE_H_INCLUDED
#define FULLTIMEEMPLOYEE_H_INCLUDED

#include "Employee.h"

class FullTimeEmployee : public Employee {
private:
    int monthlySalary;

public:
    // Constructor and Destructor
    FullTimeEmployee();
    ~FullTimeEmployee();

    // Override calculateSalary and displayInfo
    int calculateSalary() const override;
    void displayInfo() override;

    // Getter and Setter for monthlySalary
    int getMonthlySalary() const;
    void setMonthlySalary();

    // Member functions to set and print data
    void setData();
    void printData();
};

#endif // FULLTIMEEMPLOYEE_H_INCLUDED
