#include <iostream>
#include <windows.h>
#include <cctype>

int main()
{
    setlocale(LC_CTYPE, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    using namespace std;
    int d;
    char a, b;
    cout << "Выберите вариант использавания программы: ";
    cin >> d;
    switch (d) {
    case 1: {

        cout << "Введите символ: " ;
        cin >> (a);
        if ((a >= 'a' and a <= 'z') or (a >= 'A' and a <= 'Z'))
        {
            a = tolower(a);
            b = toupper(a);
            a = (int)(unsigned char)a - (int)(unsigned char)b;
            cout << "Разница кодов между заглавной и прописной латинской буквой = " << (int)a << endl;
            
        }
        else
        
            cout << "Введён неизвестный символ" << endl;
        break;
    }
    case 2:
    {
        cout << "Введите символ: ";
        cin >> (a);
        if ((a >= 'а' and a <= 'я') or (a >= 'А' and a <= 'Я')) {
            a = tolower(a);
            b = toupper(a);
            a = (int)(unsigned char)a - (int)(unsigned char)b;
            cout << "Разница кодов между заглавной и прописной русской буквой = " << (int)a << endl;
        }
        else
            cout << "Введён неизвестный символ" << endl;
        break;
    }
    case 3:
    {
        cout << "Введите символ: ";
        cin >> (a);
        if (isdigit(a)) {
            cout << "Код цифры = " << (int)a << endl;
        } else
            cout << "Введён неизвестный символ" << endl;
        break;
    }

    default:  cout << "Нет такого варианта" << endl;
    }
    
    cout << "Выходим из программы";
    return 0;
}
