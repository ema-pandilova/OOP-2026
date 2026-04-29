//
// Created by ema on 27.4.26.
//
#include <iostream>
#include <cstring>
#include <cctype>
#include <math.h>
using namespace std;

class Shape {
protected:
    double height;

public:
    Shape(double height) {
        this->height = height;
    }

    virtual void print() {
        cout << "height: " << height;
    }

    virtual double getVolume() = 0;

    double getHeight() {
        return height;
    }
};

class Cylinder : public Shape {
private:
    double radius;

public:
    Cylinder(double height, double radius) : Shape(height) {
        this->radius = radius;
    }

    double getVolume() override {
        return M_PI * radius * radius * height;
    }

    void print() {
        cout << "Cylinder with radius: " << radius << "and ";
        Shape::print();
    }

    double getRadius() {
        return radius;
    }
};

class Cone : public Shape {
private:
    double radius;

public:
    Cone(double height, double radius) : Shape(height) {
        this->radius = radius;
    }

    double getVolume() {
        return M_PI * radius * radius * height / 3.0;
    }

    void print() {
        cout << "Cone with radius: " << radius << "and ";
        Shape::print();
    }

    double getRadius() {
        return radius;
    }
};

class Cuboid : public Shape {
private:
    double a;
    double b;

public:
    Cuboid(double height, double a, double b) : Shape(height) {
        this->a = a;
        this->b = b;
    }

    void print() {
        cout << "Cuboid with length: " << a << "and " << " width: " << b;
        Shape::print();
    }

    double getVolume() {
        return a * b * height;
    }
};

void shapeWithMostVolume(Shape **shapes, int n) {
    Shape *shapeMaxVolume = shapes[0];

    for (int i = 0; i < n; i++) {
        if (shapes[i]->getVolume() > shapeMaxVolume->getVolume()) {
            shapeMaxVolume = shapes[i];
        }
    }

    shapeMaxVolume->print();
}

double getRadius(Shape *shape) {
    Cylinder *cylinder = dynamic_cast<Cylinder *>(shape);

    if (cylinder) {
        return cylinder->getRadius();
    }

    Cone *cone = dynamic_cast<Cone *>(shape);

    if (cone) {
        return cone->getRadius();
    }

    return -1;
}


int main() {
    int n, type;
    double height, a, b, radius;
    cin >> n;

    Shape **shapes = new Shape *[n];

    for (int i = 0; i < n; i++) {
        cin >> type;
        cin >> height;

        if (type == 1) {
            cin >> radius;
            shapes[i] = new Cylinder(height, radius);
        } else if (type == 2) {
            cin >> radius;
            shapes[i] = new Cone(height, radius);
        } else {
            cin >> a >> b;
            shapes[i] = new Cuboid(height, a, b);
        }
    }

    for (int i = 0; i < n; i++) {
        shapes[i]->print();

        double shapeRadius = getRadius(shapes[i]);
        if (shapeRadius == -1) {
            cout << "The shape's base is not circle" << endl;
        } else {
            cout << "The shape's radius is: " << shapeRadius << endl;
        }
    }

    cout << "-------------------------" << endl;
    cout << "Shape with most volume: " << endl;
    shapeWithMostVolume(shapes, n);


    return 0;
}
