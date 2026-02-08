#include <iostream>
#include <windows.h>


int main()
{
    setlocale(LC_CTYPE, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    using namespace std;
   char a;
    cout << "Введите символ: ";
    cin >> a;
    if (isdigit(a))
    {
        cout << "Это цифра." << endl;
        cout << "Код символа: " << (int)(unsigned char)a;
    }
    else
    {
        if ((a >= 'a' and a <= 'z') or (a >= 'A' and a <= 'Z'))
        {
            cout << "Это латинская буква." << endl;
            cout << "Код символа: " << (int)(unsigned char)a;
        }
        else
        {
            if ((a >= 'а' and a <= 'я') or (a >= 'А' and a <= 'Я'))
            {
                cout << "Это русская буква." << endl;
                cout << "Код символа: " << (int)(unsigned char)a;
            }
            else
            {
                cout << "Это не русская или латинская буква и не цифра." << endl;
            }
        }
    }
    return 0;
}
