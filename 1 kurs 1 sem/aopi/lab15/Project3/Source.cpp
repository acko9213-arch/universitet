#include <iostream>

int main()
{
    using namespace std;
    setlocale(LC_CTYPE, "Russian");
    char t[33];
    int N;
    cout << "¬ведите число:";
    cin >> N;
   
    _itoa_s(N,t, 10);
    cout << t;
    for (int i = 0; t[i] != '\0'; i++)
    {
        N = N * 10 + (t[i] - '0');
    }
    cout << N;

    return 0;
}