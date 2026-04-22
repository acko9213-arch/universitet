#include <fstream>
#include <iostream>
#include <Windows.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    ofstream file("FILE1.txt");

    if (file.fail())  {
        cout << "\n Ошибка открытия файла." << endl;
        return 1;
    }

    char buff[201];
    cout << "Введите строку слов с пробелами до 200 символов:";
    cin.getline(buff, 201);
    file << buff;
    cout << "Слова с буквой 'х':" << endl;
    char word[30];
    file.close();
    ifstream file1("FILE1.txt");
    if (file1.fail()) {
        cout << "\n Ошибка открытия файла." << endl;
        return 1;
    }
    while (file1 >> word)
    {
        for (int i = 0; word[i] != '\0'; i++)
        {
            if (word[i] == 'х')
            {
                cout << word << ", ";
            }
        }
    }
    
 
    file1.close();
    return 0;
}