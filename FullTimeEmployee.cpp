#include "FullTimeEmployee.h"
#include "input_validation.h"

FullTimeEmployee::FullTimeEmployee()
{
    set_fulltime_employee_data();
}

FullTimeEmployee::FullTimeEmployee(const FullTimeEmployee &other) : Employee(other), monthlySalary(other.monthlySalary)
{
}

FullTimeEmployee::~FullTimeEmployee()
{
}

void FullTimeEmployee::set_fulltime_employee_data()
{
    this->setName();
    this->setDOB();
    this->setPhoneNumber();
    this->setAddress();
    this->setJobRole();
    this->setMonthlySalary();
    this->setAge();
}

int FullTimeEmployee::calculateSalary() const
{
    return monthlySalary;
}

void FullTimeEmployee::displayInfo() const
{
    Employee::displayInfo();
    cout << "\nMonthly Salary: " << monthlySalary << " $" << endl;
}

void FullTimeEmployee::setMonthlySalary()
{
    while (true)
    {

        validate_input_int(monthlySalary, "\nEnter the salary (max 60k $): ", "\nInvalid salary, please try again...");

        if (monthlySalary > 0 && monthlySalary <= 60000)
            break;
    }
}

int FullTimeEmployee::getMonthlySalary() const
{
    return monthlySalary;
}

ostream &operator<<(ostream &out, const FullTimeEmployee &ftEmp)
{
    out << "Name: " << ftEmp.name << endl;
    out << "ID: " << ftEmp.id << endl;
    out << "Job Role: " << ftEmp.jobRole << endl;
    out << "Date of Birth: " << ftEmp.dob.getDay() << "/" << ftEmp.dob.getMonth() << "/" << ftEmp.dob.getYear() << endl;
    out << "Phone Number: " << ftEmp.phoneNumber << endl;
    out << "Address: " << ftEmp.address << endl;
    out << "Age: " << ftEmp.age << endl;
    out << "Monthly Salary: " << ftEmp.monthlySalary << " $" << endl;
    return out;
}