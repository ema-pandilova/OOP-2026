//
// Created by ema on 27.2.26.
//
#include <iostream>
using namespace std;

// Да се напише програма која ќе споредува два датуми (ден, месец, година) и ќе ја пресмета разликата во денови од едниот до
// другиот датум. Пресметките да се реализираат во посебни функции.
// За датумот да се дефинира посебна структура date.

struct Date {
    int day;
    int month;
    int year;

    int compare(Date other) {
        // 1 ako prv datum > vtor datum, -1 prv datum < vtor datum, 0 ako se isti
        if (year > other.year) {
            return 1;
        } else if (other.year > year) {
            return -1;
        } else {
            if (month > other.month) {
                return 1;
            } else if (other.month > month) {
                return -1;
            } else {
                if (day > other.day) {
                    return 1;
                } else if (other.day > day) {
                    return -1;
                } else {
                    return 0;
                }
            }
        }
    }

    int countDiff(Date other) {
        int diff = other.day - day;
        diff += (other.month - month) * 30;
        diff += (other.year - year) * 365;
        return diff;
    }
};

void read(Date &d) {
    cin >> d.day >> d.month >> d.year;
}

int main() {
    Date d1;
    Date d2;
    read(d1);
    read(d2);
    if (d1.compare(d2) == 1) {
        cout << "Rezlikata e " << d2.countDiff(d1) << endl;
    } else if (d1.compare(d2) == -1) {
        cout << "razlikata e " << d1.countDiff(d2) << endl;
    } else {
        cout << "Datumite se isti" << endl;
    }
}
