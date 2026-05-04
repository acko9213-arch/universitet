#include <iostream>
#include <string>
#include <windows.h>  
using namespace std;

struct Node
{
    string name;        
    Node* next;
};
int hashfunc(const string& key, int size)
{
    unsigned int hash = 0;
    for (char c : key)
        hash = hash * 31 + c;

    return hash % size;
}

void add(int size, Node** table)
{
    Node* p = new Node;

    cout << "Введите имя: ";
    string name;
    getline(cin, name);

    int h = hashfunc(name, size);


    Node* cur = table[h];
    while (cur)
    {
        if (cur->name == name)
        {
            cout << "Имя уже в списке\n";
            delete p;
            return;
        }
        cur = cur->next;
    }

    p->name = name;
    p->next = nullptr;


    p->next = table[h];
    table[h] = p;

}
Node* find(int size, Node** table, const string& name)
{
    int h = hashfunc(name, size);
    Node* cur = table[h];

    while (cur)
    {
        if (cur->name == name)
            return cur;
        cur = cur->next;
    }

    return nullptr;
}

void del(int size, Node** table, const string& name)
{
    int h = hashfunc(name, size);
    Node* cur = table[h];
    Node* prev = nullptr;

    while (cur)
    {
        if (cur->name == name)
        {
            if (prev == nullptr)
                table[h] = cur->next;
            else
                prev->next = cur->next;

            cout << "Имя удалено: " << name << "\n";
            delete cur;
            return;
        }

        prev = cur;
        cur = cur->next;
    }

    cout << "Имя не найдено\n";
}


void output(int size, Node** table)
{
    int total = 0;
    cout << "\nХЕШ-ТАБЛИЦА\n";
    for (int i = 0; i < size; i++)
    {
        Node* cur = table[i];

        if (cur)
        {
            cout << "[" << i << "] ";
            while (cur)
            {
                cout << cur->name;
                if (cur->next) cout << " -> ";
                cur = cur->next;
                total++;
            }
            cout << endl;
        }
    }

    if (total == 0)
        cout << "Таблица пуста\n";
    else
        cout << "Всего записей: " << total << "\n";

   
}

int main()
{
    SetConsoleCP(1251);      
    SetConsoleOutputCP(1251);
    setlocale(LC_CTYPE, "rus");
    
    int size = 100;
    Node** table = new Node * [size];

    for (int i = 0; i < size; i++)
        table[i] = nullptr;

    int choice;

    do
    {
        cout << "\nХЕШ-ТАБЛИЦА\n";
        cout << "1. Добавить имя\n";
        cout << "2. Найти имя\n";
        cout << "3. Удалить имя\n";
        cout << "4. Вывести таблицу\n";
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
            string name;
            cout << "Введите имя: ";
            getline(cin, name);

            
            Node* p = find(size, table, name);
            


            if (p)
                cout << "Имя найдено: " << p->name << endl;
            else
                cout << "Имя не найдено\n";

            break;
        }

        case 3:
        {
            string name;
            cout << "Введите имя: ";
            getline(cin, name);
            del(size, table, name);
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