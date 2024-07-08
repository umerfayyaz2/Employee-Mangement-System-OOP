#include "PartTimeEmployee.h"
#include "input_validation.h"

PartTimeEmployee::PartTimeEmployee()
{
    set_partime_employee_details();
}

PartTimeEmployee::PartTimeEmployee(const PartTimeEmployee &other) : Employee(other), hourlyRate(other.hourlyRate), hoursWorked(other.hoursWorked)
{
}

PartTimeEmployee::~PartTimeEmployee()
{
}

int PartTimeEmployee::calculateSalary() const
{
    return static_cast<int>(hourlyRate * hoursWorked);
}

void PartTimeEmployee::displayInfo() const
{
    Employee::displayInfo();
    cout << "Hourly Rate: " << hourlyRate << endl;
    cout << "Hours Worked: " << hoursWorked << endl;
    cout << "Salary: " << calculateSalary() << " $" << endl;
}

void PartTimeEmployee::setHourlyRate()
{
    while (true)
    {
        validate_input_double(hourlyRate, "\n\nEnter Hourly Rate (max range 80 $): ", "\nInvalid Hourly Rate, please try again...");

        if (hourlyRate >= 0 && hourlyRate <= 80)
            break;
    }
}

void PartTimeEmployee::setHoursWorked()
{
    while (true)
    {
        validate_input_int(hoursWorked, "\n\nEnter the Hours Worked (max 160 hours): ", "\nInvalid Working Hours, please try again...");

        if (hoursWorked > 0 && hoursWorked < 160)
            break;
    }
}

void PartTimeEmployee::set_partime_employee_details()
{
    this->setName();
    this->setDOB();
    this->setPhoneNumber();
    this->setAddress();
    this->setJobRole();
    this->setHourlyRate();
    this->setHoursWorked();
    this->setAge();
}

double PartTimeEmployee::getHourlyRate() const
{
    return hourlyRate;
}

int PartTimeEmployee::getHoursWorked() const
{
    return hoursWorked;
}

ostream &operator<<(ostream &out, const PartTimeEmployee &ptEmp)
{
    out << "Name: " << ptEmp.name << endl;
    out << "ID: " << ptEmp.id << endl;
    out << "Job Role: " << ptEmp.jobRole << endl;
    out << "Date of Birth: " << ptEmp.dob.getDay() << "/" << ptEmp.dob.getMonth() << "/" << ptEmp.dob.getYear() << endl;
    out << "Phone Number: " << ptEmp.phoneNumber << endl;
    out << "Address: " << ptEmp.address << endl;
    out << "Age: " << ptEmp.age << endl;
    out << "Hourly Rate: " << ptEmp.hourlyRate << endl;
    out << "Hours Worked: " << ptEmp.hoursWorked << endl;
    out << "Salary: " << ptEmp.calculateSalary() << " $" << endl;
    return out;
}