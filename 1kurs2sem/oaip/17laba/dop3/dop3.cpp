#include <iostream>
using namespace std;

struct Node
{
    int group;
    int students;
    Node* next;
};

int hashfunc(int key, int size)
{
    return key % size;
}

void add(int size, Node** table)
{
    Node* p = new Node;

    cout << "Номер группы: ";
    cin >> p->group;

    cout << "Количество студентов: ";
    cin >> p->students;

    cin.ignore();

    p->next = nullptr;

    int h = hashfunc(p->group, size);

    if (table[h] == nullptr)
        table[h] = p;
    else
    {
        Node* t = table[h];
        while (t->next)
            t = t->next;
        t->next = p;
    }
}

Node* find(int size, Node** table, int g)
{
    int h = hashfunc(g, size);

    Node* t = table[h];

    while (t)
    {
        if (t->group == g)
            return t;

        t = t->next;
    }

    return nullptr;
}

void del(int size, Node** table, int g)
{
    int h = hashfunc(g, size);

    Node* cur = table[h];
    Node* prev = nullptr;

    while (cur)
    {
        if (cur->group == g)
        {
            if (prev == nullptr)
                table[h] = cur->next;
            else
                prev->next = cur->next;

            delete cur;
            return;
        }

        prev = cur;
        cur = cur->next;
    }
}

void output(int size, Node** table)
{
    for (int i = 0; i < size; i++)
    {
        cout << "[" << i << "] ";

        Node* t = table[i];

        if (!t)
            cout << "nullptr";

        while (t)
        {
            cout << "Группа "
                << t->group
                << ", студентов "
                << t->students;

            if (t->next)
                cout << " | ";

            t = t->next;
        }

        cout << endl;
    }
}

int main()
{
    setlocale(LC_CTYPE, "rus");
    int size = 100;
    Node** table = new Node * [size];

    for (int i = 0; i < size; i++)
        table[i] = nullptr;

    int c;

    do {
        cout << "\n1 Добавить\n2 Найти\n3 Удалить\n4 Вывести\n0 Выход\n";
        cin >> c;

        if (c == 1)
            add(size, table);

        if (c == 2)
        {
            int x;
            cout << "Группа: ";
            cin >> x;

            Node* p = find(size, table, x);

            if (p)
                cout << "Студентов " << p->students << endl;
            else
                cout << "Нет\n";
        }

        if (c == 3)
        {
            int x;
            cout << "Группа: ";
            cin >> x;
            del(size, table, x);
        }

        if (c == 4)
            output(size, table);

    } while (c != 0);
}