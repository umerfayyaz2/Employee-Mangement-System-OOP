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

using namespace std;

int main()
{
    FullTimeEmployee emp;

    // Set the full-time employee data
    set_fulltime_employee_data(emp);

    // Display the information
    emp.displayInfo();

    return 0;
}

// g++ main.cpp person.cpp dateType.cpp Employee.cpp FullTimeEmployee.cpp input_validation.cpp PartTimeEmployee.cpp
