//
// Created by ema on 30.3.26.
//
#include <iostream>
#include <cstring>
#include <cctype>
#include <ostream>
using namespace std;

class Student {
private:
    char id[7];
    char *name;
    double averageGrade;
    int year;

public:
    Student(char *id = "", char *name = "", double averageGrade = 5.0, int year = 1) {
        strcpy(this->id, id);
        this->averageGrade = averageGrade;
        this->year = year;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    ~Student() {
        delete [] name;
    }

    Student(const Student &other) {
        strcpy(this->id, other.id);
        this->averageGrade = other.averageGrade;
        this->year = other.year;
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
    }

    Student &operator=(const Student &other) {
        if (this != &other) {
            delete [] name;
            strcpy(this->id, other.id);
            this->averageGrade = other.averageGrade;
            this->year = other.year;
            this->name = new char[strlen(other.name) + 1];
            strcpy(this->name, other.name);
        }
        return *this;
    }

    Student &operator ++() {
        ++year;
        return *this;
    }

    Student operator ++(int) {
        Student temp(*this); //copy constuctor
        ++year;
        return temp;
    }

    friend ostream &operator <<(ostream &out, Student &student) {
        out << "Indeks: " << student.id << endl;
        out << "Name: " << student.name << endl;
        out << "Average: " << student.averageGrade << endl;
        out << "Year: " << student.year << endl;
        return out;
    }

    friend istream &operator >>(istream &in, Student &student) {
        char id[7];
        char name[20];
        double averageGrade;
        int year;
        in.getline(id, 7);
        in.getline(name, 20);
        in >> averageGrade;
        in >> year;
        in.ignore();

        student = Student(id, name, averageGrade, year);

        return in;
    }

    bool operator ==(const Student &other) {
        return strcmp(this->id, other.id) == 0;
    }

    friend class Group;
};

class Group {
private:
    char name[10];
    Student *students;
    int count;

public:
    Group(char *name = "PIT-2") {
        strcpy(this->name, name);
        this->count = 0;
        this->students = new Student[this->count];
    }

    ~Group() {
        delete [] students;
    }

    Group(const Group &other) {
        strcpy(this->name, other.name);
        this->count = other.count;
        this->students = new Student[this->count];
        for (int i = 0; i < this->count; i++) {
            this->students[i] = other.students[i];
        }
    }

    Group &operator =(const Group &other) {
        if (this != &other) {
            delete [] students;
            strcpy(this->name, other.name);
            this->count = other.count;
            this->students = new Student[this->count];
            for (int i = 0; i < this->count; i++) {
                this->students[i] = other.students[i];
            }
        }
        return *this;
    }

    Group &operator +=(const Student &student) {
        for (int i = 0; i < this->count; i++) {
            if (this->students[i] == student) {
                return *this;
            }
        }
        Student *temp = new Student [this->count + 1];
        for (int i = 0; i < this->count; i++) {
            temp[i] = this->students[i];
        }
        temp[this->count] = student;
        this->count++;
        delete [] students;
        students = temp;

        return *this;
    }

    double operator [](char *id) {
        for (int i = 0; i < this->count; i++) {
            if (strcmp(this->students[i].id, id) == 0) {
                return this->students[i].averageGrade;
            }
        }
    }
};

int main() {
    // Student s("201056", "Ema", 9.1, 2);
    Student s;
    Student s1;
    cin >> s;
    cin >> s1;
    cout << s << endl;
    cout << s1 << endl;
    // cout<<s++; //2
    // cout<<s; // 3
    // cout<<++s; //4
    cout << (s == s1) << endl;
    Group g;
    g += s1;
    g += s;
    cout << g["201056"];
}
