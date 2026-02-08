#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Russian");
    char tmp[33];
    int A, mask, n, p;
    cout << "Число n="; cin >> p;
    cout << "Число p="; cin >> n;
    cout << "Число А="; cin >> A;
    _itoa_s(A, tmp, 2);
    cout << tmp << endl;
    mask = ~(((1 << p) - 1) << n);
    _itoa_s( mask, tmp, 2);
    cout << tmp << endl;
    
    _itoa_s( mask & A, tmp, 2);
    cout << tmp << endl;

    return 0;
}


