#include "JobRole.h"
#include "input_validation.h"

#include <iostream>
using namespace std;

JobRole::JobRole() : roleName(""), baseSalary(0)
{
}

JobRole::~JobRole() {}

const char *JobRole::getRoleName()
{
    return roleName;
}

int JobRole::getBaseSalary()
{
    return baseSalary;
}

void JobRole::setRoleName()
{
    validate_input_char_array(roleName, 50, "Enter role name: ");

    toUpper(roleName);
}

void JobRole::setBaseSalary()
{
    while (true)
    {
        validate_input_int(baseSalary, "Enter base salary:  ", "Invalid base salary, please try again...");

        if (baseSalary > 0)
            break;
    }
}
