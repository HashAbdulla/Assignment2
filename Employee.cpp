#include "Employee.h"
#include <iostream>
using namespace std;


// Employee class 
Employee::Employee(const std::string& n, int id) : name(n), employeeID(id) {}

void Employee::displayInfo() const {
    cout << "Employee Name: " << name << endl;
    cout << "Employee ID: " << employeeID << endl;
}

// Professional //
Professional::Professional(const std::string& n, int id, double salary, int vacDays)
    : Employee(n, id), monthlySalary(salary), vacationDays(vacDays) {}

double Professional::calculateWeeklySalary() const {
    return monthlySalary / 4.0; 
}

double Professional::calculateHealthCareContributions() const {
    return 0.1 * monthlySalary; // 10% of monthly salary for health care
}

int Professional::calculateVacationDays() const {
    return vacationDays; // Use the pre-defined vacation days
}

void Professional::displayInfo() const {
    Employee::displayInfo(); //uses all functions to neatly show info about pro employee
    cout << "Employee Type: Professional" << endl;
    cout << "Monthly Salary: $" << monthlySalary << endl;
    cout << "Weekly Salary: $" << calculateWeeklySalary() << endl;
    cout << "Health Care Contributions: $" << calculateHealthCareContributions() << endl;
    std::cout << "Vacation Days: " << calculateVacationDays() << " days" << endl;
}

// Nonprofessional//
Nonprofessional::Nonprofessional(const std::string& n, int id, double rate, int hours)
    : Employee(n, id), hourlyRate(rate), hoursWorked(hours) {}

double Nonprofessional::calculateWeeklySalary() const {
    return hourlyRate * hoursWorked; // Weekly salary based on hourly rate and hours worked
}

double Nonprofessional::calculateHealthCareContributions() const {
    return 0.05 * calculateWeeklySalary(); // 5% of weekly salary for health care
}

int Nonprofessional::calculateVacationDays() const {
    return hoursWorked / 40; //  40 hours of work per week = 1 vacation day
}

void Nonprofessional::displayInfo() const {
    Employee::displayInfo(); ////uses all functions to neatly show info about nonpro employee
    cout << "Employee Type: Nonprofessional" << endl;
    cout << "Hourly Rate: $" << hourlyRate << endl;
    cout << "Hours Worked: " << hoursWorked << " hours" << endl;
    cout << "Weekly Salary: $" << calculateWeeklySalary() << endl;
    cout << "Health Care Contributions: $" << calculateHealthCareContributions() << endl;
    cout << "Vacation Days: " << calculateVacationDays() << " days" << endl;
}

