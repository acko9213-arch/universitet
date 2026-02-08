#include "first.h"
#include <windows.h>
#include <cctype>
void number()

{
    setlocale(LC_CTYPE, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    using namespace std;
    char a, b;
    int h;
    cout << "Введите сколько символов вы хотите ввести: "; cin >> h;
    for (int n = 1; n <= h; n++)
    {
        cout << "Введите символ: ";
        cin >> (a);
        if (isdigit(a)) {
            cout << "Код цифры = " << (int)a << endl;
        }
        else
            cout << "Введён неизвестный символ" << endl;

    }
}