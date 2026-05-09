//
// Created by ema on 7.5.26.
//
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

class Vehicle {
protected:
    int acceleration;

public:
    Vehicle() {
        this->acceleration = 0;
        cout << "Vehicle Constructor called" << endl;
    }

    ~Vehicle() {
        cout << "Vehicle Destructor called" << endl;
    }

    virtual void accelerate() {
        cout << "Vehicle Accelerate called" << endl;
        acceleration++;
    }

    int getAcceleration() {
        return acceleration;
    }
};

class Car : virtual public Vehicle {
public:
    Car() {
        cout << "Car Constructor called" << endl;
    }

    ~Car() {
        cout << "Car Destructor called" << endl;
    }

    virtual void accelerate(){
        cout<<"Car Accelerate called"<<endl;
        Vehicle::accelerate();
        Vehicle::accelerate();
    }
    virtual void drive() {
        cout << "Car Drive called" << endl;
    }
};

class Jet : virtual public Vehicle {
public:
    Jet() {
        cout << "Jet Constructor called" << endl;
    }

    ~Jet() {
        cout << "Jet Destructor called" << endl;
    }

    // virtual void accelerate() {
    //     cout << "Jet Accelerate called" << endl;
    //     acceleration += 10;
    // }

    virtual void fly() {
        cout << "Jet Fly called" << endl;
    }
};

class JetCar : public Jet, public Car {
public:
    JetCar() {
        cout << "JetCar Constructor called" << endl;
    }

    ~JetCar() {
        cout << "JetCar Destructor called" << endl;
    }

    void drive() override {
        cout << "JetCar Drive called" << endl;
    }

    void fly() override {
        cout << "JetCar Fly called" << endl;
    }
};

int main() {
    JetCar jetcar;
    jetcar.drive();
    jetcar.fly();
    jetcar.accelerate();
    return 0;
}
