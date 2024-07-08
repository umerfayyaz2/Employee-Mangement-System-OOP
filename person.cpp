#include "person.h"
#include "input_validation.h"
#include "screen.h"

#include <ctime>
#include <cstring>

#include <iostream>
using namespace std;

// Default constructor
Person::Person() : name(""), age(0), phoneNumber(""), address("")
{
}

Person::Person(const Person &other)
{
    strcpy(name, other.name);
    dob = other.dob;
    strcpy(phoneNumber, other.phoneNumber);
    strcpy(address, other.address);
    age = other.age;
}

// Destructor
Person::~Person() {}

// Method to set all data
void Person::setData()
{
    setName();
    system("Cls");

    setDOB();
    system("Cls");

    setPhoneNumber();
    system("Cls");

    setAddress();
    system("Cls");

    setAge();
    system("Cls");
}

// Setter methods
void Person::setName()
{
    validate_input_char_array(name, 50, "\nEnter Name: ");
    toUpper(name);
}

void Person::setDOB()
{
    cout << "\n---- Setting Date Of Birth Details ----\n"
         << endl;
    dob.setDate();
}

void Person::setPhoneNumber()
{
    validate_input_phone_number(phoneNumber, "\nEnter Phone Number: ");
}

void Person::setAddress()
{
    validate_input_char_array_with_numbers(address, 100, "\nEnter Address: ");
    toUpper(address);
}

void Person::setAge()
{
    // Calculate age based on current date and DOB
    time_t now = time(0);
    tm *currentTime = localtime(&now);
    int currentYear = 1900 + currentTime->tm_year;

    age = currentYear - dob.getYear();

    // Adjust age if birthday hasn't occurred this year yet
    if (currentTime->tm_mon + 1 < dob.getMonth() ||
        (currentTime->tm_mon + 1 == dob.getMonth() && currentTime->tm_mday < dob.getDay()))
    {
        age--;
    }
}

// Getter methods
const char *Person::getName()
{
    return name;
}

dateType Person::getDOB()
{
    return dob;
}

const char *Person::getPhoneNumber()
{
    return phoneNumber;
}

const char *Person::getAddress()
{
    return address;
}

int Person::getAge()
{
    return age;
}