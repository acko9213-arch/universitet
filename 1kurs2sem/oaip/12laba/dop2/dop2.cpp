#include <iostream>
#include <queue>
using namespace std;


void input(queue<char>& q) {
    char c;
    cout << "Вводите символы (0 - выход):\n";
    while (true) {
        cin >> c;
        if (c == '0') break;
        q.push(c);
    }
}


void removeFirst(queue<char>& q) {
    if (!q.empty())
        q.pop();
    else
        cout << "Очередь пуста — нечего удалять.\n";
}

void output(queue<char> q) {
    if (q.empty()) {
        cout << "(пусто)\n";
        return;
    }
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}


int getSize(queue<char>& q) {
    return q.size();
}


void findAndTrim(queue<char>& q, char target) {
  
    bool found = false;
    queue<char> temp = q;
    while (!temp.empty()) {
        if (temp.front() == target) { found = true; break; }
        temp.pop();
    }

    if (!found) {
        cout << "Символ '" << target << "' не найден в очереди.\n";
        return;
    }


    cout << "Удаляем элементы до '" << target << "':\n";
    while (!q.empty() && q.front() != target) {
        cout << "  Удалён: '" << q.front() << "'\n";
        q.pop();
    }
    cout << "Символ '" << target << "' найден и оставлен в начале очереди.\n";
}

int main() {
    setlocale(LC_ALL, "Russian");

    queue<char> q;


    input(q);

    cout << "\nОчередь после ввода: ";
    output(q);
    cout << "Размер: " << getSize(q) << endl;


    char target;
    cout << "\nВведите эталонный символ: ";
    cin >> target;

    findAndTrim(q, target);

    cout << "\nФинальная очередь: ";
    output(q);
    cout << "Размер: " << getSize(q) << endl;

    return 0;
}