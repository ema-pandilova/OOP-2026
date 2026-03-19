//
// Created by ema on 16.3.26.
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
    Team(char *name = "", int year = 0, char *city = "") {
        strcpy(this->name, name);
        this->year = year;
        strcpy(this->city, city);
    }

    Team(const Team &t) {
        cout << "Team copy constructor called" << endl;
        strcpy(this->name, t.name);
        this->year = t.year;
        strcpy(this->city, t.city);
    }

    void print() {
        cout << name << " " << year << " " << city << endl;
    }

    char *getName() {
        return name;
    }
};

class Match {
private:
    Team host;
    Team guest;
    int hostGoals;
    int guestGoals;

public:
    Match(Team host = Team(), Team guest = Team(), int hostGoals = 0, int guestGoals = 0) {
        this->host = host;
        this->guest = guest;
        this->hostGoals = hostGoals;
        this->guestGoals = guestGoals;
    }

    Match(const Match &m) {
        cout << "Match copy constructor called" << endl;
        this->host = m.host;
        this->guest = m.guest;
        this->hostGoals = m.hostGoals;
        this->guestGoals = m.guestGoals;
    }

    friend bool isRevansh(Match m1, Match m2);

    friend Team duel(Match m1, Match m2);
};

bool isRevansh(Match m1, Match m2) {
    if (strcmp(m1.host.getName(), m2.guest.getName()) == 0 && strcmp(m1.guest.getName(), m2.host.getName()) == 0) {
        return true;
    } else {
        return false;
    }
}

Team duel(Match m1, Match m2) {
    if (isRevansh(m1, m2)) {
        int team1Goals = m1.hostGoals + m2.guestGoals;
        int team2Goals = m1.guestGoals + m2.hostGoals;
        if (team1Goals > team2Goals) {
            return m1.host;
        } else if (team1Goals < team2Goals) {
            return m1.guest;
        } else {
            return nullptr;
        }
    } else {
        return nullptr;
    }
}

int main() {
    Team t1("Barcelona", 1890, "Barcelona");
    t1.print();
    Team t2("Real Madrid", 1900, "Madrid");
    Match m1(t1, t2, 3, 2);
    Match m2(t2, t1, 3, 3);

    Team winner = duel(m1, m2);
    if (isRevansh(m1, m2)) {
        cout << winner.getName() << endl;
    } else {
        cout << "Not a revansh" << endl;
    }
}
