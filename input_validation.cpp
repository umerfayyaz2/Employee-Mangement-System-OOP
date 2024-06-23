#include "input_validation.h"
#include <limits> // For numeric_limits
#include <cstring>

// Function to clear the input buffer
void clear_input_buffer()
{
    char ch;
    while (cin.get(ch) && ch != '\n')
        ;
}

// Function to validate integer input
void int_validation(int &number)
{
    if (!(cin >> number) || cin.peek() != '\n')
    {
        clear_input_buffer(); // Clear the buffer
        throw invalid_argument("Input is not a valid integer.");
    }
    clear_input_buffer(); // Clear the buffer
}

// Function to validate string input
void name_validation(const string &input)
{
    for (char c : input)
    {
        if (isdigit(c))
        {
            throw runtime_error("Input contains numeric characters.");
        }
    }
}

// -> this is to be updated.
// void char_array_validation(const char *str)
// {
//     if (strcmp(str, "\n"))
//         throw invalid_argument("Name contains non-alphabetic characters.");

//     for (int i = 0; str[i] != '\0'; ++i)
//     {
//         if (isdigit(str[i]))
//         {
//             throw invalid_argument("Role name contains non-alphabetic characters.");
//         }
//     }
// }

// Function to validate char input
void char_validation(char &character)
{
    while (true)
    {
        try
        {
            if (!(cin >> character) || cin.peek() != '\n' || !isalpha(character))
            {
                throw invalid_argument("Input is not a valid character.");
            }
            break;
        }
        catch (const invalid_argument &e)
        {
            cerr << "Error: " << e.what() << " Please enter a valid character: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    clear_input_buffer(); // Clear the buffer
}

// Function to validate double input
void double_validation(double &number)
{
    while (true)
    {
        try
        {
            if (!(cin >> number) || cin.peek() != '\n')
            {
                throw invalid_argument("Input is not a valid double.");
            }
            break;
        }
        catch (const invalid_argument &e)
        {
            cerr << "Error: " << e.what() << " Please enter a valid double: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    clear_input_buffer(); // Clear the buffer
}

// Function to validate phone number input
void validate_phone_number(string &phoneNumber)
{
    while (true)
    {
        bool validPhoneNumber = true;
        for (char c : phoneNumber)
        {
            if (isalpha(c))
            {
                validPhoneNumber = false;
                break;
            }
        }
        if (validPhoneNumber)
        {
            break;
        }
        else
        {
            cout << "Invalid input. Please re-enter the phone number without alphabets: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> phoneNumber;
        }
    }
}
