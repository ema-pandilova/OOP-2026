//
// Created by ema on 11.5.26.
//
#include <iostream>
#include <cstring>
#include <fstream>
#include <cctype>
using namespace std;

int main() {
    ifstream fileInput("/home/ema/CLionProjects/OOP2026/aud11/primer.txt");
    if (!fileInput.is_open()) {
        //dali e otvorena datotekata - proverka
        cout << "Error opening file" << endl;
        return -1;
    }
    char c;
    int totalSamoglaski = 0; //vkupno samoglaski
    int totalRows = 0; // vkupno redovi so 10+ samoglaski
    int rowSamoglaski = 0; // broj na samoglaski vo daden red

    while (fileInput.get(c)) {
        c = tolower(c);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            totalSamoglaski++;
            rowSamoglaski++;
        }
        if (c == '\n') { // if (c == '\n' || fileInput.peek() == EOF) vtora opcija za da se izbegne posldniot if nadvor od while
            if (rowSamoglaski > 10) {
                totalRows++;
            }
            rowSamoglaski = 0;
        }
    }
    //  last line in the file doesn't have \n - we should check the counter once again
    if (rowSamoglaski > 10) {
        totalRows++;
    }
    cout << totalSamoglaski << endl;
    cout << totalRows << endl;
}
