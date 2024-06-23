#ifndef SALARY_H_INCLUDED
#define SALARY_H_INCLUDED

class Salary
{
private:
    int baseSalary;
    int bonus;
    int deduction;
    int netSalary;

public:
    Salary();
    ~Salary();

    void calculateNetSalary();
    void displaySalary() const;

    void setBaseSalary();
    void setBonus();
    void setDeduction();
    void setNetSalary();

    int getBaseSalary() const;
    int getBonus() const;
    int getDeduction() const;
    int getNetSalary() const;
};

#endif // SALARY_H_INCLUDED