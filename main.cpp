#include <iostream>
#include <iomanip>
#include "input_validation.h"
#include "person.h"
#include "dateType.h"
#include "Employee.h"
#include "FullTimeEmployee.h"
#include "PartTimeEmployee.h"
#include "EmployeeManager.h"

using namespace std;

void main_panel();

int main()
{
        main_panel();

        return 0;
}

#include <iostream>
#include <iomanip>
#include "EmployeeManager.h"
#include "input_validation.h"

void main_panel()
{
        EmployeeManager manager;
        int choice;

        while (true)
        {
                // Clear the screen (Note: system() is not portable, consider using a cross-platform alternative in production)
                system("cls");

                // Display the main menu
                cout << setfill('=') << setw(50) << "=" << endl;
                cout << setfill(' ') << setw(30) << "EMPLOYEE MANAGEMENT SYSTEM" << endl;
                cout << setfill('=') << setw(50) << "=" << endl;
                cout << setfill(' ');

                cout << setw(40) << left << "1. Add New Employee" << endl;
                cout << setw(40) << left << "2. View Employee Details" << endl;
                cout << setw(40) << left << "3. Update Employee Information" << endl;
                cout << setw(40) << left << "4. Delete Employee" << endl;
                cout << setw(40) << left << "5. Display All Employees" << endl;
                cout << setw(40) << left << "6. Exit" << endl;

                cout << setfill('-') << setw(50) << "-" << endl;
                cout << setfill(' ');

                validate_input_int(choice, "Enter your choice (1-6): ", "Invalid input. Please enter a number between 1 and 6.");

                switch (choice)
                {
                case 1:
                {
                        cout << "\n--- Adding New Employee ---\n"
                                  << endl;
                        manager.addEmployee();
                        cout << "\nEmployee added successfully!" << endl;
                        break;
                }
                case 2:
                {
                        cout << "\n--- Viewing Employee Details ---\n"
                                  << endl;
                        manager.viewEmployee();
                        break;
                }
                case 3:
                {
                        cout << "\n--- Updating Employee Information ---\n"
                                  << endl;
                        manager.updateEmployee();
                        cout << "\nEmployee information updated successfully!" << endl;
                        break;
                }
                case 4:
                {
                        cout << "\n--- Deleting Employee ---\n"
                                  << endl;
                        manager.deleteEmployee();
                        cout << "\nEmployee deleted successfully!" << endl;
                        break;
                }
                case 5:
                {
                        cout << "\n--- Displaying All Employees ---\n"
                                  << endl;
                        manager.displayEmployees();
                        break;
                }
                case 6:
                {
                        cout << "\nThank you for using the Employee Management System. Goodbye!" << endl;
                        return;
                }
                default:
                {
                        cout << "Invalid choice. Please try again." << endl;
                        break;
                }
                }

                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
        }
}

// g++ main.cpp person.cpp dateType.cpp Employee.cpp FullTimeEmployee.cpp input_validation.cpp PartTimeEmployee.cpp JobRole.cpp Salary.cpp
