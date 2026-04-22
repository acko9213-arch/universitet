#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>
using namespace std;
const int N = 3;



int main() {
    setlocale(LC_CTYPE, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string candidats[N];

    static int results[N][100];
    cout << "Введите имена кандидатов: " << endl;
    for (int i = 0; i < N; i++) {
        getline(cin, candidats[i]);
    }
    for (int i = 0; i < N; i++) {
        cout << i + 1 << ") " << candidats[i] << endl;
    }

    int cand = 0, n = 0;

    cout << "Сколько бюллетеней было собрано n? "; cin >> n;

    int votesPerCandidate[N] = { 0 };

    for (int i = 0; i < n; i++) {
        printf("За кого проголосовали? (1-%d)", N); cin >> cand;
        results[cand - 1][votesPerCandidate[cand - 1]] = 1;
        votesPerCandidate[cand - 1]++;
    }

    register int max = 0;
    int index = 0;

    for (int i = 0; i < N; i++) {
        register int k = 0;
        for (int j = 0; j < 100; j++) {
            if (results[i][j] == 1) {
                k++;
            }
        }
        cout << i + 1 << ") " << setw(10) << candidats[i] << " кол-во голосов: " << k << endl;
        if (k > max) {
            max = k;
            index = i;
        }
    }
    cout << "Максимальное кол-во голосов: " << max << endl << "Кандидат: " << candidats[index];

    return 0;
}