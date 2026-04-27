//
// Created by ema on 17.4.26.
//
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

class TennisPlayer {
protected:
    char *name;
    char *surname;
    bool league;

    void copy(const TennisPlayer &p) {
        this->name = new char[strlen(p.name) + 1];
        strcpy(this->name, p.name);
        this->surname = new char[strlen(p.surname) + 1];
        strcpy(this->surname, p.surname);
        this->league = p.league;
    }

public:
    TennisPlayer(char *name = "", char *surname = "", bool league = false) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->surname = new char[strlen(surname) + 1];
        strcpy(this->surname, surname);
        this->league = league;
    }

    TennisPlayer(const TennisPlayer &p) {
        copy(p);
    }

    TennisPlayer &operator=(const TennisPlayer &p) {
        if (this != &p) {
            delete[] this->name;
            delete[] this->surname;
            copy(p);
        }
        return *this;
    }

    ~TennisPlayer() {
        delete[] this->name;
        delete[] this->surname;
    }

    friend ostream &operator<<(ostream &os, const TennisPlayer &p) {
        os << p.name << " " << p.surname << " ";
        if (p.league) {
            os << "TRUE" << endl;
        } else {
            os << "FALSE" << endl;
        }
        return os;
    }
};

class RankedTennisPlayer : public TennisPlayer {
private:
    int rank;

public:
    RankedTennisPlayer(char *name = "", char *surname = "", bool league = true, int rank = 1): TennisPlayer(
        name, surname, league) {
        this->rank = rank;
    }

    RankedTennisPlayer(TennisPlayer tp, int rank) {
        TennisPlayer::copy(tp);
        this->rank = rank;
    }

    RankedTennisPlayer(const RankedTennisPlayer &p) : TennisPlayer(p) {
        this->rank = p.rank;
    }

    RankedTennisPlayer &operator=(const RankedTennisPlayer &p) {
        if (this != &p) {
            TennisPlayer::operator=(p);
            this->rank = p.rank;
        }
        return *this;
    }

    friend ostream &operator<<(ostream &os, const RankedTennisPlayer &rp) {
        TennisPlayer tp(rp);
        os << tp << "  " << rp.rank;
        return os;
    }

    // ~RankedTennisPlayer() {
    //     delete[] this->name;
    //     delete[] this->surname;
    // }
};

int main() {
    TennisPlayer tp1("Rafael", "Nadal");
    cout << tp1 << endl;
    RankedTennisPlayer tp2("Tome", "Eftimov", true, 3);
    cout << tp2 << endl;
}
