#include <iostream>
#include <Windows.h>
#include <iomanip>

using namespace std;
struct Item
{
	int number;
	Item* next;
};
void input(Item*& head, int value)
{
	Item* p = new Item;
	p->number = value;
	p->next = head;
	head = p;
	cout << "Элемент записан." << endl;
}
void find(Item* head, int value)
{
	Item* current = head;
	while (current)
	{
		if (current->number == value)
		{
			Item* p = new Item;
			p->number = 8;
			p->next = current->next;
			current->next = p;
			break;
		}
		current = current->next;
	}
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
int main()
{
	setlocale(LC_CTYPE, "rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	Item* head = nullptr;
	input(head, 1);
	input(head, 2);
	input(head, 7);
	input(head, 4);
	input(head, 15);
	input(head, 9);
	find(head, 7);
	output(head);
	return 0;
}