#include "iostream"
#include "JobRole.h"
#include "limits"
#include "input_validation.h"
#include <cctype>

using namespace std;

JobRole::JobRole()
{
    strcpy(roleName, "");
    baseSalary = 0;
}

JobRole::~JobRole() {}

// Function to convert a string to uppercase
void JobRole::toUpper(char *str)
{
    for (int i = 0; str[i] != '\0'; ++i)
    {
        str[i] = toupper(static_cast<unsigned char>(str[i]));
    }
}

// Function to validate that the role name contains only alphabets
void JobRole::string_validation(const char *str)
{
    // if (strcmp(str, "\n"))
    //     throw invalid_argument("Name contains non-alphabetic characters.");

    for (int i = 0; str[i] != '\0'; ++i)
    {
        if (isdigit(str[i]))
        {
            throw invalid_argument("Role name contains non-alphabetic characters.");
        }
    }
}

const char *JobRole::getRoleName()
{
    return roleName;
}

int JobRole::getBaseSalary()
{
    return baseSalary;
}

void JobRole::setRoleName()
{
    while (true)
    {
        try
        {
            cout << "Enter role name: ";
            cin.getline(roleName, 50);

            // Validate the input address
            if (strlen(roleName) == 0)
            {
                throw invalid_argument("Role name cannot be empty.");
            }

            // Validate the input role name
            string_validation(roleName);

            // Convert to uppercase
            toUpper(roleName);

            break;
        }
        catch (const invalid_argument &e)
        {
            cerr << "Error: " << e.what() << " Please enter role name in alphabets only." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void JobRole::setBaseSalary()
{
    int salary;

    while (true)
    {
        try
        {
            cout << "Enter base salary: ";
            int_validation(salary);

            // Validate the input to ensure it's an integer
            // if (cin.fail())
            // {
            //     throw invalid_argument("Input is not a valid integer.");
            // }

            // Validate the base salary value
            if (salary < 0)
            {
                throw invalid_argument("Base salary cannot be negative.");
            }

            // If the input is valid, break out of the loop
            break;
        }
        catch (const invalid_argument &e)
        {
            cerr << "Error: " << e.what() << " Please enter a valid base salary in terms of number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    baseSalary = salary;
}
