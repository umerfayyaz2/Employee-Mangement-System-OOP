#ifndef PARTTIMEEMPLOYEE_H
#define PARTTIMEEMPLOYEE_H

#include "Employee.h"

class PartTimeEmployee : public Employee {
private:
    double hourlyRate;
    int hoursWorked;

public:
    PartTimeEmployee();

    ~PartTimeEmployee();

    int calculateSalary() override;
    void displayInfo() override;

    void setHourlyRate();
    void setHoursWorked();
    double getHourlyRate() const;
    int getHoursWorked() const;
};

#endif // PARTTIMEEMPLOYEE_H
