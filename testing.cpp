#include <iostream>
#include "EmployeeManager.h"

using namespace std;

int main()
{

    EmployeeManager manager;

    manager.addEmployee();
    // manager.addEmployee();

    // manager.viewEmployee();
    // manager.viewEmployee();

    // cout << "Added.\n";

    manager.displayEmployees();

    return (0);
}