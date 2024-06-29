#include <iostream>
// #include <limits>
// #include <string>
// #include <cstring>
#include "input_validation.h"
#include "person.h"
#include "dateType.h"
#include "Employee.h"
#include "FullTimeEmployee.h"
#include "PartTimeEmployee.h"
#include "JobRole.h"
#include "Salary.h"
#include "EmployeeManager.h"

using namespace std;

// dateType validation
// class EmployeeManager
// class FileManager

int main()
{
        FullTimeEmployee e1;

        e1.set_fulltime_employee_data();
        e1.printData();

        return 0;
}

// g++ main.cpp person.cpp dateType.cpp Employee.cpp FullTimeEmployee.cpp input_validation.cpp PartTimeEmployee.cpp JobRole.cpp Salary.cpp
