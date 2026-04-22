#include <iostream>
#include <deque>
#include <string>
using namespace std;
struct Element {
    int val, prio, id;
};
int global_id = 0;
void check_overflow(deque<Element>& dq, int limit) {
    if (dq.size() < limit) return;
    int min_pos = 0;
    for (int i = 1; i < dq.size(); i++) {
        if (dq[i].prio < dq[min_pos].prio || (dq[i].prio == dq[min_pos].prio && dq[i].id < dq[min_pos].id)) {
            min_pos = i;
        }
    }
    cout << "Внимание: Дек полон. Удален элемент с мин. приоритетом: " << dq[min_pos].val << endl;
    dq.erase(dq.begin() + min_pos);
}
int main() {
    setlocale(LC_ALL, "Russian");
    int limit, ops;
    cout << "Введите лимит размера дека: ";
    cin >> limit;
    cout << "Введите количество операций: ";
    cin >> ops;
    deque<Element> dq;
    cout << "\nКоманды: push_front V P, push_back V P, pop_front, pop_back, print\n";
    for (int i = 0; i < ops; i++) {
        string cmd;
        cout << "\nОперация " << i + 1 << "/" << ops << ": ";
        cin >> cmd;
        if (cmd == "push_front" || cmd == "push_back") {
            int v, p;
            cin >> v >> p;
            check_overflow(dq, limit);
            if (cmd == "push_front") dq.push_front({ v, p, global_id++ });
            else dq.push_back({ v, p, global_id++ });
            cout << "Элемент " << v << " добавлен.\n";
        }
        else if (cmd == "pop_front") {
            if (!dq.empty()) {
                cout << "Удалено из начала: " << dq.front().val << endl;
                dq.pop_front();
            }
            else cout << "Ошибка: Дек пуст!\n";
        }
        else if (cmd == "pop_back") {
            if (!dq.empty()) {
                cout << "Удалено из конца: " << dq.back().val << endl;
                dq.pop_back();
            }
            else cout << "Ошибка: Дек пуст!\n";
        }
        else if (cmd == "print") {
            if (dq.empty()) {
                cout << "Дек пуст.\n";
            }
            else {
                cout << "Содержимое дека: ";
                for (const auto& e : dq) {
                    cout << "[" << e.val << " (пр:" << e.prio << ")] ";
                }
                cout << endl;
            }
        }
        else {
            cout << "Неизвестная команда. Попробуйте еще раз.\n";
            i--;
        }
    }
    return 0;
}