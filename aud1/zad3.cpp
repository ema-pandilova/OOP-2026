//
// Created by ema on 27.2.26.
//
#include <iostream>
using namespace std;

// Да се напише програма која ќе го пресметува векторскиот и скаларниот производ на два вектори.
// Векторите се претставени со координати во тродимензионален координатен систем.
// Скаларниот и векторскиот производ да се пресметуваат со посебни функции.
// За вектор да се дефинира посебна структура vector.

struct Vector {
    float x;
    float y;
    float z;

    float skalaren(Vector other) {
        return x * other.x + y * other.y + z * other.z;
    }

    Vector vektorski(Vector other) {
        Vector result;
        result.x = y * other.z - z * other.y;
        result.y = z * other.x - x * other.z;
        result.z = x * other.y - y * other.x;
        return result;
    }

    void print() {
        cout << "(" << x << ", " << y << ", " << z << ")" << endl;
    }
};
void read(Vector &v) {
    cin >> v.x >> v.y >> v.z;
}
int main() {
    Vector v1;
    Vector v2;
    read(v1);
    read(v2);
    cout<<v1.skalaren(v2)<<endl;
    v1.vektorski(v2).print();
}
