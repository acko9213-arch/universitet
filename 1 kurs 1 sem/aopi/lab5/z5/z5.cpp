#include <iostream>
int main()
{
    int a, b, c, r, s, t;
    using namespace std;
    setlocale(LC_CTYPE, "Russian");
    cout << "Введите длину коробки ";
    cin >> a;
    cout << "Введите ширину коробки ";
    cin >> b;
    cout << "Введите высоту коробки ";
    cin >> c;
    cout << "Введите длину посылки ";
    cin >> r;
    cout << "Введите ширину посылки ";
    cin >> s;
    cout << "Введите высоту посылки ";
    cin >> t;
    if (r * s * t > a * b * c)
        cout << "Коробка поместится";
    else
        cout << "Коробка не поместится";
    return 0;
}