#ifndef EMPLOYEE_H //so that it wont be included multiple times
#define EMPLOYEE_H

#include <string>

class Employee {
protected:
    std::string name;
    int employeeID;

public:
    Employee(const std::string& n, int id); 
    virtual ~Employee() {} 

    virtual double calculateWeeklySalary() const = 0;
    virtual double calculateHealthCareContributions() const = 0;
    virtual int calculateVacationDays() const = 0;
    virtual void displayInfo() const;
};

class Professional : public Employee {
private:
    double monthlySalary;
    int vacationDays;

public:
    Professional(const std::string& n, int id, double salary, int vacDays);

    double calculateWeeklySalary() const override;
    double calculateHealthCareContributions() const override;
    int calculateVacationDays() const override;
    void displayInfo() const override;
};

class Nonprofessional : public Employee {
private:
    double hourlyRate;
    int hoursWorked;

public:
    Nonprofessional(const std::string& n, int id, double rate, int hours);

    double calculateWeeklySalary() const override;
    double calculateHealthCareContributions() const override;
    int calculateVacationDays() const override;
    void displayInfo() const override;
};

#endif