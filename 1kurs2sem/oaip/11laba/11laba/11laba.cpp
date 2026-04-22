#include <iostream>
#include <deque>
using namespace std;
int main()
{
	int value;
	setlocale(LC_CTYPE, "RUS");
	deque <int> c;
	while (true)
	{
		cout << "Выберите (1-ввод в дек),(2-проверить семмитрична ли последовательность):";
		cin >> value;
		switch(value)
		{
		case 1:
		{
			cout << "Введите значение:";
			cin >> value;
			c.push_back(value);
			break;
		}
		case 2:
		
		{
			while (true)
			{
				if (c.size() == 1 || c.empty())
				{
					cout << "Число семмитрично"; return 0;
				}
				if (c.front() != c.back())
				{
					cout << "Число не семмитрично"; return 0;

				}
				else
				{
					c.pop_front();
					c.pop_back();
				}
			}
			break;
		}
		
		default:
		{
			cout << "Попробуйте ещё раз." << endl; cin.clear(); cin.ignore(10000, '\n'); break;
		}
		}
	 }
}