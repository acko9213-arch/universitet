#include <iostream>
#include <fstream>
#include <Windows.h>
#include "Header.h"
using namespace std;
int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_CTYPE, "Rus");

    Steak* head1 = nullptr;  
    Steak* head2 = nullptr;  
    Steak* result = nullptr; 

    while (true)
    {
        int choice;
        cout << endl;
        cout << "1. Ввод элемента в Stack1" << endl;
        cout << "2. Ввод элемента в Stack2" << endl;
        cout << "3. Сформировать Stack из повторяющихся" << endl;
        cout << "4. Вывод Stack1" << endl;
        cout << "5. Вывод Stack2" << endl;
        cout << "6. Вывод Stack (результат)" << endl;
        cout << "7. Очистка всех стеков" << endl;
        cout << "8. Сохранение в файл" << endl;
        cout << "9. Загрузка из файла" << endl;
        cout << "10. Выход" << endl;
        cout << "Выбор: ";

        cin >> choice;
        switch (choice)
        {
        case 1: { int val; cin >> val; input(head1, val); break; }
        case 2: { int val; cin >> val; input(head2, val); break; }
        case 3: { formStack(head1, head2, result); break; }
        case 4: { output(head1); break; }
        case 5: { output(head2); break; }
        case 6: { output(result); break; }
        case 7: { clear(head1); clear(head2); clear(result); break; }
        case 8: { saveToFile(result); break; }
        case 9: { loadFromFile(result); break; }
        case 10: exit(0);
        default: cout << "Нет такого варианта. Попробуйте ещё раз.";
            cin.clear(); cin.ignore(10000, '\n');
        }
    }
    return 0;
}