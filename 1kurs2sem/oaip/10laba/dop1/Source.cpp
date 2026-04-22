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
void formStack(Steak* head1, Steak* head2, Steak*& result)
{
    clear(result);
    Steak* p1 = head1;
    while (p1)
    {
        Steak* p2 = head2;
        while (p2)
        {
            if (p1->data == p2->data)
            {
                
                bool already = false;
                Steak* r = result;
                while (r)
                {
                    if (r->data == p1->data) { already = true; break; }
                    r = r->next;
                }
                if (!already)
                    input(result, p1->data);
                break;
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }

    if (!result)
        cout << "Повторяющихся элементов не найдено" << endl;
}