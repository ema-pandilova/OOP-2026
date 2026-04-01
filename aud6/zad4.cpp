//
// Created by ema on 1.4.26.
//
//Да се дефинира класа Student во која ќе се чуваат информации за:
//
//Индексот на студентот (тип: char[], со default вредност "NO_ID")
//Поените освоени на некој испит (тип: integer, со default вредност 0)
//За класата да се дефинираат:
//
//Конструктори (согласно кодот во main методот)
//addPoints(int points) - метод кој додава поени на студентот. Да се внимава поените да не надминат 100!
//print() - метод кој ги печати информациите за студентот во следниот формат:
//ID - POINTS - STATUS, каде што статус може да биде:
//FAILED (ако студентот има под 50 поени)
//PASSED (ако студентот има 50 или повеќе од 50 поени)
//BEST (ако студентот има 90 или повеќе од 90 поени)
//Define a class Student to store information about:
//
//The student's index (type: char[], with default value "NO_ID")
//Points earned on an exam (type: integer, with a default value 0)
//The class should define:
//
//Constructors (as required by the code in the main method)
//addPoints(int points) - a method that adds points to the student. Ensure that the points do not exceed 100!
//print() - a method that prints the student's information in the following format:
//ID - POINTS - STATUS, where the status can be:
//FAILED (if the student has less than 50 points)
//PASSED (if the student has 50 or more points)
//BEST (if the student has 90 or more points)
#include<iostream>
#include <cstring>
using namespace std;

// Да се дефинира класа Student во која ќе се чуваат информации за:
//
// Индексот на студентот (тип: char[], со default вредност "NO_ID")
// Поените освоени на некој испит (тип: integer, со default вредност 0)
// За класата да се дефинираат:
//
// Конструктори (согласно кодот во main методот)
// addPoints(int points) - метод кој додава поени на студентот. Да се внимава поените да не надминат 100!
// print() - метод кој ги печати информациите за студентот во следниот формат:
// ID - POINTS - STATUS, каде што статус може да биде:
// FAILED (ако студентот има под 50 поени)
// PASSED (ако студентот има 50 или повеќе од 50 поени)
// BEST (ако студентот има 90 или повеќе од 90 поени)
class Student {
private:
    char id[50];
    int points;

public:


    Student(const char *id = "NO_ID", int points = 0) {
        strcpy(this->id, id);
        this->points = points;
    }

    void addPoints(int points) {
        this->points += points;
        if (this->points > 100) {
            this->points = 100;
        }
    }

    string status() {
        if (points >= 90) {
            return "BEST";
        } else if (points >= 50) {
            return "PASSED";
        } else {
            return "FAILED";
        }
    }

    void print() {
        cout << id << " - " << points << " " << status() << endl;
    }
};

int main() {
    int N;
    cin >> N;

    Student students[100];

    //TODO read N students;
    for (int i = 0; i < N; ++i) {
        char id[50];
        int points;
        cin>>id;
        cin>>points;
        students[i] = Student(id, points);
    }

    int idx, points;
    cin >> idx >> points;

    students[idx].addPoints(points);

    for (int i = 0; i < N; i++) {
        students[i].print();
    }


    return 0;
}