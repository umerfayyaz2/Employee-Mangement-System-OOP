#ifndef PARTTIMEEMPLOYEE_H
#define PARTTIMEEMPLOYEE_H

#include "Employee.h"

// NEED TO SET A METHOD TO GET SALARY DETAILS WITH RESPECT TO HOURS WORKED AND HOURLY RATE
class PartTimeEmployee : public Employee
{
private:
    double hourlyRate;
    int hoursWorked;

public:
    PartTimeEmployee(); // Default constructor
    PartTimeEmployee(int) : Employee(1) {}
    PartTimeEmployee(const PartTimeEmployee &other);
    ~PartTimeEmployee(); // Destructor

    int calculateSalary() const override; // Override calculateSalary
    void displayInfo() override;          // Override displayInfo

    // Setter methods
    void setHourlyRate();
    void setHoursWorked();
    void set_partime_employee_details();

    // Getter methods
    double getHourlyRate() const;
    int getHoursWorked() const;
};

#include "PartTimeEmployee.cpp"

#endif // PARTTIMEEMPLOYEE_H
