//
// Created by ema on 11.5.26.
//
#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("/home/ema/CLionProjects/OOP2026/aud11/vlezna.txt"); // ifstream - klasa za chitanje datoteki
    ofstream fout("/home/ema/CLionProjects/OOP2026/aud11/izlezna.txt"); //ofstream - klasa za pishuvanje vo datoteki

    if (!fin.is_open()) { // proverka dali se otvori
        cout << "Failed to open input stream" << endl;
        return -1;
    }

    if (!fout.is_open()) { // proverka dali se otvori
        cout << "Failed to open output stream" << endl;
        return -1;
    }
    string line;
    while (getline(fin, line)) { //prochitaj red od vlezna.txt
        fout << line << endl;  // zapishi go vo izlezna.txt
        fout << line.length() << endl;
    }
    return 0;
}
