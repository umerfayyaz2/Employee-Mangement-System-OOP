#include "person.h"
#include <cstring>
#include <cstdlib>
#include "input_validation.h"
#include <limits>
#include <cctype>
#include <ctime>

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

// Method to set all data
void Person::setData()
{
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
}

// Method to print all data
void Person::printData()
{
    cout << "Name: " << getName() << endl;
    cout << "Date of Birth: " << getDOB().getDay() << "/" << getDOB().getMonth() << "/" << getDOB().getYear() << endl;
    cout << "Phone Number: " << getPhoneNumber() << endl;
    cout << "Address: " << getAddress() << endl;
    cout << "Age: " << getAge() << endl;
}

// Setter methods
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
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
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

void Person::setAddress()
{
    while (true)
    {
        try
        {
            cout << "Enter address: ";
            cin.getline(address, 100);

            // Validate the input address
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
    // Calculate age based on current date and DOB
    time_t now = time(0);
    tm *currentTime = localtime(&now);
    int currentYear = 1900 + currentTime->tm_year;

    age = currentYear - dob.getYear();

    // Adjust age if birthday hasn't occurred this year yet
    if (currentTime->tm_mon + 1 < dob.getMonth() ||
        (currentTime->tm_mon + 1 == dob.getMonth() && currentTime->tm_mday < dob.getDay()))
    {
        age--;
    }
}

// Getter methods
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
