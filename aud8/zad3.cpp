//
// Created by ema on 21.4.26.
//
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

class HotelReservation {
protected:
    int days;
    int people;
    char contact[50];

public:
    HotelReservation(char *contact = "", int days = 0, int people = 0) {
        this->days = days;
        this->people = people;
        strcpy(this->contact, contact);
    }

    virtual int price() {
        return people * days * 25;
    }

    virtual int price(int amount) {
        return amount - price();
    }
};

class HalfBoardHotelReservation : public HotelReservation {
public:
    HalfBoardHotelReservation(char *contact = "", int days = 0,
                              int people = 0): HotelReservation(contact, days, people) {
    }

    int price() {
        return people * days * 30;
    }

    int price(int amount) {
        return amount - (HotelReservation::price() + people * days * 5);
    }
};

class Hotel {
    char name[20];
    int balance;

public:
    Hotel(char *name = "", int balance = 0) {
        strcpy(this->name, name);
        this->balance = balance;
    }

    int pay(HotelReservation &hr, int amount) {
        int totalPrice = hr.price();
        balance += totalPrice;
        return hr.price(amount);
    }

    friend ostream &operator<<(ostream &os, const Hotel &h) {
        os << h.name << " " << h.balance;
        return os;
    }
};

int main() {
    Hotel hotel("FINKI", 1000);
    int n;
    cin >> n;
    HotelReservation **reservations = new HotelReservation *[n];

    for (int i = 0; i < n; i++) {
        //type = 1,
        int type;
        int days;
        int people;
        char contact[50];
        cin >> type >> days >> people >> contact;
        if (type == 1) {
            reservations[i] = new HotelReservation(contact, days, people);
        } else if (type == 2) {
            reservations[i] = new HalfBoardHotelReservation(contact, days, people);
        }
        cout << reservations[i]->price() << endl;
    }
}
