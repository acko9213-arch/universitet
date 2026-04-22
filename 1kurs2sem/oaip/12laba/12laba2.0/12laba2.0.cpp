#include <iostream>
#include <queue>
using namespace std;
struct Node {
	char data;
	Node* next;
};
void del(Node*& head);

void input(Node*& head, Node*& tail, char x,char et)
{
	Node* p = new Node;
	if (x == et)
	{
		del(head);
		del(head);
		return;
	}
	if (head == NULL)
	{
		p->data = x;
		head = p;
		tail = p;
	}
	else
	{
		p->data = x;
		p->next = nullptr;
		tail->next = p;
		tail = p;
	}
}
void output(Node*& t)
{
	if (t != NULL)
	{
		cout << t->data << endl;
		t = t->next;
	}
}
void del(Node*& head)
{
	if (head->next == nullptr)
	{
		head = nullptr; return;
}
	if (head != NULL)
	{
		head = head->next;
	}
}
int size(Node* head)
{
	int x=0;
	Node* p = head;
	while (p)
	{
		x++;
		p = p->next;
	}
	return x;
}
int main()
{
	Node* head = nullptr;
	Node* tail = nullptr;
	setlocale(LC_CTYPE, "Rus");
	char etalon;
	cout << "Введите эталонный символ: ";
	cin >> etalon;
	while (true)
	{
		int choice;
		cout << endl;
		cout << "1. Ввод элемента в очередь" << endl;
		cout << "2. Вывод элемента очереди" << endl;

		cout << "3. Удаление элемента очереди" << endl;
		cout << "4. Размер очереди" << endl;

		cout << "5. Выход" << endl;
		cout << "Выбор: ";



		cin >> choice;
		switch (choice)
		{
		case 1: { char choice1; cin >> choice1;  input(head, tail,choice1, etalon); break; }
		case 2: {
			output(head);	break;
		}
			  break;
		case 3: { del(head);   break; }
		case 4: { cout << size(head) << endl; break; }
		case 5: {
			exit(1);
		}

		default:cout << "Нет такого варианта.Попробуйте ещё раз."; cin.clear(); cin.ignore(10000, '\n');
		}
	}

	return 0;
}
