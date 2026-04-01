//
// Created by ema on 1.4.26.
//
#include <iostream>
#include <cstring>
using namespace std;

// Да се дефинира класа Book, која репрезентира една книга. За класата Book се чуваат:
// Наслов (текстуална низа од 30 знаци)
// Сериски број (цел број)
// Тип на книга (енумерациски тип, стручна литература или роман)
// Цена (децимален број)
// Серискиот број е единствен за секоја книга, неговата почетна вредност е 777550. Да се обезбеди секвенцијално генерирање на овој број, така што првата книга ќе има сериски број 777551, втората 777552, третата 777553 итн. (5 поени)
// За оваа класа да се обезбедат потребните конструктори и set/get методи. (5 поени)
//
// Да се имплементира метод print() со кој ќе се печатат информациите за секој објект во формат:
// [сериски број] - [наслов] [тип] [цена]
// (5 поени)
//
// Да се имплементира метод increasePrice(float) кој како аргумент ќе прима реален број, што ќе претставува износ кој се додава на цената на книгата. (5 поени)
//
// Потоа да се дефинира класа BookStore, во која се чуваат информации за:
// Име (текстуална низа од 20 знаци)
// Листа од книги (обична низа со максимум 100 објекти од класата Book)
// Број на книги (број на елементи во низата од книги, иницијално е 0)

// За оваа класа да се дефинираат потребните конструктори, деструктор (ако е потребен), set и get методи. (5 поени)
//
// Да се имплементира метод print() во формат:
// [име]
// и потоа сите книги поединечно (види форматот од методот Book::print). (5 поени)
//
// Да се имплементира метод addBook(const Book&) за додавање нова книга во продавницата.
// Книгите се менаџираат според нивниот наслов, односно не смее да се дозволи додавање книга со ист наслов повеќе од еднаш. (10 поени)
// Да се дефинира метод greaterThan(const BookStore&) кој ќе споредува дали едната продавница има повеќе книги од другата. (5 поени)
// Да се дефинира метод void createMarketPrice() - со кој продавницата генерира продажни цени на сите книги. Продажните цени се пресметуваат во зависност од тоа за каков тип на литература станува збор:
// За стручна литература се додава 5% на цената
// За романи се додава 3% (10 поени)
//
// Да се дефинира глобална функција best() - која прима низа од објекти од класатa BookStore и бројот на продавници, а ја враќа онаа продавница која има најмногу книги. Доколку повеќе продавници имаат ист број на книги, се враќа првата најдена. (5 поени)

//YOUR CODE HERE:
enum Type {
    ACADEMIC,// 0
    ROMAN // 1
};
class Book {
    char title[31];
    int id;
    Type type;
    float price;
    static int serial;
public:
    Book(){}
    Book(const char *title, int type, float price) {
        strcpy(this->title, title);
        this->price = price;
        this->type = (Type) type;
        this->id=++serial;
    }
    //[сериски број] - [наслов] [тип] [цена]
    void print() {
        cout<<id<<" - "<<title<<" ";
        if(type==ACADEMIC) {
            cout<<"academic";
        }
        else {
            cout<<"roman";
        }
        cout<<" "<<price<<endl;
    }
    void increasePrice(float p) {
        this->price+=p;
    }
    const char *getTitle() const {
        return title;
    }
    Type getType() const {
        return type;
    }
    float getPrice() const {
        return price;
    }
};
class BookStore {
    char name[21];
    Book books[100];
    int number;
public:
    BookStore (const char *name=" ") {
        strcpy(this->name, name);
        this->number = 0;
    }
    // BookStore (const char *name, Book books[], int number) {
    //     strcpy(this->name, name);
    //     this->number = number;
    //     for(int i=0; i<number; i++) {
    //         this->books[i]=books[i];
    //     }
    // }
    // BookStore(const BookStore &bs) {
    //     strcpy(this->name, bs.name);
    //     this->number = bs.number;
    //     for(int i=0; i<number; i++) {
    //         books[i]=bs.books[i];
    //     }
    // }
    void print() {
        cout<<name<<endl;
        for(int i=0; i<number; i++) {
            books[i].print();
        }
    }
    void addBook(const Book& b) {
        if(number<100) {
            for(int i=0; i<number; i++) {
                if(strcmp(b.getTitle(), books[i].getTitle())==0) {
                    return;
                }
            }
            books[number]=b;
            number++;
        }
        return;
    }
    bool greaterThan(const BookStore& bs) {
        return (this->number>bs.number);
    }
    void createMarketPrice() {
        for(int i=0; i<number; i++) {
            if(books[i].getType()==ACADEMIC) {
                books[i].increasePrice(books[i].getPrice()*0.05);
            }
            else {
                books[i].increasePrice(books[i].getPrice()*0.03);
            }
        }
    }
    friend BookStore best(BookStore bs[],int number);
};

