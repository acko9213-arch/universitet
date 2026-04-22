#include <iostream>
#include <string>
#include <ctime>
using namespace std;
struct Node {
    int phone;
    string name;
    Node* next;
};
int hashfunc(int phone, int size) {
    return phone % size;
}
void add(int size,Node **table)
{
    Node* p = new Node;
    int ph; string na;
    cout << "Введите ФИО:"; getline(cin,na);
    cout << "Введите номер телефона:"; cin >> ph; cin.ignore();
    if (ph < 0 || ph > 32767)
    {
        cout << "Неверный номер телефона.";
        exit(1);
    }
    p->next = nullptr;
    p->name = na;
    p->phone = ph;
    int d = hashfunc(ph, size);
    if (table[d]==nullptr) {
        table[d] = p;
    }
    else
    {
        Node* g = table[d];
        while (g->next)
        {
            g = g->next;
        }
        g->next = p;
    }
}
Node* find(int size, Node** table,int ph)
{
    clock_t start = clock();
    int d = hashfunc(ph, size);
        Node* current = table[d];
        while (current != nullptr) {
            if (current->phone == ph) {
                return current;
            }
            current = current->next;
        }
        return nullptr; 
    
}
void del(int size, Node** table, int ph)
{
    int d = hashfunc(ph, size);
    Node* current = table[d];
    Node* prev = nullptr;
    if (current == nullptr) {
        cout << "Нечего удалять\n";
        return;
    }
    while (current != nullptr)
    {
        if (current->phone == ph)
        {
            if (prev == nullptr)
                table[d] = current->next;
            else
                prev->next = current->next;
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
    cout << "Элемент не найден\n";
}
void output(int size, Node** table)
{
    for (int i = 0; i < size; i++) {
    cout << "[" << i << "]: ";
    Node* current = table[i];
      if (current == nullptr) {
      cout << "nullptr";}
      while (current != nullptr) {
      cout  << current->name << ", " << current->phone;
      if (current->next != nullptr) cout << " | ";
       current = current->next;
        }
         cout << endl;
       }
}
int main()
{
    setlocale(LC_CTYPE, "rus");
    int size1 = 16, size2 = 32;
    Node** table1 = new Node * [size1];
    Node** table2 = new Node * [size2];
    for (int i = 0; i < size1; i++) {
        table1[i] = nullptr;
    }
    for (int i = 0; i < size2; i++) {
        table2[i] = nullptr;
    }
    int choice;
    do {
        cout << "Меню\n";
        cout << "1. Добавить элемент в 1таблицу\n";
        cout << "2. Найти элемент во 1 таблице\n";
        cout << "3. Удалить элемент 1 таблицы\n";
        cout << "4. Вывести 1 таблицу \n";
        cout << "5. Добавить элемент в 2 таблицу\n";
        cout << "6. Найти элемент во 2 таблице\n";
        cout << "7. Удалить элемент во второй таблице\n";
        cout << "8. Вывести 2 таблицу \n";
        cout << "0. Выход\n";
        cout << "Выберите действие: "; cin >> choice;
        cin.ignore();
        switch (choice) {
        case 1:
            add(size1, table1);
            break;
        case 2: {
            int ph;
            cout << "Введите номер телефона для поиска: "; cin >> ph; cin.ignore();
            clock_t start = clock();
            Node* result = find(size1, table1, ph);
            clock_t end = clock();
            double sec = (double)(end - start) / CLOCKS_PER_SEC;
            cout << sec << "секунд.\n";
            if (result != nullptr)
                cout << "Найдено: " << result->name << ", " << result->phone << "\n";
            else
                cout << "Элемент не найден\n";
            break;
        }
        case 3: {
            int ph;
            cout << "Введите номер телефона для удаления: "; cin >> ph; cin.ignore();
            del(size1, table1, ph);
            break;
        }
        case 4:
            output(size1, table1);
            break;
        case 5:
            add(size2, table2);
            break;
        case 6: {
            int ph;
            cout << "Введите номер телефона для поиска: "; cin >> ph; cin.ignore();
            clock_t start1 = clock();
            Node* result = find(size2, table2, ph);
            clock_t end1 = clock();
            double sec = (double)(end1 - start1) / CLOCKS_PER_SEC;
            cout << sec << "секунд.\n";
            if (result != nullptr)
                cout << "Найдено: " << result->name << ", " << result->phone << "\n";
            else
                cout << "Элемент не найден\n";
            break;
        }
        case 7: {
            int ph;
            cout << "Введите номер телефона для удаления: "; cin >> ph; cin.ignore();
            del(size2, table2, ph);
            break;
        }
        case 8:
            output(size2, table2);
            break;
        case 0:
            cout << "Выход\n";
            break;
        default:
            cout << "Неверный выбор\n";
            break;
        }

    } while (choice != 0);
    return 0;
}