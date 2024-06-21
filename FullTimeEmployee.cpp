#include "FullTimeEmployee.h"
#include "input_validation.h"
#include <iostream>
#include <limits>

// Default constructor
FullTimeEmployee::FullTimeEmployee() : Employee(), monthlySalary(0) {}

// Destructor
FullTimeEmployee::~FullTimeEmployee() {}

// Override calculateSalary
int FullTimeEmployee::calculateSalary() const {
    return monthlySalary;
}

// Override displayInfo
void FullTimeEmployee::displayInfo() {
    Employee::displayInfo();
    cout << "Monthly Salary: " << monthlySalary << endl;
}

// Getter for monthlySalary
int FullTimeEmployee::getMonthlySalary() const {
    return monthlySalary;
}

// Setter for monthlySalary
void FullTimeEmployee::setMonthlySalary() {
    while (true) {
        try {
            cout << "Enter Monthly Salary: ";
            int tempSalary;
            cin >> tempSalary;

            // Check if input is a valid integer and not a failure state
            if (cin.fail()) {
                throw invalid_argument("Invalid salary input.");
            }

            // Assuming int_validation checks if the integer is within an acceptable range
            int_validation(tempSalary);

            monthlySalary = tempSalary;
            break;
        } catch (const invalid_argument& e) {
            cerr << "Error: " << e.what() << ". Please enter a valid integer." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

// Set data for FullTimeEmployee
void FullTimeEmployee::setData() {
    setName();
    system("Cls");
    setDOB();
    system("Cls");
    setPhoneNumber();
    system("Cls");
    setAddress();
    system("Cls");
    setAge();
    system("Cls");

    while (true) {
        try {
            cout << "Enter monthly salary: ";
            cin >> monthlySalary;
            if (cin.fail()) {
                throw invalid_argument("Invalid salary input.");
            }
            break;
        } catch (const invalid_argument& e) {
            cerr << "Error: " << e.what() << " Please enter a valid salary." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

// Print data for FullTimeEmployee
void FullTimeEmployee::printData() {
    cout << "Name: " << getName() << endl;
    cout << "Date of Birth: " << dob.getDay() << "/" << dob.getMonth() << "/" << dob.getYear() << endl;
    cout << "Phone Number: " << getPhoneNumber() << endl;
    cout << "Address: " << getAddress() << endl;
    cout << "Age: " << getAge() << endl;
    cout << "Monthly Salary: " << monthlySalary << endl;
}
