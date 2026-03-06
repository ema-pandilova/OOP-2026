//
// Created by ema on 27.2.26.
//
#include <iostream>
using namespace std;

struct Complex {
    float real;
    float imag;

    Complex add(Complex other) {
        Complex result;
        result.real = real + other.real;
        result.imag = imag + other.imag;
        return result;
    }

    Complex subtract(Complex other) {
        Complex result;
        result.real = real - other.real;
        result.imag = imag - other.imag;
        return result;
    }

    void print() {
        cout << real;
        if (imag < 0) {
            cout << imag << "i" << endl;
        } else {
            cout << "+" << imag << "i" << endl;
        }
    }
};

void read(Complex &c) {
    cin >> c.real >> c.imag;
}

int main() {
    Complex a, b, c;
    read(a);
    read(b);
    a.print();
    b.print();
    cout << "a + b" << endl;
    c = a.add(b);
    c.print();
    cout << "a - b" << endl;
    a.subtract(b).print();
    return 0;
}
