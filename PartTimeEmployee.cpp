#include "PartTimeEmployee.h"
#include <iostream>
#include <limits>
#include <stdexcept>
#include "input_validation.h"  // Assuming this is where int_validation and double_validation are defined

using namespace std;

// Default constructor
PartTimeEmployee::PartTimeEmployee() : hourlyRate(0.0), hoursWorked(0) {}


// Destructor
PartTimeEmployee::~PartTimeEmployee() {}

// Override calculateSalary
int PartTimeEmployee::calculateSalary override()
{
    return hourlyRate * hoursWorked;
}

// Override displayInfo
void PartTimeEmployee::displayInfo() {
    Employee::displayInfo();
    cout << "Hourly Rate: " << hourlyRate << endl;
    cout << "Hours Worked: " << hoursWorked << endl;
    cout << "Total Salary: " << calculateSalary() << endl;
}

// Set methods
void PartTimeEmployee::setHourlyRate() {
    while (true) {
        try {
            cout << "Enter Hourly Rate: ";
            double tempRate;
            cin >> tempRate;

            // Check if input is a valid double and not a failure state
            if (cin.fail()) {
                throw invalid_argument("Invalid hourly rate input.");
            }

            // Assuming double_validation checks if the double is within an acceptable range
            double_validation(tempRate);

            hourlyRate = tempRate;
            break;
        } catch (const invalid_argument& e) {
            cerr << "Error: " << e.what() << ". Please enter a valid hourly rate." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void PartTimeEmployee::setHoursWorked() {
    while (true) {
        try {
            cout << "Enter Hours Worked: ";
            int tempHours;
            cin >> tempHours;

            // Check if input is a valid integer and not a failure state
            if (cin.fail()) {
                throw invalid_argument("Invalid hours worked input.");
            }

            // Assuming int_validation checks if the integer is within an acceptable range
            int_validation(tempHours);

            hoursWorked = tempHours;
            break;
        } catch (const invalid_argument& e) {
            cerr << "Error: " << e.what() << ". Please enter a valid number of hours." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

// Get methods
double PartTimeEmployee::getHourlyRate() const {
    return hourlyRate;
}

int PartTimeEmployee::getHoursWorked() const {
    return hoursWorked;
}
