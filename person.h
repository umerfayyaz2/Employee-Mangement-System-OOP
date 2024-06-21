#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

#include <iostream>
#include "dateType.h"

using namespace std;

class Person {
protected:
    char name[50];
    dateType dob;  // dateType object to store date of birth
    char phoneNumber[20];
    char address[100];
    int age;
public:
    Person();
    virtual ~Person();
    void string_validation(const char* str);
    void phone_validation(const char* str); // Placeholder for phone number validation

    // Declare setData and printData as friend functions
    friend void setData(Person& p);
    friend void printData(Person& p);

    void setName();
    void setDOB();
    void setPhoneNumber();
    void setAddress();
    void setAge();  // Function to calculate and set age

    const char* getName();
    dateType getDOB();  // Return dateType object for date of birth
    const char* getPhoneNumber();
    const char* getAddress();
    int getAge();  // Function to get age
};

#endif // PERSON_H_INCLUDED
