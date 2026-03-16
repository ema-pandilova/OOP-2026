#include <iostream>
#include <cstring>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int _day = 13, int _month = 3, int _year = 2026) {
        day = _day;
        month = _month;
        year = _year;
    }

    void print() {
        cout << day << "." << month << "." << year;
    }
};

class Employee {
private:
    char name[20];
    double salary;
    Date dob;

public:
    Employee(char *_name = "", double _salary = 12000, Date _dob = Date()) {
        strcpy(name, _name);
        salary = _salary;
        dob = _dob;
    }

    void print() {
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;

        cout << "Date of birth: ";
        dob.print();
        cout << endl;
    }

    double getSalary() {
        return salary;
    }

    void increaseSalary() {
        salary += 2000;
    }
};

class Company {
private:
    char name[50];
    int totalEmployees;
    Employee employees[50];

public:

    Company(char *_name = "", int _totalEmployees = 0, Employee _employees[] = nullptr) {
        strcpy(name, _name);
        totalEmployees = _totalEmployees;

        for (int i = 0; i < totalEmployees; i++) {
            employees[i] = _employees[i];
        }
    }

    void addEmployee(Employee &_employee) {
        employees[totalEmployees++] = _employee;
    }

    void print() {
        cout << "Company: " << name << endl;

        for (int i = 0; i < totalEmployees; i++) {
            cout << "Employee " << i + 1 << ":" << endl;
            employees[i].print();
            cout << endl;
        }
    }

    Employee &highestPaidEmployee() {

        int index = 0;

        for (int i = 1; i < totalEmployees; i++) {
            if (employees[i].getSalary() > employees[index].getSalary()) {
                index = i;
            }
        }

        return employees[index];
    }
};

int main() {

    char companyName[50];
    cin >> companyName;

    int n;
    cin >> n;

    Employee employees[50];

    for (int i = 0; i < n; i++) {

        char name[20];
        double salary;
        int day, month, year;

        cin >> name >> salary >> day >> month >> year;

        employees[i] = Employee(name, salary, Date(day, month, year));
    }

    Company c(companyName, n, employees);

    c.print();

    cout << "Highest paid employee:" << endl;
    c.highestPaidEmployee().print();

    c.highestPaidEmployee().increaseSalary();

    cout << "After salary increase:" << endl;
    c.print();

    return 0;
}