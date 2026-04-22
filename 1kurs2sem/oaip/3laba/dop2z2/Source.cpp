#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main() {
    setlocale(LC_CTYPE, "rus");

    char input[1024];
    cout << "Введите строку из групп цифр и нулей: ";
    cin.getline(input, 1024);

   
    ofstream outFile("task2.txt");
    outFile << input;
    outFile.close();

    
    ifstream inFile("task2.txt");
    char tGroup[256];
    char shortest[256];
    int minLen = 10000;
    bool found = false;

    while (inFile >> tGroup) {
        int currentLen = strlen(tGroup);

        if (currentLen < minLen) {
            minLen = currentLen;
            strcpy_s(shortest, tGroup); 
            found = true;
        }
    }
    inFile.close();

    if (found) {
        cout << "Самая короткая группа: " << shortest << endl;
        cout << "Длина: " << minLen << endl;
    }
    else {
        cout << "Файл пуст." << endl;
    }

    return 0;
}