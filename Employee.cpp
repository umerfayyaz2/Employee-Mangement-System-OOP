#include "Employee.h"

#include <iostream>

using namespace std;

int Employee::count = 1000;

int Employee::getNextId()
{
    return ++count;
}

Employee::Employee() : Person()
{
    id = getNextId();
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
    validate_input_char_array(jobRole, 50, "Enter role name: ");

    toUpper(jobRole);
}