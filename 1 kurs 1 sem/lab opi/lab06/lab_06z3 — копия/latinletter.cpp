#include "first.h"
#include <windows.h>
#include <cctype>
void latinletter() {
    setlocale(LC_CTYPE, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    using namespace std;
    char a, b;
    int h;
    cout << "Введите сколько символов вы хотите ввести: "; cin >> h;
    for (int n = 1; n <= h; n++) {
        cout << "Введите символ: ";
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

    }
}