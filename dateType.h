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



    void setDay();
    void setMonth();
    void setYear();

    int getDay();
    int getMonth();
    int getYear();

    virtual void printDate();
};

#endif // DATETYPE_H_INCLUDED
