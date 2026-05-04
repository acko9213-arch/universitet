#include <iostream>
#include <cfloat>
#include "Varparm.h"
using namespace std;
using namespace Varparm;
int main() {
    setlocale(LC_CTYPE, "rus");

    int a =ivarparm(4, 1, 2, 3, 7);
    cout << "Произведение a: " << a << endl;

    int b = svarparm(4, 1, 2, 3, 7);
    cout << "Максимум b: " << b << endl;

    double c = fvarparm(1.f, 2.f, 3.f, 7.f, FLT_MAX);
    cout << "Сумма c: " << c << endl;

    double d = dvarparm(1.0, 2.0, 3.0, 7.0, DBL_MAX);
    cout << "Сумма d: " << d << endl;

    return 0;
}