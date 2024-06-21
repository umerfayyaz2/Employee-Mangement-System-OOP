#include "Employee.h"

int Employee::id = 1000;

int Employee::getNextId() {
    return ++id;
}

Employee::Employee() : Person() {  // Initialize the base class Person
    id = getNextId();
}

Employee::~Employee() {}

int Employee::getId() const {
    return id;
}

void Employee::displayInfo() {
    cout << "Name: " << getName() << endl;  // Use the getter methods from Person class
    cout << "ID: " << id << endl;
    cout << "Date of Birth: " << dob.getDay() << "/" << dob.getMonth() << "/" << dob.getYear() << endl;
    cout << "Phone Number: " << getPhoneNumber() << endl;
    cout << "Address: " << getAddress() << endl;
    cout << "Age: " << getAge() << endl;
}

// Friend function to set all data
void setData(Employee& e) {
    e.setName();
    system("Cls");
    e.setDOB();
    system("Cls");
    e.setPhoneNumber();
    system("Cls");
    e.setAddress();
    system("Cls");
    e.setAge();
    system("Cls");
    // Salary input could be added here if required
}

// Friend function to print all data
void printData(Employee& e) {
    cout << "Name: " << e.getName() << endl;
    cout << "ID: " << e.getId() << endl;  // Include ID
    cout << "Date of Birth: " << e.getDOB().getDay() << "/" << e.getDOB().getMonth() << "/" << e.getDOB().getYear() << endl;
    cout << "Phone Number: " << e.getPhoneNumber() << endl;
    cout << "Address: " << e.getAddress() << endl;
    cout << "Age: " << e.getAge() << endl;
    cout << "Salary: " << e.calculateSalary() << endl; // Display salary
}
