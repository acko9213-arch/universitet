#include <iostream>

void main() {
    using namespace std;
    setlocale(LC_CTYPE, "Russian");

    float a = 2, b = 7, n, s1 = 0,
        s2 = 0, h, x, s;

    cout << "¬ведите n ";
    cin >> n;

    h = (b - a) / (2 * n);
    x = a + (2 * h);

    for (int i = 1; i < n; i++) {
        s1 += pow(sin(x), 2) + 1;
        x += h;
        s2 += pow(sin(x),2) + 1;
        x += h;
    }

    s = (h / 3) * (pow(sin(a), 2) + 1 + (4 * (pow(sin(a+h), 2) + 1)) + (4 * s1) + (2 * s2) + pow(sin(b), 2) + 1);

    cout << "s = " << s;
}