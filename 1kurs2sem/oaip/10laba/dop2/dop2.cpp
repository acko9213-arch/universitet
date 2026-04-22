#include <iostream>
#include <fstream>
#include <Windows.h>
#include "Header.h"
using namespace std;


int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	Steak* head = nullptr;
	setlocale(LC_CTYPE, "Rus");
	while (true)
	{
		int choice;
		cout << endl;
		cout << "1. Ввод элемента в стек" << endl;
		cout << "2. Очистка стека" << endl;

		cout << "3. Сохранение в файл" << endl;
		cout << "4. Вывод из файла" << endl;
		cout << "5. Подсчёт повторяющихся элементов стека" << endl;
		cout << "6. Выход" << endl;
		cout << "7. Вывод всего стека." << endl;
		cout << "Выбор: ";
		


		cin >> choice;
		switch (choice)
		{
		case 1: { int choice1; cin >> choice1;  input(head, choice1); break; }
		case 2: {
			clear(head);	break;
		}
			  break;
		case 3: { saveToFile(head);   break; }
		case 4: { loadFromFile(head); break; }
		case 5: { countRepeating(head); break; }
		case 6:  exit(0);
		case 7:  output(head); break;

		default:cout << "Нет такого варианта.Попробуйте ещё раз."; cin.clear(); cin.ignore(10000, '\n');
		}
	}
	return 0;
}