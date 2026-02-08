#include <iostream>

void main() {
    using namespace std;
    setlocale(LC_CTYPE, "Russian");

    float a = 2, b = 7.0, n=200, s = 0, h, x;

    
    h = (b - a) / n;

    for (x = a; x < (b - h); x += h) {
        s = s + (h * (pow(sin(x),2)+1 + pow(sin(x+h), 2) + 1))/ 2;
    }

    cout << "s = " << s << endl;
}