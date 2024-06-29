#ifndef DATETYPE_H_INCLUDED
#define DATETYPE_H_INCLUDED

#include <iostream>
using namespace std;

class dateType
{
protected:
    int day;
    int month;
    int year;

public:
    dateType();
    virtual ~dateType();

    bool check_leap_year() const;

    // void setDay();
    // void setMonth();
    // void setYear();
    void setDate(); // changes in Person.h are required

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    virtual void printDate();
};

#include "dateType.cpp"

#endif // DATETYPE_H_INCLUDED
