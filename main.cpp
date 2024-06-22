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
    PartTimeEmployee pte1;

    pte1.set_partime_employee_details();

    pte1.displayInfo();

    return 0;
}

// g++ main.cpp person.cpp dateType.cpp Employee.cpp FullTimeEmployee.cpp input_validation.cpp PartTimeEmployee.cpp
