#ifndef PARTTIMEEMPLOYEE_H
#define PARTTIMEEMPLOYEE_H

#include "Employee.h"

class PartTimeEmployee : public Employee
{
private:
    double hourlyRate;
    int hoursWorked;

public:
    PartTimeEmployee();  // Default constructor
    ~PartTimeEmployee(); // Destructor

    int calculateSalary() const override; // Override calculateSalary
    void displayInfo() override;          // Override displayInfo

    // Setter methods
    void setHourlyRate(double rate);
    void setHoursWorked(int hours);

    // Getter methods
    double getHourlyRate() const;
    int getHoursWorked() const;
};

#endif // PARTTIMEEMPLOYEE_H
