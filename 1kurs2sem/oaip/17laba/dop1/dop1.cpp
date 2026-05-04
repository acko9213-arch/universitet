#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string city;
    int population;
    Node* next;
};

int hashfunc(int key, int size)
{
    return key % size;
}

void add(int size, Node** table)
{
    Node* p = new Node;

    cout << "Название города: ";
    getline(cin, p->city);

    cout << "Население: ";
    cin >> p->population;
    cin.ignore();

    p->next = nullptr;

    int h = hashfunc(p->population, size);

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

Node* find(int size, Node** table, int pop)
{
    int h = hashfunc(pop, size);

    Node* t = table[h];

    while (t)
    {
        if (t->population == pop)
            return t;

        t = t->next;
    }

    return nullptr;
}

void del(int size, Node** table, int pop)
{
    int h = hashfunc(pop, size);

    Node* cur = table[h];
    Node* prev = nullptr;

    while (cur)
    {
        if (cur->population == pop)
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
            cout << t->city
                << " (" << t->population << ")";

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
        cin.ignore();

        if (c == 1) add(size, table);

        if (c == 2)
        {
            int x;
            cout << "Население: ";
            cin >> x;
            cin.ignore();

            Node* p = find(size, table, x);

            if (p)
                cout << p->city << endl;
            else
                cout << "Нет\n";
        }

        if (c == 3)
        {
            int x;
            cout << "Население: ";
            cin >> x;
            cin.ignore();

            del(size, table, x);
        }

        if (c == 4)
            output(size, table);

    } while (c != 0);
}