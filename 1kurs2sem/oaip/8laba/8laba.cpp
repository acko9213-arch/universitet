#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <fstream>
using namespace std;
struct Item
{
	int number;
	Item *next;
};
void input(Item*& head,int value)
{
	Item* p = new Item;
	p->number = value;   
	p->next = head;       
	head = p;
	cout << "Элемент записан." << endl;
}
void output(Item* head)
{
	Item* current = head;
	while (current)
	{
		cout << current->number << " ";
		current = current->next;
	}
	cout << endl << "Список выведен." << endl;
}
bool find(Item* head,int value)
{
	Item* current = head;
	while (current)
	{
		if (current->number == value)
		{
			return true;
		}
		current = current->next;
	}
	return false;
}
void delet(Item* head,int value)
{
	int i = 0;
	Item* current = head;
	if (head == nullptr) {
		cout << "Список пуст!" << endl;
		return;
	}

	if (value == 1) {
		Item* temp = head;
		head = head->next;
		delete temp;
		cout << "Первый элемент удалён." << endl;
		return;
	}
	while (current)
	{
		i++;
		if (i == value-1)
		{
			break;
		}
		current = current->next;
		
	}
	Item* p = current->next;
	current->next = p->next;
	delete p;

	cout << "Элемент удалён." << endl;
}
void toFile(Item*& p)
{
	Item* temp = p;
	ofstream frm("mList.dat");
	if (frm.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	while (temp)
	{
		frm.write((char*)&temp->number, sizeof(int));
		temp = temp->next;
	}
	frm.close();
	cout << "Список записан в файл mList.dat\n";
}

void fromFile(Item*& p)
{
	int buf;
	Item* first = nullptr;
	ifstream frm("mList.dat");
	if (frm.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	while (frm.read((char*)&buf, sizeof(int)))
	{
		cout << "-->" << buf;
		input(first, buf);
	}
	cout << "-->NULL" << endl;
	frm.close();
	p = first;
	cout << "\nСписок считан из файла mList.dat\n";
}
int sum(Item*& head)
{
	int sum=0;
	Item* current = head;
	while (current)
	{
		if ((current->number) % 10 == 7 && (current->number)>0)
		{
			sum += current->number;
		}
		current = current->next;
	}
	return sum;
}
int main()
{
	setlocale(LC_CTYPE, "rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	Item* head = nullptr;
	while (true)
	{
		cout << setw(20) << "МЕНЮ" <<endl;
		cout << "1)Добавить элемент в начало списка." << endl;
		cout << "2)Удалить элемент списка." << endl;
		cout << "3)Поиск элемента." << endl;
		cout << "4)Запись в файл." << endl;
		cout << "5)Вывод из файла." << endl;
		cout << "6)Вывод списка в консоль." << endl;
		cout << "7)Сумма положительных элементов кончающихся на 7." << endl;
		cout << "8)Выход." << endl;
		int choice;
		
		cout << "Выбор: ";
		cin >> choice;
		switch (choice)
		{
		case 1: {
			int value;
			cout << "Введите элемент: ";
			if (!(cin >> value))
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Не целое число.Выход в меню." << endl; break;
			}
			input(head, value); break;
		}
		case 2: {
			int value;

			cout << "Введите индекс нужного элемента: ";
			if (!(cin >> value))
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Не целое число.Выход в меню." << endl; break;
			}
			delet(head, value); break;
		}
		case 3: {
			int value;
			
			cout << "Введите значение нужного элемента: ";
			if (!(cin >> value))
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Не целое число.Выход в меню." << endl; break;
			}
			if (find(head, value))
			{
				cout << "Элемент найден" << endl; break;
			}
			else
			{
				cout << "Элемент не найден" << endl; break;
			}
			break;
		}
		case 4: toFile(head); break;
		case 5: fromFile(head); break;
		case 6:output(head); break;
		case 7: {
			if (sum(head)>0)
			{
				cout << "Сумма: " << sum(head) << endl;
			}
			else
				cout << "Таких элементов нету"<<endl;
		}
		case 8:cout << "Досвидания."; return 0; break;
		default:
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Нету такого варианта.Попробуйте ещё." << endl; break;
		}
		}
	}

	return 0;
}

