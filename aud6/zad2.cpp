//
// Created by ema on 30.3.26.
//
#include<iostream>
#include <cstring>
using namespace std;

// Да се дефинира класа Car во која ќе се чуваат информации за:
//
// Регистрацискиот број на автомобилот (тип: string, со default вредност "SK-0001-AA")
// Количината на гориво во резервоарот (тип: double, со default вредност 0.0)
// За класата да се дефинираат:
//
// Конструктори (согласно кодот во main методот)
// refuel(double liters) - метод кој додава гориво во резервоарот. Да се внимава горивото да не ја надмине максималната количина од 50 литри.
// print() - метод кој ги печати информациите за автомобилот во следниот формат:
// LICENSE PLATE - FUEL LEVEL - STATUS, каде што статус може да биде:
// EMPTY (ако количината на гориво е 0)
// LOW (ако количината е помала од 10 литри)
// ENOUGH (ако количината е 10 или повеќе литри)

class Car {
private:
    char reg[20];
    double gorivo;

public:
    Car() {
        strcpy(reg, "SK-0001-AA");
        gorivo = 0.0;
    }

    Car(char *reg, double gorivo) {
        strcpy(this->reg, reg);
        this->gorivo = gorivo;
    }

    Car(char *reg) {
        strcpy(this->reg, reg);
        gorivo = 0;
    }

    void refuel(double liters) {
        this->gorivo += liters;
        if (this->gorivo > 50) {
            this->gorivo = 50;
        }
    }

    void print() {
        //LICENSE PLATE - FUEL LEVEL - STATUS
        cout << reg << " - " << gorivo << " - ";
        if (gorivo == 0) {
            cout << "EMPTY" << endl;
        } else if (gorivo < 10) {
            cout << "LOW" << endl;
        } else if (gorivo >= 10) {
            cout << "ENOUGH" << endl;
        }
    }
};

int main() {
    string command;
    Car s;
    char id[20];
    double liters;

    while (cin >> command) {
        if (command == "constructor1") {
            cin >> id >> liters;
            s = Car(id, liters);
        } else if (command == "constructor2") {
            cin >> id;
            s = Car(id);
        } else if (command == "refuel") {
            cin >> liters;
            s.refuel(liters);
        } else if (command == "print") {
            s.print();
        }
    }


    return 0;
}
