//
// Created by ema on 11.5.26.
//
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

class NegativeValueException {
private:
    float value;

public:
    NegativeValueException(float v = 0) {
        this->value = v;
    }

    void showMessage() {
        cout << " The price value is negative: " << value << endl;
    }
};

class Product {
protected:
    char name[50];
    float basePrice;

public:
    static float EUR_TO_MKD;
    static float USD_TO_MKD;

    Product(char *name = "", float basePrice = 0) {
        strcpy(this->name, name);
        this->basePrice = basePrice;
    }

    virtual float discount_price() = 0;

    float price() {
        return this->basePrice;
    }

    void changePrice(float newPrice) {
        if (newPrice < 0) {
            throw NegativeValueException(newPrice);
        }
        this->basePrice = newPrice;
    }

    virtual void print_rule() = 0;
};

float Product::EUR_TO_MKD = 61.3;
float Product::USD_TO_MKD = 50.2;

class FoodProduct : public Product {
public:
    FoodProduct(char *name = "", float basePrice = 0) : Product(name, basePrice) {
    }

    float discount_price() {
        return basePrice;
    }

    void print_rule() {
        cout << "No discount on food products" << endl;
    }
};

class Drinks : public Product {
private:
    bool alcohol;
    char brand[50];

public:
    Drinks(char *name = "", float basePrice = 0, bool alcohol = false,
           char *brand = "Gazoza"): Product(name, basePrice) {
        this->alcohol = alcohol;
        strcpy(this->brand, brand);
    }

    float discount_price() {
        if (alcohol && price() / EUR_TO_MKD > 20) {
            return price() * 0.95; // price() - (price()*0.05)
        }
        if (!alcohol && strcmp(this->brand, "Coca-Cola") == 0) {
            return price() * 0.90;
        }
    }

    void print_rule() {
        cout << "Rule 1: If alcohol and price > 20 eur ---> discount 5%" << endl;
        cout << "Rule 2: If non-alcoholic and Coca-Cola ---> discount 10%" << endl;
    }
};

class Cosmetics : public Product {
public:
    Cosmetics(char *name = "", float basePrice = 0) : Product(name, basePrice) {
    }

    float discount_price() {
        if (price() / USD_TO_MKD > 20) {
            return price() * 0.86;
        } else if (price() / EUR_TO_MKD > 5) {
            return price() * 0.88;
        } else {
            return price();
        }
    }

    void print_rule() {
        cout << "Rule 1: If  price > 20 usd ---> discount 14%" << endl;
        cout << "Rule 2: If price > 5 eur ---> discount 12%" << endl;
    }
};

float total_price(Product **products, int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += products[i]->discount_price();
    }
    return sum;
}

int main() {
    Product **products = new Product *[5];
    products[0] = new FoodProduct("pizza", 400);
    products[1] = new Drinks("whiskey", 2000, true, "red_label");
    products[2] = new Drinks("juice", 100, false, "Coca-Cola");
    products[3] = new Cosmetics("lipstick", 2000);
    products[4] = new Cosmetics("lipliner", 380);
    cout << "Total price: " << total_price(products, 5) << endl;

    for (int i = 0; i < 5; i++) {
        Cosmetics *cptr = dynamic_cast<Cosmetics *>(products[i]);
        if (cptr != nullptr) {
            try {
                products[i]->changePrice(-100);
            } catch (NegativeValueException e) {
                e.showMessage();
            }
        }
    }
}
