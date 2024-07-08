#include "Employee.h"

#include <fstream>

int Employee::count = 1000;

int Employee::getNextId()
{
    return ++count;
}

Employee::Employee() : Person()
{
    setId();
}

Employee::Employee(int value) : Person()
{
}

Employee::Employee(const Employee &other) : Person(other), id(other.id) // copy constructor
{
    strcpy(jobRole, other.jobRole);
    // id = getNextId();
}

Employee::~Employee() {}

int Employee::getId() const
{
    return id;
}

void Employee::setId()
{
    int temp;
    ifstream fin("EmployeeId.txt");
    if (!fin)
    {
        validate_input_int(id, "Enter employee ID: ", "Invalid ID, please try again...");
        ofstream fout("EmployeeId.txt");
        fout << id;
        fout.close();
        return;
    }
    fin >> temp;
    while (1)
    {
        validate_input_int(id, "Enter employee ID: ", "Invalid ID, please try again...");

        if (id > temp)
        {
            break;
        }
        cout << "Employee cannot have duplicate id, please try again...\n";
    }
    fin.close();
    ofstream fout("EmployeeId.txt");
    fout << id;
    fout.close();
}

void Employee::displayInfo() const
{
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
    cout << "Job Role: " << jobRole << endl;
    cout << "Date of Birth: " << dob.getDay() << "/" << dob.getMonth() << "/" << dob.getYear() << endl;
    cout << "Phone Number: " << phoneNumber << endl;
    cout << "Address: " << address << endl;
    cout << "Age: " << age << endl;
}

const char *Employee::getJobRole()
{
    return jobRole;
}

void Employee::setJobRole()
{
    // cin.clear();
    // clear_input_buffer();
    validate_input_char_array(jobRole, 30, "Enter role name: ");

    toUpper(jobRole);
}

// ostream &operator<<(ostream &out, const Employee &emp)
// {
//     out << "Name: " << name << endl;
//     out << "ID: " << id << endl;
//     out << "Job Role: " << jobRole << endl;
//     out << "Date of Birth: " << dob.getDay() << "/" << dob.getMonth() << "/" << dob.getYear() << endl;
//     out << "Phone Number: " << phoneNumber << endl;
//     out << "Address: " << address << endl;
//     out << "Age: " << age << endl;
//     return out;
// }