//
// Created by ema on 27.3.26.
//
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;


class Array {
    int size;
    int capacity;
    int *array;

public:
    Array(int capacity = 5) {
        this->capacity = capacity;
        this->size = 0;
        this->array = new int[capacity];
    }

    Array(const Array &other) {
        this->capacity = other.capacity;
        this->size = other.size;
        this->array = new int[capacity];
        for (int i = 0; i < size; i++) {
            this->array[i] = other.array[i];
        }
    }

    ~Array() {
        delete[] this->array;
    }


    Array &operator=(const Array &other) {
        if (this != &other) {
            delete[] this->array;
            this->capacity = other.capacity;
            this->size = other.size;
            this->array = new int[capacity];
            for (int i = 0; i < size; i++) {
                this->array[i] = other.array[i];
            }
        }
        return *this;
    }


    Array &operator+=(int number) {
        if (this->size == this->capacity) {
            int *tmp = new int[this->capacity * 2];
            for (int i = 0; i < this->size; i++) {
                tmp[i] = this->array[i];
            }
            tmp[this->size] = number;
            this->size++;
            this->capacity *= 2;
            delete[] this->array;
            this->array = tmp;
        } else {
            this->array[size] = number;
            this->size++;
        }
        return *this;
    }

    Array &operator-=(int number) {
        int j = 0;
        for (int i = 0; i < size; i++) {
            if (this->array[i] != number) {
                this->array[j++] = this->array[i];
            }
        }
        this->size = j;
        return *this;
    }

    friend ostream &operator<<(ostream &out, const Array &other) {
        cout << "Capacity: " << other.capacity << endl;
        cout << "Size: " << other.size << endl;
        for (int i = 0; i < other.size; i++) {
            if (i == other.size - 1) {
                cout << other.array[i] << endl;
            } else {
                cout << other.array[i] << " ";
            }
        }
        return out;
    }

    int &operator[](int index) {
        return this->array[index];
    }

    bool operator==(const Array &other) {
        if (this->size != other.size) {
            return false;
        } else {
            for (int i = 0; i < this->size; i++) {
                if (this->array[i] != other.array[i]) {
                    return false;
                }
            }
            return true;
        }
    }

    Array operator + (const Array &other){
        Array result (this->capacity+other.capacity);
        for(int i = 0; i < this->size; i++) {
            result+=array[i];
        }
        for(int i = 0; i < other.size; i++) {
            result+=other.array[i];
        }
        return result;
    }
};

int main() {
    Array a;
    a += (6);
    a += (4);
    a += (3);
    a += (2);
    a += (1);


    Array b(a);
    b -= (2);
    b -= (3);


    a[0] = 9; //primena na operatorot []


    cout << " a: " << a;
    cout << " b: " << b;


    if (a == b) cout << "Isti se";
    else cout << "Ne se isti";


    return 0;
}
