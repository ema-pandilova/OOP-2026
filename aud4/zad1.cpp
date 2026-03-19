//
// Created by ema on 16.3.26.
//
#include<iostream>
#include<cstring>
using namespace std;

class Student {
private:
    char name[50];
    int index;
    int age;
public:
    Student(char *name="", int index = 0, int age = 0) {
        strcpy(this->name,name);
        this->index = index;
        this->age = age;
    }
    Student(const Student &s) {
        strcpy(this->name,s.name);
        this->index = s.index;
        this->age = s.age;
    }
    Student & increaseAge() {
        this->age++;
        return *this;
    }
    void print() {
        cout<<name<<" "<<index<<" "<<age<<endl;
    }

};
void compare(Student &s1, Student &s2) {
    //logika
}
int main() {
    Student s1("Ema",20156,24);
    s1.print();
    Student s2 = Student(s1); //ekspliciten nacin za povikuvanje copy konstruktor
    s2.print();
    compare(s1,s2); // impliciten nacin

}
