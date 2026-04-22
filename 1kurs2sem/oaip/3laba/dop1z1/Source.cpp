#include <iostream>
#include <fstream>

using namespace std;

int main() {
    setlocale(LC_CTYPE, "rus");
    ifstream fin("FILE1.txt");
    ofstream fout("FILE2.txt");

    if (!fin.is_open()) {
        cout << "Ошибка открытия!" << endl;
        return 1;
    }

    char buffer[1024];
    int lineNum = 1;

    while (fin.getline(buffer, 1024)) {
        if (lineNum % 2 == 0) {
            fout << buffer << endl;
        }
        lineNum++;
    }

    fin.close();
    fout.close();
    ifstream f1("FILE1.txt", ios::binary | ios::ate);
    ifstream f2("FILE2.txt", ios::binary | ios::ate);

    cout << "Размер FILE1: " << f1.tellg() << " байтов " << endl;
    cout << "Размер FILE2: " << f2.tellg() << " байтов" << endl;

    f1.close();
    f2.close();

    return 0;
}