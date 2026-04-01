//
// Created by ema on 1.4.26.
//
#include <iostream>
#include <cstring>
#include <cctype>
#include <optional>
#include<iomanip>
using namespace std;

// Да се дефинира класа SMS, во која ќе се чуваат информации за датумот на пораката (објект од класа Date), содржина на пораката (низа од 150 карактери) и два телефонски броја (текстуални низи од 9 цифри за број кој испраќа и број кој прима). (10 поени)
// Класата Date треба да содржи три цели броеви за ден, месец и година. (5 поени)
// Да се напише main функција во која се чита цел броj N (max 500), a потоа информации за N пораки. Читањето на една порака е во следниот формат:
//
// dd mm yyyy
// број_што_праќа
// број_што_прима
// содржина. (10 поени)
//
// Пример влез:
//
// 18 03 2016
// 070211123
// 071300400
// I'll call you back
//
// На екран да се испечатат сите пораки каде бројот што праќа е бројот 070214011 и се испратени во периодот од 1.1.2019 до 31.12.2020, вклучувајќи ги и датумите 1.1.2019 и 31.12.2020. (15 поени)
//
// Да се испечати вкупниот број на карактери на тие пораки (5 поени)
//
// Форматот на печатење да се види од тест примерите.
//
//
// ПОМОШ: Да се вклучи библиотеката #include<iomanip> за датумите да се испечатат со наредбата
//  cout << setfill('0') << setw(2) << day << "/" << setfill('0') << setw(2) << month << "/" << year

class Date {
    int day;
    int month;
    int year;
public:
    Date(int day=0, int month=0, int year=0) {
        this->day = day;
        this->month = month;
        this->year = year;
    }
    void print() {
        cout << setfill('0') << setw(2) << day << "/" << setfill('0') << setw(2) << month << "/" << year;
    }
    int getYear() {
        return year;
    }
};
class SMS {
    Date date;
    char content[151];
    char sender[10];
    char receiver[10];
public:
    SMS (){}
    SMS (Date date, const char * sender, const char * receiver, const char * content) {
        this->date = date;
        strcpy(this->sender, sender);
        strcpy(this->receiver, receiver);
        strcpy(this->content, content);
    }
    const char *getSender() const {
        return sender;
    }
    Date &getDate() {
        return date;
    }
    void print() {
        date.print();
        cout<<" "<<sender<<" "<<receiver<<" "<<content<<endl;
    }

    int getLength() {
        return strlen(content);
    }

};
bool filterMessages(SMS &sms) {
    return ((strcmp(sms.getSender(),"070214011")==0) && (sms.getDate().getYear()==2019 || sms.getDate().getYear()==2020));
    //     return true;
    // }
    // return false;
}
int main() {
    int N;
    cin>>N;
    int day;
    int month;
    int year;
    char content[151];
    char sender[10];
    char receiver[10];
    SMS messages[];
    for(int i=0;i<N;i++) {
        cin>>day>>month>>year;
        cin>>sender>>receiver;
        cin.ignore();
        cin.getline(content,151);
        messages[i]=SMS(Date(day, month,year), sender, receiver, content);
    }
int total=0;
    for(int i=0;i<N;i++) {
        if(filterMessages(messages[i])) {
            messages[i].print();
            total+=messages[i].getLength();
        }
    }
    cout<<total<<" characters"<<endl;
}