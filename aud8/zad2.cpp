//
// Created by ema on 21.4.26.
//
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

//virtual i pokazhuvaci
class Animal {
protected:
    char name[20];

public:
    Animal(char *name = "") {
        strcpy(this->name, name);
    }

    virtual void makeSound() {
        cout << this->name << "makes this sound bla bla" << endl;
    }
};

class Dog : public Animal {
public:
    Dog(char *name = "") : Animal(name) {
    }

    void makeSound() {
        cout << this->name << "makes this sound af af" << endl;
    }
};

class Cow : public Animal {
public:
    Cow(char *name = "") : Animal(name) {
    }

    void makeSound() {
        cout << this->name << "makes this sound mu mu" << endl;
    }
};

int main() {
    // Animal *a = new Animal("basic");
    // a->makeSound();
    // Animal *d = new Dog("lesi");
    // d->makeSound();
    // Animal *c = new Cow("milka");
    // c->makeSound();
    Animal **animals = new Animal *[3]; //deklaracija na niza od pokazuvaci
    animals[0] = new Dog("lesi");
    animals[1] = new Cow("Milka");
    animals[2] = new Animal("test");
    for (int i = 0; i < 3; i++) {
        animals[i]->makeSound();
    }
}
