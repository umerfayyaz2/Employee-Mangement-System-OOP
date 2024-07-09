#include "input_validation.h"
#include <stdexcept>

void clear_input_buffer()
{
    cin.ignore(10000, '\n');
}

void validate_input_int(int &number, const string &promptMessage, const string &errorMessage)
{
    while (true)
    {
        try
        {
            cout << promptMessage;
            if (!(cin >> number) || cin.peek() != '\n')
            {
                throw invalid_argument(errorMessage);
            }
            clear_input_buffer();

            break;
        }
        catch (const invalid_argument &e)
        {
            cerr << "Error: " << e.what() << "\n";
            cin.clear();
            clear_input_buffer();
        }
    }
}

void validate_string(string &input, const string &promptMessage, const string &errorMessage)
{
    for (char c : input)
    {
        if (isDigit(c))
        {
            throw runtime_error("Input contains numeric characters.");
        }
    }
}

void validate_input_char_array(char *str, int size, const string &promptMessage)
{
    while (true)
    {
        try
        {
            cout << promptMessage;
            cin.getline(str, size);

            int strSize = 0;
            while (str[strSize] != '\0')
                strSize++;

            if (cin.fail())
            {
                clear_input_buffer();
                throw invalid_argument("Field input failed, too long..");
            }

            if (strSize == 0)
                throw invalid_argument("Field cannot be empty, please try again...");

            for (int i = 0; i < strSize; i++)
            {
                if (isDigit(str[i]))
                    throw invalid_argument("Field cannot contain digits.");
            }

            break;
        }
        catch (const invalid_argument &e)
        {
            cerr << "Error: " << e.what() << "\n";
            cin.clear();
            clear_input_buffer();
        }
    }
}
void validate_input_char_array_with_numbers(char *str, int size, const string &promptMessage)
{
    while (true)
    {
        try
        {
            cout << promptMessage;
            cin.getline(str, size);

            int strSize = 0;
            while (str[strSize] != '\0')
                strSize++;

            if (cin.fail())
            {
                clear_input_buffer();
                throw invalid_argument("Field input failed, too long..");
            }

            if (strSize == 0)
                throw invalid_argument("Field cannot be empty, please try again...");

            break;
        }
        catch (const invalid_argument &e)
        {
            cerr << "Error: " << e.what() << "\n";
            cin.clear();
            clear_input_buffer();
        }
    }
}

void validate_input_char(char &character, const string &promptMessage, const string &errorMessage)
{
    while (true)
    {
        try
        {
            cout << promptMessage;
            if (!(cin >> character) || cin.peek() != '\n')
            {
                throw invalid_argument(errorMessage);
            }
            clear_input_buffer();

            break;
        }
        catch (const invalid_argument &e)
        {
            cerr << "Error: " << e.what() << "\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}

void validate_input_double(double &number, const string &promptMessage, const string &errorMessage)
{
    while (true)
    {
        try
        {
            cout << promptMessage;
            if (!(cin >> number) || cin.peek() != '\n')
            {
                throw invalid_argument(errorMessage);
            }
            clear_input_buffer();

            break;
        }
        catch (invalid_argument &e)
        {
            cerr << "Error: " << e.what() << "\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}

void validate_input_phone_number(char *phoneNumber, const string &promptMessage)
{
    while (true)
    {
        try
        {
            cout << promptMessage;
            cin.getline(phoneNumber, PHONE_NUMBER_SIZE);

            int phoneNumberSize = 0;
            while (phoneNumber[phoneNumberSize] != '\0')
                phoneNumberSize++;

            if (cin.fail() || phoneNumberSize == 0)
            {
                clear_input_buffer();
                throw invalid_argument("Field input failed, too long..");
            }

            if (phoneNumberSize == 0)
                throw invalid_argument("Field cannot be empty, please try again...");

            for (int i = 0; i < phoneNumberSize; i++)
            {
                if (isAlpha(phoneNumber[i]))
                    throw invalid_argument("Field cannot contain alphabets...");
            }

            break;
        }
        catch (const invalid_argument &e)
        {
            cerr << "Error: " << e.what() << "\n";
            cin.clear();
            clear_input_buffer();
        }
    }
}

bool isAlpha(char character)
{
    if ((character >= 65 && character <= 90) || (character >= 97 && character <= 122))
        return (true);
    return (false);
}

bool isDigit(char digit)
{
    return (digit >= '0' && digit <= '9');
}

void toUpper(char *str)
{
    for (int i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] >= 97 && str[i] <= 122)
            str[i] -= 32;
    }
}