#ifndef FULLTIMEEMPLOYEE_H
#define FULLTIMEEMPLOYEE_H

#include "Employee.h"

class FullTimeEmployee : public Employee
{
private:
    int monthlySalary;

public:
    FullTimeEmployee();  // Default constructor
    ~FullTimeEmployee(); // Destructor

    // Friend function to set full-time employee data
    friend void set_fulltime_employee_data(FullTimeEmployee &employee);

    int calculateSalary() const override; // Override calculateSalary
    void displayInfo() override;          // Override displayInfo

    // Setter methods
    void setMonthlySalary();

    // Getter methods
    int getMonthlySalary() const;
};

#endif // FULLTIMEEMPLOYEE_H
