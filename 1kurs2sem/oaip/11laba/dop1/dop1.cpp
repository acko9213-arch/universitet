#include <iostream>
#include <deque>
struct Request {
	int floor;     
	int priority;   
};
using namespace std;
void input(int a,int b,deque <Request> &dek, deque <Request>& h, deque <Request>& l)
{
	Request r;
	r.floor = b;
	r.priority = a;
	for (Request x : l)
	{
		if (b == x.floor)
		{
			cout << "Элемент не записан." << endl; return;
		}
	}for (Request x : h)
	{
		if (b == x.floor)
		{
			cout << "Элемент не записан." << endl; return;
		}
	}
	if (a == 0)
	{
		l.push_back(r);
	}
	else
	{
		h.push_back(r);

	}
}
void output(deque <Request>& h, deque <Request>& l)
{
	int j = 0;
	for (Request r : h)
	{
		cout << "Лифт остановился на " << r.floor << endl;
	}

	for (Request r : l)
	{
		cout << "Лифт остановился на " << r.floor << endl;
		
	}
	l.clear();
	
	h.clear();
}
int main()
{
	int value;
	setlocale(LC_CTYPE, "RUS");
	deque <Request> dek,high,low;
	while (true)
	{
		cout << "Выберите (1-ввод запроса),(2-показать движение лифта),(3-выход):";
		cin >> value;
		switch (value)
		{
		case 1:
		{
			int a, b;
			cout << "Введите  уровень запроса(0-1):";
			cin >> a;
			cout << "Введите номер этажа:";
			cin >> b;
			input(a, b, dek,high,low);
			break;
		}
		case 2:

		{

			output(high,low); dek.clear(); break;
		}
		case 3:
		{
			return 0;
		}
		default:
		{
			cout << "Попробуйте ещё раз." << endl; cin.clear(); cin.ignore(10000, '\n'); break;
		}
		}
	}
}