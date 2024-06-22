#include "Employee.h"

int Employee::id = 1000;

int Employee::getNextId()
{
    return ++id;
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
    cout << "Name: " << getName() << endl;
    cout << "ID: " << id << endl;
    cout << "Date of Birth: " << dob.getDay() << "/" << dob.getMonth() << "/" << dob.getYear() << endl;
    cout << "Phone Number: " << getPhoneNumber() << endl;
    cout << "Address: " << getAddress() << endl;
    cout << "Age: " << getAge() << endl;
}
