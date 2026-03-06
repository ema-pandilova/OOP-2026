//
// Created by ema on 27.2.26.
//
#include <iostream>
using namespace std;

// struct Employee {
//     int id;
//     char name[100];
//     int salary;
//
//     //     void read() {
//     //         cin >> id >> name >> salary;
//     //     }
//     //
//     //     void print() {
//     //         cout << id << " " << name << " " << salary << endl;
//     //     }
//     // };
// };
//
// void read(Employee &e) {
//     cin >> e.id >> e.name >> e.salary;
// }
//
// void print(Employee e) {
//     cout << e.id << " " << e.name << " " << e.salary << endl;
// }
//
// int main() {
//     Employee e;
//     // e.read();
//     // e.print();
//     read(e);
//     print(e);
//
//     return 0;
//
// }

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int a = 10, b = 7;
    swap(a, b);
    cout << a << " " << b << endl;
}
