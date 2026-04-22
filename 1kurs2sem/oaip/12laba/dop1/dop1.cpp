#include <iostream>
#include <queue>
using namespace std;

void input(queue<char>& q, int n) {
    char c;
    for (int i = 0; i < n; i++) {
        cin >> c;
        q.push(c);
    }
}

void output(queue<char> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

void removeUntil(queue<char>& q, char etalon) {
    queue<char> temp = q;
    bool found = false;
    while (!temp.empty()) {
        if (temp.front() == etalon) {
            found = true;
            break;
        }
        temp.pop();
    }
    if (!found) {
        cout << "Эталон не найден\n";
        return;
    }
    while (!q.empty() && q.front() != etalon) {
        q.pop();
    }
}

int main() {
    setlocale(LC_ALL, "");
    queue<char> q;
    int n;
    cout << "Сколько символов: ";
    cin >> n;
    cout << "Введите символы:\n";
    input(q, n);
    cout << "Очередь: ";
    output(q);
    char etalon;
    cout << "Введите эталонный символ: ";
    cin >> etalon;
    removeUntil(q, etalon);
    cout << "После обработки: ";
    output(q);
    return 0;
}