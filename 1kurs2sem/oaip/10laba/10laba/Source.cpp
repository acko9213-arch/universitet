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
void del(Steak*& head)
{
	int arr[200];
	Steak* p = head;
	int i=0;
	while (p)
	{
		
		arr[i] = p->data;
			i++;
		p = p->next;
		for (int j = 0; j < i; j++)
		{
			if (p == nullptr)
			{
				std::cout << "Нет повторяющихся элементов" << std::endl; break;
			}
			if (arr[j] == p->data)
			{
				p = head;
				for (int j = 0; j < i-1; j++)
				{
					p = p -> next;
				}
				Steak* z = p->next;
				p->next = z->next;
				delete z;
				return;
			}
		}
	}
	
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