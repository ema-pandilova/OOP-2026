//
// Created by ema on 17.4.26.
//
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

class Square {
protected:
    int a;

public:
    Square(int a = 1) {
        cout << "S" << endl;
        this->a = a;
    }

    Square(const Square &s) {
        cout << "S copy constructor" << endl;
        this->a = s.a;
    }

    ~Square() {
        cout << "~S" << endl;
    }

    int area() const {
        return a * a;
    }

    int perimeter() const {
        return 4 * a;
    }

    friend ostream &operator<<(ostream &os, const Square &s) {
        os << s.a << " " << s.area() << " " << s.perimeter() << endl;
        return os;
    }
};

class Rectangle : public Square {
private:
    int b;

public:
    Rectangle(int a = 1, int b = 1): Square(a) {
        cout << "R" << endl;
        this->b = b;
    }

    Rectangle(const Rectangle &r): Square(r) {
        this->b = r.b;
    }

    ~Rectangle() {
        cout << "~R" << endl;
    }

    int area() const {
        return a * b;
    }

    int perimeter() const {
        return 2 * a + 2 * b;
    }

    friend ostream &operator<<(ostream &os, const Rectangle &r) {
        os << r.a << " " << r.b << " " << r.area() << " " << r.perimeter() << endl;;
        return os;
    }
};

int main() {
    Square s;
    cout << s;
    Rectangle r(2, 3);
    cout << r;
}
