#include <iostream> 
#include <string>
#define MAX 32000
using namespace std;
void proverka(string x)
{
    cout << "Введите строку для проверки скобочек:";
    getline(cin, x);
    int zakr = 0;
    for (int i = 0; i < x.length(); i++)
    {
        if (x[i] == '(')
        {
            zakr++;
        }
        if (x[i] == ')')
        {
            zakr--;
        }
    }
    if (zakr==0)
    {
        cout << "Скобочки расставлены правильно" << endl;

    }
    else
    {
        cout << "Скобочки расставлены неправильно" << endl;

    }
    int q;
    cout << "Продолжить проверку строк?(1 - ДА,2 - НЕТ)" << endl;
    cin >> q;
    switch (q)
    {
    case 1: cin.clear(); cin.ignore(MAX, '\n'); proverka(x); break;
    case 2: cout << "Программа закончена."; break;
    default:  cout << "Вы ввели не то число."; break;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    string line;
    
    proverka(line);
    return 0;
}