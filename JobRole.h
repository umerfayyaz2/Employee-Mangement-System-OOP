#ifndef JOBROLE_H_INCLUDED
#define JOBROLE_H_INCLUDED

class JobRole
{
private:
    char roleName[50];
    int baseSalary;

public:
    JobRole();
    ~JobRole();

    const char *getRoleName();
    int getBaseSalary();

    void setRoleName();
    void setBaseSalary();
};

#include "JobRole.cpp"

#endif // JOBROLE_H_INCLUDED