#include <iostream>
using namespace std;

struct Node {
    char data;          
    int priority;        
    Node* next;
};
Node* head = nullptr;
Node* tail = nullptr;
void input() {
    Node* p = new Node;
    char b;
    int a;

    cout << "Введите символ: ";
    cin >> b;
    cout << "Введите приоритет (0 - наивысший, 10 - низший): ";
    cin >> a;

    p->data = b;
    p->priority = a;
    p->next = nullptr;
    if (head == nullptr) {
        head = tail = p;
        cout << "Элемент добавлен" << endl;
        return;
    }

    
   
    if (p->priority < head->priority) {
        p->next = head;
        head = p;
        cout << "Элемент добавлен" << endl;
        return;
    }

   
    Node* current = head;
    while (current->next != nullptr && current->next->priority <= p->priority) {
        current = current->next;
    }

    p->next = current->next;
    current->next = p;

    if (p->next == nullptr) {
        tail = p;
    }

    cout << "Элемент добавлен" << endl;
}

void del() {
    if (head == nullptr) {
        cout << "Очередь пуста, удалять нечего!" << endl;
        return;
    }

    Node* temp = head;
    cout << "Удалён элемент: " << head->data
        << " (приоритет: " << head->priority << ")" << endl;
    head = head->next;

    if (head == nullptr) {
        tail = nullptr;
    }

    delete temp;
}


void outputAll() {
    if (head == nullptr) {
        cout << "Очередь пуста!" << endl;
        return;
    }

    cout << "Очередь (приоритет): " << endl;
    Node* current = head;
    int pos = 1;
    while (current != nullptr) {
        cout << pos++ << ". '" << current->data
            << "' (приоритет: " << current->priority << ")" << endl;
        current = current->next;
    }
}

void clear() {
    while (head != nullptr) {
        del();
    }
    cout << "Очередь очищена" << endl;
}

int main() {
    setlocale(LC_ALL, "Rus");

    while (true) {
       
      
        cout << "1. Добавить элемент с приоритетом" << endl;
        cout << "2. Удалить первый элемент" << endl;
        cout << "3. Вывести всю очередь" << endl;
        cout << "4. Очистить очередь" << endl;
        cout << "5. Выход" << endl;
        cout << "Выбор: ";

        int choice;
        cin >> choice;

        switch (choice) {
      
        case 1:
            input();
            break;
    
        case 2:
            del();
            break;
        case 3:
            outputAll();
            break;

        case 4:
            clear();
            break;
        case 5:
            cout << "Конец" << endl;
            clear();
            return 0;
        default:
            cout << "Нет такого варианта. Попробуйте ещё раз." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    return 0;
}