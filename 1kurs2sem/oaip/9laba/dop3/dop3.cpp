#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;
const unsigned int NAME_SIZE = 30;
const unsigned int CITY_SIZE = 20;

struct Address
{
	char name[NAME_SIZE];
	char city[CITY_SIZE];
	Address* next;
	Address* prev;
};
struct Address1
{
	char name[NAME_SIZE];
	char city[CITY_SIZE];
	Address1* next;


};
//-----------------------------------------------------------
int menu(void)
{

	char s[80];  int c;
	cout << endl;
	cout << "1. Ввод имени" << endl;
	cout << "2. Удаление имени" << endl;
	cout << "3. Вывод на экран" << endl;
	cout << "4. Поиск" << endl;
	cout << "6. Ввод элементов в л список" << endl;
	cout << "7. Сложение двух списков." << endl;
	cout << "5. Выход" << endl; 
	cout << "8. Удаление по вашему значению." << endl;
	cout << "9. Замена i-го элемента." << endl;
	cout << "10. Добавления x в начало списка." << endl;
	cout << endl;
	do
	{
		cout << "Ваш выбор: ";
		cin.sync();
		gets_s(s);
		cout << endl;
		c = atoi(s);
	} while (c < 0 || c > 10);
	return c;
}
//-----------------------------------------------------------
void insert(Address* e, Address** phead, Address** plast)
{
	Address* p = *plast;
	if (*plast == NULL)
	{
		e->next = NULL;
		e->prev = NULL;
		*plast = e;
		*phead = e;
		return;
	}
	else
	{
		p->next = e;
		e->next = NULL;
		e->prev = p;
		*plast = e;
	}
}
//-----------------------------------------------------------
Address* setElement()
{
	Address* temp = new  Address();
	if (!temp)
	{
		cerr << "Ошибка выделения памяти памяти";
		return NULL;
	}
	cout << "Введите имя: ";
	cin.getline(temp->name, NAME_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	cout << "Введите город: ";
	cin.getline(temp->city, CITY_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}
//-----------------------------------------------------------
void outputList(Address** phead, Address** plast)
{
	Address* t = *phead;
	while (t)
	{
		cout << t->name << ' ' << t->city << endl;
		t = t->next;
	}
	cout << "" << endl;
}
//-----------------------------------------------------------
void find(char name[NAME_SIZE], Address** phead)
{
	Address* t = *phead;
	while (t)
	{
		if (!strcmp(name, t->name)) break;
		t = t->next;
	}
	if (!t)
		cerr << "Имя не найдено" << endl;
	else
		cout << t->name << ' ' << t->city << endl;
}
//-----------------------------------------------------------
void delet(char name[NAME_SIZE], Address** phead, Address** plast)
{
	struct Address* t = *phead;
	while (t)
	{
		if (!strcmp(name, t->name))  break;
		t = t->next;
	}
	if (!t)
		cerr << "Имя не найдено" << endl;
	else
	{
		if (*phead == t)
		{
			*phead = t->next;
			if (*phead)
				(*phead)->prev = NULL;
			else
				*plast = NULL;
		}
		else
		{
			t->prev->next = t->next;
			if (t != *plast)
				t->next->prev = t->prev;
			else
				*plast = t->prev;
		}
		delete t;
		cout << "Элемент удален" << endl;
	}
}
void setElementforL(Address1*& head)
{
	Address1* temp = new Address1();


	cout << "Введите имя: ";
	cin.getline(temp->name, NAME_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	cout << "Введите город: ";
	cin.getline(temp->city, CITY_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();


	temp->next = head;
	head = temp;
}
void addLEnd(Address1* head1, Address** phead, Address** plast)
{

	Address1* current = head1;

	while (current)
	{

		Address* e = new Address();
		strncpy_s(e->city, current->city, CITY_SIZE - 1);
		strncpy_s(e->name, current->name, NAME_SIZE - 1);
		insert(e, phead, plast);
		current = current->next;
	}
}
void deleteX(char x[NAME_SIZE], Address** phead, Address** plast)
{
	Address* t = *phead;

	while (t)
	{
		if (!strcmp(x, t->name)) break;
		t = t->next;
	}

	if (!t)
	{
		cout << "Элемент не найден." << endl;
		return;
	}


	if (t == *phead)
	{
		*phead = t->next;
		if (*phead)
			(*phead)->prev = NULL;
		else
			*plast = NULL;
	}
	else if (t == *plast)
	{
		*plast = t->prev;
		(*plast)->next = NULL;
	}
	else
	{
		t->prev->next = t->next;
		t->next->prev = t->prev;
	}

	delete t;
	cout << "Первый элемент с заданным значением удалён." << endl;
}
void changeX(int i, Address** phead, Address** plast)
{
	if (*phead == NULL)
	{
		cout << "Список пуст." << endl;
		return;
	}


	Address* t = *phead;
	int count = 1;
	while (t)
	{
		if (count == i) break;
		t = t->next;
		count++;
	}

	if (!t)
	{
		cout << "Элемент с таким индексом не найден." << endl;
		return;
	}


	cout << "Введите новое имя: ";
	cin.getline(t->name, NAME_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	cout << "Введите новый город: ";
	cin.getline(t->city, CITY_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();

	cout << "Элемент заменён." << endl;
}
void changeX(int i, Address* x, Address** phead, Address** plast)
{
	if (*phead == NULL)
	{
		cout << "Список пуст." << endl;
		return;
	}


	Address* t = *phead;
	int count = 1;
	while (t)
	{
		if (count == i) break;
		t = t->next;
		count++;
	}

	if (!t)
	{
		cout << "Элемент с таким индексом не найден." << endl;
		return;
	}


	strncpy_s(t->name, x->name, NAME_SIZE - 1);
	strncpy_s(t->city, x->city, CITY_SIZE - 1);

	delete x;
	cout << "Элемент заменён." << endl;
}
//-----------------------------------------------------------
int main(void)
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	Address1* head1 = NULL;
	Address* head = NULL;
	Address* last = NULL;
	setlocale(LC_CTYPE, "Rus");
	while (true)
	{
		switch (menu())
		{
		case 1:  insert(setElement(), &head, &last);
			break;
		case 2: {
			char dname[NAME_SIZE];
			cout << "Введите имя: ";
			cin.getline(dname, NAME_SIZE - 1, '\n');
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			delet(dname, &head, &last);
		}
			  break;
		case 3:  outputList(&head, &last);
			break;
		case 4: {
			char fname[NAME_SIZE];
			cout << "Введите имя: ";
			cin.getline(fname, NAME_SIZE - 1, '\n');
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			find(fname, &head);
		}
			  break;

		case 6:
		{
			setElementforL(head1);
			cout << "Элемент введен." << endl; break;

		}
		case 7:
		{
			addLEnd(head1, &head, &last);
			cout << "Элементы записаны." << endl; break;
		}
		case 5:  exit(0);
		case 8:
		{
			char xname[NAME_SIZE];
			cout << "Введите имя для удаления: ";
			cin.getline(xname, NAME_SIZE - 1, '\n');
			cin.ignore(cin.rdbuf()->in_avail());
			cin.clear();
			deleteX(xname, &head, &last);
			break;
		}
		case 9:
		{
			int idx;
			cout << "Введите индекс элемента: ";
			char s[80];
			cin.sync();
			gets_s(s);
			idx = atoi(s);
			changeX(idx, &head, &last);
			break;
		}
		case 10:
		{
			int idx;
			cout << "Введите индекс элемента: ";
			char s[80];
			cin.sync();
			gets_s(s);
			idx = atoi(s);


			cout << "Введите новый элемент:" << endl;
			Address* x = setElement();

			changeX(idx, x, &head, &last);
			break;
		}
		default: exit(1);
		}
	}
	return 0;
}