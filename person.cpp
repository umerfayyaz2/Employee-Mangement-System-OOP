#include "Person.h"
#include <cstring>
#include <cstdlib>
#include "input_validation.h"
#include <limits>
#include <cctype>

// Default constructor
Person::Person() : age(0)
{
    strcpy(name, "");
    strcpy(phoneNumber, "");
    strcpy(address, "");
}

// Destructor
Person::~Person() {}

// Function to convert a string to uppercase
void toUpper(char *str)
{
    for (int i = 0; str[i] != '\0'; ++i)
    {
        str[i] = std::toupper(static_cast<unsigned char>(str[i]));
    }
}

// Friend function to set all data
void setData(Person &p)
{
    p.setName();
    system("Cls");
    p.setDOB();
    system("Cls");
    p.setPhoneNumber();
    system("Cls");
    p.setAddress();
    system("Cls");
    p.setAge();
    system("Cls");
}

// Friend function to print all data
void printData(Person &p)
{
    cout << "Name: " << p.getName() << endl;
    cout << "Date of Birth: " << p.getDOB().getDay() << "/" << p.getDOB().getMonth() << "/" << p.getDOB().getYear() << endl;
    cout << "Phone Number: " << p.getPhoneNumber() << endl;
    cout << "Address: " << p.getAddress() << endl;
    cout << "Age: " << p.getAge() << endl;
}

// Set methods
void Person::setName()
{
    while (true)
    {
        try
        {
            cout << "Enter name: ";
            cin.getline(name, 50);

            // Validate the input name
            string_validation(name);

            break;
        }
        catch (const invalid_argument &e)
        {
            cerr << "Error: " << e.what() << " Please enter name in alphabets only." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Fixed parentheses error
        }
    }
    toUpper(name);
}

void Person::setDOB()
{
    cout << "<--------- Setting Date Of Birth Details --------->" << endl;
    dob.setDay();
    dob.setMonth();
    dob.setYear();
}

// Function to set the phone number with validation
void Person::setPhoneNumber()
{
    while (true)
    {
        try
        {
            cout << "Enter phone number: ";
            cin.getline(phoneNumber, 20);

            // Validate the input phone number
            phone_validation(phoneNumber);

            break;
        }
        catch (const invalid_argument &e)
        {
            cerr << "Error: " << e.what() << " Please enter a valid phone number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

// Function to set the address with validation
void Person::setAddress()
{
    while (true)
    {
        try
        {
            cout << "Enter address: ";
            cin.getline(address, 100);

            // Assuming we need a simple validation for address
            // For this example, let's just check if the address is not empty
            if (strlen(address) == 0)
            {
                throw invalid_argument("Address cannot be empty.");
            }

            break;
        }
        catch (const invalid_argument &e)
        {
            cerr << "Error: " << e.what() << " Please enter a valid address." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    toUpper(address);
}

void Person::setAge()
{
    int currentYear = 2024;
    age = currentYear - dob.getYear();
}

// Get methods
const char *Person::getName()
{
    return name;
}

dateType Person::getDOB()
{
    return dob;
}

const char *Person::getPhoneNumber()
{
    return phoneNumber;
}

const char *Person::getAddress()
{
    return address;
}

int Person::getAge()
{
    return age;
}

void Person::string_validation(const char *str)
{
    for (int i = 0; str[i] != '\0'; ++i)
    {
        if (isdigit(str[i]))
        {
            throw invalid_argument("Name contains non-alphabetic characters.");
        }
    }
}

// Function to validate that the phone number contains only digits
void Person::phone_validation(const char *str)
{
    for (int i = 0; str[i] != '\0'; ++i)
    {
        if (isalpha(str[i]))
        {
            throw invalid_argument("Phone number contains non-numeric characters.");
        }
    }
}
