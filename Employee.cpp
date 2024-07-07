#include "Employee.h"

#include <fstream>

int Employee::count = 1000;

int Employee::getNextId()
{
    return ++count;
}

Employee::Employee() : Person()
{
    validate_input_int(id, "Enter employee ID: ", "Invalid ID, please try again...");
}

Employee::Employee(int value) : Person()
{
}

Employee::Employee(const Employee &other) : Person(other), id(other.id) // copy constructor
{
    strcpy(jobRole, other.jobRole);
    // id = getNextId();
}

Employee::~Employee() {}

int Employee::getId() const
{
    return id;
}

void Employee::displayInfo()
{
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
    cout << "Job Role: " << jobRole << endl;
    cout << "Date of Birth: " << dob.getDay() << "/" << dob.getMonth() << "/" << dob.getYear() << endl;
    cout << "Phone Number: " << phoneNumber << endl;
    cout << "Address: " << address << endl;
    cout << "Age: " << age << endl;
}

const char *Employee::getJobRole()
{
    return jobRole;
}

void Employee::setJobRole()
{
    // cin.clear();
    clear_input_buffer();
    validate_input_char_array(jobRole, 50, "Enter role name: ");

    toUpper(jobRole);
}