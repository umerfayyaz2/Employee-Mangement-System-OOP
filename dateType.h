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
    //    dateType(int dd , int mm , int yyyy);
    virtual ~dateType();

    bool check_leap_year() const;

    void setDay();
    void setMonth();
    void setYear();

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    virtual void printDate();
};

#endif // DATETYPE_H_INCLUDED
