//
// Created by ema on 30.3.26.
//
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

// Да се дефинира класа Book во која ќе се чуваат информации за:
//
// Насловот на книгата (тип: char [], со default вредност "TEST BOOK")
// Бројот на страници кои се прочитани (тип: integer, со default вредност 0)
// За класата да се дефинираат:
//
// Конструктори (согласно кодот во main методот)
// readPages(int pages) - метод кој додава број на прочитани страници. Да се внимава прочитаните страници да не го надминат вкупниот број на страници за 200.
// print() - метод кој ги печати информациите за книгата во следниот формат:
// TITLE - READ_PAGES/200 - STATUS, каде што статус може да биде:
// IN PROGRESS (ако се прочитани помалку од 100 страници)
// ALMOST DONE (ако се прочитани 100 или повеќе страници, но помалку од 200)
// FINISHED (ако се прочитани сите 200 страници)


using namespace std;

class Book {
private:
    char name[50];
    int pagesRead;

public:
    Book(const char *name = "TEST_BOOK", int pagesRead = 0) {
        strcpy(this->name, name);
        this->pagesRead = pagesRead;
    }

    void readPages(int pages) {
        pagesRead += pages;
        if (pagesRead > 200) {
            pagesRead = 200;
        }
    }

    const char *status() {
        if (pagesRead < 100) {
            return "IN PROGRESS";
        } else if (pagesRead < 200) {
            return "ALMOST DONE";
        } else {
            return "FINISHED";
        }
    }

    void print() {
        cout << name << " - " << pagesRead << "/200 - " << status() << endl;
    }
};

int main() {
    int N;
    cin >> N;

    Book books[100];

    char name[50];
    int pagesRead;

    for (int i = 0; i < N; i++) {
        cin >> name >> pagesRead;
        books[i] = Book(name, pagesRead);
    }

    int idx, pages;
    cin >> idx >> pages;

    books[idx].readPages(pages);

    for (int i = 0; i < N; i++) {
        books[i].print();
    }

    return 0;
}