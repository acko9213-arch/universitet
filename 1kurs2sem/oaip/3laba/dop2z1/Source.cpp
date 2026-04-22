#include <iostream>
#include <fstream>

using namespace std;

int main() {
    setlocale(LC_CTYPE, "rus");

    ifstream fin("FILE1.txt");
    ofstream fout("FILE2.txt");

    if (!fin.is_open()) {
        cout << "Ошибка: FILE1.txt не найден!" << endl;
        return 1;
    }

    char line[1024];
    while (fin.getline(line, 1024)) {
        
        if (line[0] == 'A' || line[0] == 'a' || (unsigned char)line[0] == 208 || (unsigned char)line[0] == 192) {
           
            fout << line << endl;
        }
    }
    fin.close();
    fout.close();

    
    ifstream f2("FILE2.txt");
    int wordCount = 0;
    char word[256];

    
    while (f2 >> word) {
        wordCount++;
    }
    f2.close();

    cout << "Количество слов в FILE2: " << wordCount << endl;

    return 0;
}