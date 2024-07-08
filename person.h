#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

#include "dateType.h"

class Person
{
protected:
    char name[50];
    dateType dob; // dateType object to store date of birth
    char phoneNumber[20];
    char address[100];
    int age;

public:
    Person();
    Person(const Person &other) ;
    virtual ~Person();

    // Methods to set and print data
    void setData();
    virtual void displayInfo() const = 0;

    // Setter methods
    void setName();
    void setDOB();
    void setPhoneNumber();
    void setAddress();
    void setAge(); // Function to calculate and set age

    // Getter methods
    const char *getName();
    dateType getDOB(); // Return dateType object for date of birth
    const char *getPhoneNumber();
    const char *getAddress();
    int getAge(); // Function to get age
};

#include "person.cpp"

#endif // PERSON_H_INCLUDED
