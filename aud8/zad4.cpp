//
// Created by ema on 21.4.26.
//
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

/*
    *  Group: FINKI
       Members: 14
       Rating: 1
       Members list:
       1. Username: dejan Company name: FINKI Position: 1
       2. Username: ivan Company name: FINKI Position: 1
       3. Username: ana Company name: FINKI Position: 1
       4. Username: nevena Company name: FINKI Position: 1
       5. Username: ivica Company name: FINKI Position: 2
       6. Username: gjorgji Company name: FINKI Position: 2
       7. Username: kate Company name: FINKI Position: 3
       8. Username: hristina Company name: FINKI Position: 3
       9. Username: bobi Company name: FINKI Position: 3
       10. Username: tenev Company name: FINKI Position: 4
       11. Username: stojmenski Company name: FINKI Position: 4
       12. Username: stefan Company name: FINKI Position: 5
       13. Username: vlatko Company name: FINKI Position: 5
       14. Username: dimitar Company name: FINKI Position: 5
    * */

class User {
private:
    char *username;
    char *company;
    int level;

public:
    User(char *username = "", char *company = "", int level = 0) {
        this->username = new char[strlen(username) + 1];
        strcpy(this->username, username);
        this->company = new char[strlen(company) + 1];
        strcpy(this->company, company);
        this->level = level;
    }

    User(const User &other) {
        this->username = new char[strlen(other.username) + 1];
        strcpy(this->username, other.username);
        this->company = new char[strlen(other.company) + 1];
        strcpy(this->company, other.company);
        this->level = other.level;
    }

    User &operator=(const User &other) {
        if (this != &other) {
            delete [] this->username;
            delete [] this->company;
            this->username = new char[strlen(other.username) + 1];
            strcpy(this->username, other.username);
            this->company = new char[strlen(other.company) + 1];
            strcpy(this->company, other.company);
            this->level = other.level;
        }
        return *this;
    }

    ~User() {
        delete [] this->username;
        delete [] this->company;
    }

    friend istream &operator>>(istream &is, User &user) {
        char tempUsername[50];
        char tempCompany[50];

        is >> tempUsername >> tempCompany >> user.level;
        delete [] user.username;
        delete [] user.company;

        user.username = new char[strlen(tempUsername) + 1];
        strcpy(user.username, tempUsername);
        user.company = new char[strlen(tempCompany) + 1];
        strcpy(user.company, tempCompany);
        return is;
    }

    friend ostream &operator<<(ostream &os, const User &user) {
        os << user.level << " " << user.company << " " << user.username;
        return os;
    }

    bool operator ==(User &u) {
        return strcmp(this->username, u.username) == 0;
    }

    int getLevel() {
        return this->level;
    }
};

class Group {
protected:
    User *users;
    int n;
    string name;

public:
    Group(string name = "") {
        this->users = nullptr;
        this->n = 0;
        this->name = name;
    }

    virtual void addMember(User &u) {
        for (int i = 0; i < n; i++) {
            if (users[i] == u) {
                return;
            }
        }
        User *temp = new User[n + 1];
        for (int i = 0; i < n; i++) {
            temp[i] = users[i];
        }
        temp[n] = u;
        n++;
        delete [] users;
        users = temp;
    }

    virtual double averageLevel() const {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += users[i].getLevel();
        }
        return (double) sum / n;
    }

    virtual double rating() const {
        return (10 - averageLevel()) * n / 100;
    }

    friend ostream &operator<<(ostream &os, const Group &g) {
        os << g.name << endl;
        for (int i = 0; i < g.n; i++) {
            os << g.users[i] << endl;
        }
    }
};

class PrivateGroup : public Group {
public:
    static int capacity;
    static float coeficient;

public:
    PrivateGroup(string name = ""): Group(name) {
    }

    static void setCapacity(int capacity) {
        PrivateGroup::capacity = capacity;
    }

    void addMember(User &u) {
        if (n + 1 > capacity) {
            return;
        }
        Group::addMember(u);
    }

    double rating() const {
        return (10 - averageLevel() * (double(n) / capacity) * coeficient);
    }

    friend ostream &operator<<(ostream &os, const PrivateGroup &g) {
        Group group(g);
        os << g;
        return os;
    }
};

int PrivateGroup::capacity = 10;
float PrivateGroup::coeficient = 0.8;

int main() {
    cout << "INTEGRATION TEST" << endl;
    char name[50];
    int nGroups;
    cin >> nGroups;
    Group **groups = new Group *[nGroups];
    for (int i = 0; i < nGroups; i++) {
        int type;
        cin >> type;
        cin >> name;
        if (type == 1) {
            //normal group
            groups[i] = new Group(name);
        } else {
            //private group
            groups[i] = new PrivateGroup(name);
        }
        int nUsers;
        cin >> nUsers;
        for (int j = 0; j < nUsers; j++) {
            User u;
            cin >> u;

            groups[i]->addMember(u);
        }
    }

    cout << "BEFORE CHANGE OF PRIVATE GROUP COEFFICIENT" << endl;
    for (int i = 0; i < nGroups; ++i) {
        cout << *groups[i];
    }
    PrivateGroup::setCapacity(15);
    cout << "AFTER CHANGE OF PRIVATE GROUP COEFFICIENT" << endl;
    for (int i = 0; i < nGroups; ++i) {
        cout << *groups[i];
    }
}
