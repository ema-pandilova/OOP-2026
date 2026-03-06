//
// Created by ema on 27.2.26.
//
#include <iostream>
using namespace std;
#include <cstring>
#include <cctype>

// Од стандарден влез се читаат податоци за непознат број студенти (не повеќе од 100).
// Податоците се внесуваат така што во секој ред се состои од:
//
// името
// презимето
// бројот на индекс (формат xxyzzzz)
// четири броја (поени од секоја задача)
// со произволен број празни места или табулатори меѓу нив.
//
// Да се напише програма која ќе испечати список на студенти, каде во секој ред ќе има: презиме, име, број на индекс,
// вкупен број на бодови сортиран според бројот на бодови.
// При тоа имињата и презимињата да се напишат со голема почетна буква.

struct Student {
    char name[100];
    char surname[100];
    char index[10];
    int totalPoints;

    void print() {
        cout << name << " " << surname << " " << index << " " << totalPoints << endl;
    }
};

void normalize(char *niza) {
    niza[0] = toupper(niza[0]);
    for (int i = 1; i < strlen(niza); i++) {
        niza[i] = tolower(niza[i]);
    }
}

void read(Student &s) {
    cin >> s.name >> s.surname >> s.index;
    normalize(s.name);
    normalize(s.surname);
    int z1, z2, z3, z4;
    cin >> z1 >> z2 >> z3 >> z4;
    s.totalPoints = z1 + z2 + z3 + z4;
}

void sort(Student *students, int n) {
    Student temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].totalPoints < students[j + 1].totalPoints) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    Student students[n];
    for (int i = 0; i < n; i++) {
        read(students[i]);
    }
    sort(students, n);
    for (int i = 0; i < n; i++) {
        students[i].print();
    }
}