BookStore best(BookStore bs[],int n) {
    BookStore max = bs[0];
    for(int i=0; i<n; i++) {
        if(bs[i].number>max.number) {
            max = bs[i];
        }
    }
    return max;

}
int Book::serial=777550;
int main() {
    int testCase;
    cin>>testCase;
    if(testCase==0)
    {
        cout<<"TESTING BOOK CONSTRUCTOR"<<endl;
        Book book1("Object-oriented programming",0,2300);
        Book book2("Discrete Mathematics",0,1800);
        Book book3("Crime and punishment",1,950);
        cout<<"TEST PASSED"<<endl;
    }else if(testCase==1)
    {
        cout<<"TESTING BOOK print()"<<endl;
        Book book1("Object-oriented programming",0,2300);
        Book book2("Discrete Mathematics",0,1800);
        Book book3("Crime and punishment",1,950);
        book1.print();
        book2.print();
        book3.print();
        cout<<"TEST PASSED"<<endl;
    } else if(testCase==2)
    {
        cout<<"TESTING BOOK increasePrice"<<endl;
        Book book1("Object-oriented programming",0,2300);
        Book book2("Discrete Mathematics",0,1800);
        Book book3("Crime and punishment",1,950);
        book1.print();
        book2.print();
        book3.print();
        book1.increasePrice(200);
        book2.increasePrice(300);
        book3.increasePrice(150);
        cout<<"===== INCREASE ====="<<endl;
        book1.print();
        book2.print();
        book3.print();
        cout<<"TEST PASSED"<<endl;
    }else if(testCase==3)
    {
        cout<<"TESTING BOOKSTORE CONSTRUCTOR"<<endl;
        BookStore bookStore1("The Book Cellar");
        bookStore1.print();
        cout<<"TEST PASSED"<<endl;
    }else if(testCase==4)
    {
        cout<<"TESTING BOOKSTORE addBook() and print()"<<endl;
        Book book1("Object-oriented programming",0,2300);
        Book book2("Discrete Mathematics",0,1800);
        Book book3("Crime and punishment",1,950);
        BookStore bookStore1("The Book Cellar");
        bookStore1.addBook(book1);
        bookStore1.addBook(book2);
        bookStore1.addBook(book3);
        bookStore1.print();
        cout<<"TEST PASSED"<<endl;
    }
    else if(testCase==5)
    {
        cout<<"TESTING BOOKSTORE OPERATOR addBook() and print()"<<endl;
        Book book1("Object-oriented programming",0,2300);
        Book book2("Discrete Mathematics",0,1800);
        Book book3("Crime and punishment",1,950);
        Book book4("Object-oriented programming",0,2300);
        BookStore bookStore1("The Book Cellar");
        bookStore1.addBook(book1);
        bookStore1.addBook(book2);
        bookStore1.addBook(book3);
        bookStore1.addBook(book4);
        bookStore1.print();
        cout<<"TEST PASSED"<<endl;
    }
    else if(testCase==6)
    {
        cout<<"TESTING BOOKSTORE COPY-CONSTRUCTOR"<<endl;
        Book book1("Object-oriented programming",0,2300);
        Book book2("Discrete Mathematics",0,1800);
        Book book3("Crime and punishment",1,950);
        Book book4("Anna Karenina",1,1200);
        Book book5("Calculus 1",0,1320);
        BookStore bookStore1("The Book Cellar");
        bookStore1.addBook(book1);
        bookStore1.addBook(book2);
        bookStore1.addBook(book3);
        BookStore bookStore2(bookStore1);

        bookStore1.print();
        bookStore2.print();
        cout<<"TEST PASSED"<<endl;

    }else if(testCase==7)
    {
        cout<<"TESTING BOOKSTORE greaterThan "<<endl;
        Book book1("Object-oriented programming",0,2300);
        Book book2("Discrete Mathematics",0,1800);
        Book book3("Crime and punishment",1,950);
        Book book4("Anna Karenina",1,1200);
        Book book5("Calculus 1",0,1320);
        BookStore bookStore1("The Book Cellar");
        bookStore1.addBook(book1);
        bookStore1.addBook(book2);
        bookStore1.addBook(book3);
        BookStore bookStore3("Word Wizardry Books");
        bookStore3.addBook(book4);
        bookStore3.addBook(book5);
        if(bookStore1.greaterThan(bookStore3))
        {
            cout<<"TEST PASSED"<<endl;
        }
        else
        {
            cout<<"TEST FAILED"<<endl;
        }
    }else if(testCase==8)
    {
        cout<<"TESTING METHOD createMarketPrice()"<<endl;
        char name[30],name1[30];
        int type, numofBookStores, numberOfBooks;
        float price;
        cin>>numofBookStores;
        cin.ignore();
        BookStore bookStores[10];
        for(int i=0;i<numofBookStores;i++)
        {
            cin.getline(name,20);
            bookStores[i]=BookStore(name);
            cin>>numberOfBooks;
            cin.ignore();
            Book books[10];
            for(int j=0;j<numberOfBooks;j++)
            {
                cin >> name1 >> type >> price;
                cin.ignore();
                books[j]=Book(name1,type,price);
                bookStores[i].addBook(books[j]);
            }
        }
        for(int i=0;i<numofBookStores;i++)
        {
            bookStores[i].print();
            cout<<"CREATED MARKET PRICES"<<endl;
            bookStores[i].createMarketPrice();
            bookStores[i].print();
        }

    }else if(testCase==9)
    {
        cout<<"TESTING METHOD best()"<<endl;
        char name[30],name1[30];
        int type, numofBookStores, numberOfBooks;
        float price;
        cin>>numofBookStores;
        cin.ignore();
        BookStore bookStores[10];
        for(int i=0;i<numofBookStores;i++)
        {
            cin.getline(name,20);
            bookStores[i]=BookStore(name);
            cin>>numberOfBooks;
            cin.ignore();
            Book books[10];
            for(int j=0;j<numberOfBooks;j++)
            {
                cin >> name1 >> type >> price;
                cin.ignore();
                books[j]=Book(name1,type,price);
                bookStores[i].addBook(books[j]);
            }
        }
        best(bookStores,numofBookStores).print();
    }
    return 0;
}