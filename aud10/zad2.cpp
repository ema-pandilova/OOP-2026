//
// Created by ema on 7.5.26.
//
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;


class Product {
protected:
    char name[50];
    float price;

public:
    Product(char *name = "", float price = 0) {
        strcpy(this->name, name);
        this->price = price;
    }
};

class Discountable {
    //interface
public:
    virtual float getPrice() = 0;

    virtual float getDiscountPrice() = 0;

    virtual void print() = 0;
};

class FoodProduct : public Product, public Discountable {
private:
    int calories;

public:
    FoodProduct(char *name = "", float price = 0, int calories = 0): Product(name, price) {
        this->calories = calories;
    }

    float getPrice() {
        return this->price;
    }

    float getDiscountPrice() {
        if (calories > 500) {
            return 0.8 * price;
        } else if (calories > 100) {
            return 0.9 * price;
        } else
            return 0.1 * price;
    }

    void print() {
        cout << "Food Product: " << this->name << " " << this->price << " " << this->calories << " " <<
                getDiscountPrice() << endl;
    }
};

class DigitalProduct : public Product, public Discountable {
private:
    int size;

public:
    DigitalProduct(char *name = "", float price = 0, int size = 0): Product(name, price) {
        this->size = size;
    }

    float getPrice() {
        return this->price;
    }

    float getDiscountPrice() {
        if (size > 1024) {
            return 0.8 * price;
        } else if (size > 100) {
            return 0.9 * price;
        } else
            return 0.1 * price;
    }

    void print() {
        cout << "Digital Product: " << this->name << " " << this->price << " " << this->size << " " <<
                getDiscountPrice() << endl;
    }
};

float total_discount(Discountable **discountable, int n) {
    float total = 0.0;
    for (int i = 0; i < n; i++) {
        total += discountable[i]->getPrice() - discountable[i]->getDiscountPrice();
    }
    return total;
}

int count_food_products(Discountable **discountable, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        FoodProduct *casted = dynamic_cast<FoodProduct *>(discountable[i]);
        if (!casted) {
            //if(!nullptr)
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;

    Discountable **discountable = new Discountable *[n];
    for (int i = 0; i < n; i++) {
        int type;
        char name[50];
        float price;
        int calories;
        int size;
        cin >> type;
        if (type == 1) {
            cin >> name >> price >> calories;
            discountable[i] = new FoodProduct(name, price, calories);
        } else if (type == 2) {
            cin >> name >> price >> size;
            discountable[i] = new DigitalProduct(name, price, size);
        }
    }
    for (int i = 0; i < n; i++) {
        discountable[i]->print();
    }
    cout << "Total discount for the products is: " << total_discount(discountable, n) << endl;

    cout << "Total number of food products" << count_food_products(discountable, n);
    cout << "Total number of digital products" << n - count_food_products(discountable, n);
}
