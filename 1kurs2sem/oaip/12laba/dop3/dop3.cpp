#include <iostream>
#include <queue>
#include <cctype>
using namespace std;

void input(queue<char>& q1, queue<char>& q2) {
    char c;
    cout << "Введите символы (0 - выход):\n";
    while (cin >> c && c != '0') {
        if (isupper((unsigned char)c))
            q1.push(tolower((unsigned char)c));
        else if (islower((unsigned char)c))
            q2.push(toupper((unsigned char)c));
    }
}

void output(queue<char> q) {
    if (q.empty()) {
        cout << "(пусто)" << endl;
        return;
    }
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

void removeFirst(queue<char>& q) {
    if (!q.empty())
        q.pop();
    else
        cout << "Очередь пуста.\n";
}

int main() {
    setlocale(LC_ALL, "");
    queue<char> q1, q2;

    input(q1, q2);

    cout << "Очередь 1 (заглавные -> строчные): ";
    output(q1);
    cout << "Очередь 2 (строчные -> заглавные): ";
    output(q2);

    removeFirst(q1);
    removeFirst(q2);

    cout << "После удаления первых элементов:\n";
    cout << "Очередь 1: ";
    output(q1);
    cout << "Очередь 2: ";
    output(q2);

    return 0;
}