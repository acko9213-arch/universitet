#include "Header.h"
#include <iostream>
#include <fstream>
using namespace std;
void input(Steak*& head, int x)
{
	Steak* p = new Steak;
	p->data = x;
	p->next = head;
	head = p;
}
void clear(Steak*& head)
{


	while (head)
	{
		Steak* p = head;

		head = head->next;
		delete p;
	}
}
void output(Steak*& head)
{
	while (head)
	{
		int tmp = head->data;
		Steak* pv = head;
		head = head->next;
		delete pv;
		std::cout << tmp << std::endl;
	}

}
void countRepeating(Steak* head)
{
	if (!head)
	{
		cout << "Стек пуст" << endl;
		return;
	}

	int values[200];
	int counts[200];
	int size = 0;

	Steak* p = head;
	while (p)
	{
		bool found = false;
		for (int i = 0; i < size; i++)
		{
			if (values[i] == p->data)
			{
				counts[i]++;
				found = true;
				break;
			}
		}
		if (!found)
		{
			values[size] = p->data;
			counts[size] = 1;
			size++;
		}
		p = p->next;
	}

	
	int totalRepeating = 0;
	cout << "Повторяющиеся элементы:" << endl;
	for (int i = 0; i < size; i++)
	{
		if (counts[i] > 1)
		{
			cout << "Элемент " << values[i]
				<< " повторяется " << counts[i] << " раз" << endl;
			totalRepeating++;
		}
	}

	if (totalRepeating == 0)
		cout << "Повторяющихся элементов нет" << endl;
	else
		cout << "Итого повторяющихся элементов: " << totalRepeating << endl;
}
void saveToFile(Steak* head)
{
	ofstream file("stack.txt");
	if (!file)
	{
		cout << "Ошибка открытия файла!" << endl;
		return;
	}

	Steak* p = head;
	while (p)
	{
		file << p->data << "\n";
		p = p->next;
	}

	file.close();
	cout << "Стек сохранён в файл stack.txt" << endl;
}
void loadFromFile(Steak*& head)
{
	ifstream file("stack.txt");
	if (!file)
	{
		cout << "Ошибка открытия файла!" << endl;
		return;
	}

	clear(head);

	int arr[200];
	int count = 0;
	while (file >> arr[count])
	{
		count++;
	}
	file.close();


	for (int i = count - 1; i >= 0; i--)
	{
		input(head, arr[i]);
	}

	cout << "Стек загружен из файла stack.txt" << endl;
}