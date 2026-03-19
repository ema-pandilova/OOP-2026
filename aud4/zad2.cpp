//
// Created by ema on 16.3.26.
//
#include<iostream>
#include<cstring>
using namespace std;

// Example for static variable
// class Test {
// public:
//     static int x;
//     Test(){}
// };
// int Test::x = 0;
// int main() {
//     cout<<Test::x<<endl;
// }

class Student {
private:
    char name[20];
    char index[20];
    float gpa;
    static int totalStudents;
    static float totalGPA;

public:
    Student() {
    }

    Student(char *name, char *index, float gpa) {
        strcpy(this->name, name);
        strcpy(this->index, index);
        this->gpa = gpa;
        totalStudents++;
        totalGPA += gpa;
    }

    static int getTotalStudents() {
        return totalStudents;
    }

    static int getAverageGPA() {
        return totalGPA / totalStudents;
    }

    void printStudent() {
        cout << "Name: " << name << endl;
        cout << "Index: " << index << endl;
        cout << "GPA: " << gpa << endl;
    }
};

int Student::totalStudents = 0;
float Student::totalGPA = 0;

int main() {
    int n;
    cout << "Enter number of students" << endl;
    cin >> n;
    Student students[n];
    char name[30], id[10];
    float gpa;
    for (int i = 0; i < n; i++) {
        cin >> name >> id >> gpa;
        students[i] = Student(name, id, gpa);
    }

    for (int i = 0; i < n; i++) {
        students[i].printStudent();
    }
    cout << "Total students: " << Student::getTotalStudents() << endl;
    cout << "Total average: " << Student::getAverageGPA() << endl;
    return 0;
}
