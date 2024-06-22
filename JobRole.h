#ifndef JOBROLE_H_INCLUDED
#define JOBROLE_H_INCLUDED

#include <iostream>
#include <cstring>
#include <stdexcept>
#include "input_validation.h"

class JobRole
{
private:
    char roleName[50];
    int baseSalary;

    // Function to convert a string to uppercase
    void toUpper(char *str);

    // Function to validate that the role name contains only alphabets
    void string_validation(const char *str);

public:
    JobRole();
    ~JobRole();

    const char *getRoleName();
    int getBaseSalary();

    void setRoleName();
    void setBaseSalary();
};

#endif // JOBROLE_H_INCLUDED
