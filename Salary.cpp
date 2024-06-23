#include "Salary.h"
#include <iostream>
#include <stdexcept>
#include <limits>
#include "input_validation.h"

using namespace std;

Salary::Salary()
{
    setBaseSalary();
    setBonus();
    setDeduction();
}

Salary::~Salary() {}

void Salary::calculateNetSalary()
{
    netSalary = baseSalary + bonus - deduction;
}

void Salary::displaySalary() const
{
    cout << "Base Salary: " << baseSalary << " $" << endl;
    cout << "Bonus: " << bonus << " $" << endl;
    cout << "Deduction: -" << deduction << " $" << endl;
    cout << "Net Salary: " << netSalary << " $" << endl;
}

void Salary::setBaseSalary()
{
    int attempts = 0;
    while (true)
    {
        try
        {
            if (attempts >= 3)
            {
                throw invalid_argument("Too many invalid attempts. Please try again later.");
            }
            cout << "Enter Base Salary: ";
            int_validation(baseSalary);
            if (baseSalary < 0 || baseSalary > 60000)
                throw invalid_argument("Base salary range should be between (0-60000)");
            break;
        }
        catch (invalid_argument &e)
        {
            cerr << "Error: " << e.what() << " Please enter a valid base salary in terms of number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            attempts++;
        }
    }

    calculateNetSalary();
}

void Salary::setBonus()
{
    int attempts = 0;
    while (true)
    {
        try
        {
            if (attempts >= 3)
            {
                throw invalid_argument("Too many invalid attempts. Please try again later.");
            }
            cout << "Enter Bonus: ";
            int_validation(bonus);
            if (bonus < 0 || bonus > 10000)
                throw invalid_argument("Bonus range should be between (0-10000)");
            break;
        }
        catch (invalid_argument &e)
        {
            cerr << "Error: " << e.what() << " Please enter a valid bonus in terms of number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            attempts++;
        }
    }

    calculateNetSalary();
}

void Salary::setDeduction()
{
    int attempts = 0;
    while (true)
    {
        try
        {
            if (attempts >= 3)
            {
                throw invalid_argument("Too many invalid attempts. Please try again later.");
            }
            cout << "Enter Deduction: ";
            int_validation(deduction);
            if (deduction < 0 || deduction > 60000)
                throw invalid_argument("Deduction range should be between (0-60000)");
            break;
        }
        catch (invalid_argument &e)
        {
            cerr << "Error: " << e.what() << " Please enter a valid deduction in terms of number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            attempts++;
        }
    }

    calculateNetSalary();
}

int Salary::getBaseSalary() const
{
    return baseSalary;
}

int Salary::getBonus() const
{
    return bonus;
}

int Salary::getDeduction() const
{
    return deduction;
}

int Salary::getNetSalary() const
{
    return netSalary;
}
