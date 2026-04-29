//
// Created by ema on 27.4.26.
//
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

class Payment {
protected:
    int amount;

public:
    Payment(int amount) {
        this->amount = amount;
    }

    virtual void processPayment() {
        cout << "Please enter the amount to be payed: ";
    }

    virtual void printTypePayment() = 0;
};

class CashPayment : public Payment {
public:
    CashPayment(int amount) : Payment(amount) {
    }

    void printTypePayment() {
        cout << "Pay with cash" << endl;
    }

    // void processPayment() {
    //     cout<<"The amount that is paid is: "<<amount<<endl;
    // }
};

class CreditCardPayment : public Payment {
public:
    CreditCardPayment(int amount) : Payment(amount) {
    }

    void printTypePayment() {
        cout << "Pay with credit card" << endl;
    }

    // void processPayment() {
    //     cout<<"The amount that is paid is: "<<amount<<endl;
    // }
};

int main() {
    int n;
    cin >> n;
    Payment **payments = new Payment *[n];
    int type, amount;
    for (int i = 0; i < n; i++) {
        cin >> type >> amount;
        if (type == 1) {
            payments[i] = new CashPayment(amount);
        } else if (type == 2) {
            payments[i] = new CreditCardPayment(amount);
        }
    }
    for (int i = 0; i < n; i++) {
        payments[i]->printTypePayment();
        payments[i]->processPayment();
    }
}
