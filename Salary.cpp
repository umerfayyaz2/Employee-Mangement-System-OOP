#include "Salary.h"
#include "input_validation.h"

#include <iostream>
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
    while (true)
    {
        validate_input_int(baseSalary, "Enter base salary (0-60000 $): ");

        if (baseSalary > 0 || baseSalary <= 60000)
            break;
    }

    calculateNetSalary();
}

void Salary::setBonus()
{
    while (true)
    {
        validate_input_int(bonus, "Enter bonus (0-10000 $): ");

        if (bonus > 0 || bonus <= 10000)
            break;
    }

    calculateNetSalary();
}

void Salary::setDeduction()
{
    while (true)
    {
        validate_input_int(deduction, "Enter deduction (0-60000 $): ");

        if (deduction > 0 || deduction <= 10000)
            break;
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
