// //
// // Created by ema on 27.3.26.
// //
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

class String {
private:
    char *content;

    void copy(const String &str) {
        this->content = new char [strlen(str.content) + 1];
        strcpy(this->content, str.content);
    }

public:
    String(char *content = "") {
        this->content = new char [strlen(content) + 1];
        strcpy(this->content, content);
    }

    String(const String &str) {
        // this->content = new char [strlen(str.content)+1];
        // strcpy(this->content, str.content);
        copy(str);
    }

    ~String() {
        delete [] content;
    }

    String &operator=(const String &str) {
        if (this != &str) {
            delete [] content;
            // this->content = new char [strlen(str.content)+1];
            // strcpy(this->content, str.content);
            copy(str);
        }
        return *this;
    }
};

int main() {
    String str[10];
}
