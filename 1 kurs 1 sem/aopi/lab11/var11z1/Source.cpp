#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Russian");
    char tmp[33];
    int A;
    cout << "Число А="; cin >> A;
    _itoa_s(A, tmp, 2);
    if ((A & 1) == 0)
    {
        cout << "Число A четное";
    }
    else
    {
        cout << "Число A нечетное";
    }

    return 0;
}