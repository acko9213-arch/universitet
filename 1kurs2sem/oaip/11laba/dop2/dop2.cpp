#include <iostream>
#include <deque>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    int n;
    cout << "Введите количество рыб: ";
    cin >> n;

    deque<int> river;

    cout << "Введите размеры рыб (положительные - вправо, отрицательные - влево): \n";
    for (int i = 0; i < n; i++) {
        int fish;
        cin >> fish;

        bool alive = true;
        while (alive && !river.empty() && river.back() > 0 && fish < 0) {
            if (river.back() < -fish) {
                river.pop_back();
            }
            else if (river.back() > -fish) {
                alive = false;
            }
            else {
                river.pop_back();
                alive = false;
            }
        }

        if (alive) river.push_back(fish);
    }

    cout << "Выжившие: ";
    if (river.empty()) cout << "все погибли";
    for (int f : river) cout << f << " ";

    return 0;
}