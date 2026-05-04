#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct Node
{
    int place;
    string owner;
    Node* next;
};

int hashfunc(int key, int size)
{
    return key % size;
}

void add(int size, Node** table)
{
    Node* p = new Node;

    cout << "Введите владельца места: ";
    string name;
    getline(cin, name);

    cout << "Введите номер места (1-100): ";
    int num;
    cin >> num;
    cin.ignore();

    if (num < 1 || num>100)
    {
        cout << "Некорректный номер места\n";
        delete p;
        return;
    }

    if (table[hashfunc(num, size)] != nullptr)
    {
        Node* t = table[hashfunc(num, size)];
        while (t)
        {
            if (t->place == num)
            {
                cout << "Место уже занято\n";
                delete p;
                return;
            }
            t = t->next;
        }
    }

    p->place = num;
    p->owner = name;
    p->next = nullptr;

    int h = hashfunc(num, size);

    if (table[h] == nullptr)
        table[h] = p;
    else
    {
        Node* cur = table[h];
        while (cur->next)
            cur = cur->next;
        cur->next = p;
    }

    cout << "Место добавлено\n";
}

Node* find(int size, Node** table, int num)
{
    int h = hashfunc(num, size);

    Node* cur = table[h];

    while (cur)
    {
        if (cur->place == num)
            return cur;

        cur = cur->next;
    }

    return nullptr;
}

void del(int size, Node** table, int num)
{
    int h = hashfunc(num, size);

    Node* cur = table[h];
    Node* prev = nullptr;

    while (cur)
    {
        if (cur->place == num)
        {
            if (prev == nullptr)
                table[h] = cur->next;
            else
                prev->next = cur->next;

            delete cur;

            cout << "Место освобождено\n";
            return;
        }

        prev = cur;
        cur = cur->next;
    }

    cout << "Место не найдено\n";
}

void output(int size, Node** table)
{
    for (int i = 0; i < size; i++)
    {
        cout << "[" << i << "] ";

        Node* cur = table[i];

        if (cur == nullptr)
            cout << "свободно";

        while (cur)
        {
            cout << "Место " << cur->place
                << ", " << cur->owner;

            if (cur->next)
                cout << " | ";

            cur = cur->next;
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

    int choice;

    do
    {
        cout << "\nПАРКИНГ\n";
        cout << "1. Добавить парковочное место\n";
        cout << "2. Найти место\n";
        cout << "3. Освободить место\n";
        cout << "4. Вывести парковку\n";
        cout << "0. Выход\n";
        cout << "Выбор: ";

        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            add(size, table);
            break;

        case 2:
        {
            int num;
            cout << "Введите номер места: ";
            cin >> num;
            cin.ignore();

            clock_t s = clock();

            Node* p = find(size, table, num);

            clock_t e = clock();

            

            if (p)
                cout << "Владелец: "
                << p->owner
                << ", место "
                << p->place << endl;
            else
                cout << "Место не найдено\n";

            break;
        }

        case 3:
        {
            int num;

            cout << "Введите номер места: ";
            cin >> num;
            cin.ignore();

            del(size, table, num);

            break;
        }

        case 4:
            output(size, table);
            break;

        case 0:
            cout << "Выход\n";
            break;

        default:
            cout << "Неверный выбор\n";
        }

    } while (choice != 0);

    return 0;
}