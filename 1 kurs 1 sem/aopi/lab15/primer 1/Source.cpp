#include <iostream>
using namespace std;

void main()
{
    setlocale(LC_CTYPE, "Russian");
    char* pStr;
    char c, * pc;
    int j, length, count = 0;
    cout << "Введите размер строки ";
    cin >> length;
    pStr = new char[length + 1];
    cout << "Введите строку ";
    cin >> pStr;
    cout << "Введите символ ";
    cin >> c;
    pc = &c;
    for (j = 0; j < length; j++)
        if (pStr[j] == *pc)
            count++;
    cout << count << " повторений символа " << c << endl;
    delete[] pStr;
}