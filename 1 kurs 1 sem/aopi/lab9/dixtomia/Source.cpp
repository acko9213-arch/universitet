#include <iostream>
#include <Windows.h>

using namespace std;


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double a, b, e = 0.0001, x;
    cout << "Введите a" << endl;
    cin >> a;
    cout << "Введите b" << endl;
    cin >> b;

    while (abs(a - b) > 2 * e) {
        x = (a + b) / 2;
        if ((sin(x) + 2 + x) * (sin(x) + 2 + x) <= 0) {
            b = x;
        }
        else a = x;
    }

    cout << "Ответ: " << x << endl;


}
