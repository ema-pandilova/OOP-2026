//
// Created by ema on 13.3.26.
//
#include<iostream>
#include<cstring>
using namespace std;

class Team {
private:
    char name[50];
    int year;
    char city[50];

public:
    // Team() {
    //     strcpy(name,"");
    //     year = 0;
    //     strcpy(city,"");
    // }
    // Team(char * _name, int _year, char * _city) {
    //     strcpy(name, _name);
    //     year = _year;
    //     strcpy(city, _city);
    // }
    Team(char *_name = "", int _year = 0, char *_city = "Madrid") {
        strcpy(name, _name);
        year = _year;
        strcpy(city, _city);
    }

    ~Team() {
    }

    void print() {
        cout << name << " " << year << " " << city << endl;
    }

    bool isEqual(Team &other) {
        return strcmp(name, other.name) == 0;
    }

    char *getName() {
        return name;
    }
};

class Game {
private:
    Team host;
    Team guest;
    int hostGoals;
    int guestGoals;

public:
    Game() {
        hostGoals = guestGoals = 0;
    }

    Game(Team _host = Team(), Team _guest = Team(), int _hostGoals, int _guestGoals) {
        host = _host;
        guest = _guest;
        hostGoals = _hostGoals;
        guestGoals = _guestGoals;
    }

    bool isRevansh(Game other) {
        return host.isEqual(other.guest) && (guest.isEqual(other.host));
    }

    ~Game() {
    }
};

int main() {
    Team t1("Barcelona", 2001);
    t1.print();
}
