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
#include "Salary.h"
#include "EmployeeManager.h"

using namespace std;

// dateType validation
// class EmployeeManager
// class FileManager

int main()
{
        // JobRole e;
        // FullTimeEmployee e;
        // PartTimeEmployee e;
        // Salary s;

        // e.setRoleName();
        // e.setBaseSalary();

        // cout << "Employee's Job Role : " << e.getRoleName() << endl;

        // cout << "Employee's Base Salary: " << e.getBaseSalary();

        // e.set_partime_employee_details();

        // e.displayInfo();

        // s.displaySalary();

        JobRole e;

        e.setRoleName();

        cout << e.getRoleName() << endl;
        ;

        Salary s;

        s.setBaseSalary();

        s.displaySalary();

        return 0;
}

// g++ main.cpp person.cpp dateType.cpp Employee.cpp FullTimeEmployee.cpp input_validation.cpp PartTimeEmployee.cpp JobRole.cpp Salary.cpp
