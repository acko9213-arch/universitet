#include "FileName1.h"

void Source()
{

    setlocale(LC_CTYPE, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    using namespace std;
    double d, b, f;
    char a;
    cout << "¬ведите первое число ";
    cin >> d;
    cout << "¬ведите знак ";
    cin >> a;
    cout << "¬ведите второе число ";
    cin >> b;

    if (a == '+')
    {
        f = d + b;
        cout << d << '+' << b << '=' << f;

    }
    else
        if (a == '-')
        {
            f = d - b;
            cout << d << '-' << b << '=' << f;

        }
        else
            if (a == '*')
            {
                f = d * b;
                cout << d << '*' << b << '=' << f;

            }
            else
                if (a == '/')
                {
                    f = d / b;
                    cout << d << '/' << b << '=' << f;

                }
}