#include <iostream>
#include <windows.h>
#include <cctype>

#include "first.h"

int main()
{
    setlocale(LC_CTYPE, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    using namespace std;
    int d;
    
    cout << "Выберите вариант использавания программы: ";
    cin >> d;
    switch (d) {
    case 1: {
        latinletter(); break;
    }
    case 2:
    {
        russianletter(); break;
    }
    case 3:
    {
        number(); break;
    }

    default:  cout << "Нет такого варианта" << endl;
    }

    cout << "Выходим из программы";
    return 0;
}