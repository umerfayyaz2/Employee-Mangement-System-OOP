#include <iostream>
#include <limits>
#include <string>
#include <cstring>
#include "input_validation.h"
#include "person.h"
#include "dateType.h"
#include "Employee.h"
#include "FullTimeEmployee.h"
#include "PartTimeEmployee.h"
#include "JobRole.h"

using namespace std;

int main()
{
        JobRole e;

        e.getRoleName();
        e.setBaseSalary();

        cout << "Employee's Job Role : " << e.getRoleName() << endl;

        cout << "Employee's Base Salary: " << e.getBaseSalary();

        return 0;
}

// g++ main.cpp person.cpp dateType.cpp Employee.cpp FullTimeEmployee.cpp input_validation.cpp PartTimeEmployee.cpp JobRole.cpp
