#include <iostream>
#include <fstream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void pushFront(Node*& head, int value) {
    Node* newNode = new Node{ value, head };
    head = newNode;
}

void deleteNode(Node*& head, int value) {
    if (!head) return;
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* current = head;
    while (current->next && current->next->data != value) {
        current = current->next;
    }
    if (current->next) {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

bool contains(Node* head, int value) {
    Node* current = head;
    while (current) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void printList(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void sum(Node* p) {
    int sm = 0;
    if (p == NULL)
        cout << "Список пуст" << endl;
    else {
        while (p != NULL) {
            if (p->data > 0 && p->data % 5 == 0)
                sm = sm + p->data;
            p = p->next;
        }
        if (sm != 0)
            cout << "Сумма = " << sm << endl;
        else
            cout << "Кратных 5 положительных элементов нет" << endl;
    }
}

void toFile(Node*& p) {
    Node* temp = p;
    Node buf;
    ofstream frm("mList.dat");
    if (frm.fail()) {
        cout << "\nОшибка открытия файла";
        exit(1);
    }
    while (temp) {
        buf = *temp;
        frm.write((char*)&buf, sizeof(Node));
        temp = temp->next;
    }
    frm.close();
    cout << "Список записан в файл mList.dat\n";
}

void fromFile(Node*& p) {
    Node buf, * first = nullptr;
    ifstream frm("mList.dat");
    if (frm.fail()) {
        cout << "\nОшибка открытия файла";
        exit(1);
    }
    frm.read((char*)&buf, sizeof(Node));
    while (!frm.eof()) {
        pushFront(first, buf.data);
        cout << "-->" << buf.data;
        frm.read((char*)&buf, sizeof(Node));
    }
    cout << "-->NULL" << endl;
    frm.close();
    p = first;
    cout << "\nСписок считан из файла mList.dat\n";
}

int main() {
    setlocale(LC_CTYPE, "Russian");
    Node* first = nullptr;
    int choice, value;
    cout << "МЕНЮ:\n"
        << " 1 - добавление элемента\n"
        << " 2 - удаление элемента\n"
        << " 3 - поиск элемента\n"
        << " 4 - вывод списка в консольное окно\n"
        << " 5 - запись списка в файл\n"
        << " 6 - считывание списка из файла\n"
        << " 7 - вывод суммы кратных 5 положительных чисел списка\n"
        << " 8 - выход" << endl;
    while (true) {
        cout << "Выбор: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cin >> value;
            pushFront(first, value);
            break;
        case 2:
            cin >> value;
            deleteNode(first, value);
            break;
        case 3:
            cin >> value;
            if (contains(first, value))
                cout << "Элемент найден" << endl;
            else
                cout << "Элемент не найден" << endl;
            break;
        case 4:
            printList(first);
            break;
        case 5:
            toFile(first);
            break;
        case 6:
            fromFile(first);
            break;
        case 7:
            sum(first);
            break;
        case 8:
            return 0;
        default:
            cout << "Неправильный выбор" << endl;
            break;
        }
    }
    return 0;
}