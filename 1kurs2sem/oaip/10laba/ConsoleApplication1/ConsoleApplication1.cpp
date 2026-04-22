#include <iostream>
#include <stack>
#include <Windows.h>
using namespace std;
int main()
{
	stack <int> st;


		SetConsoleOutputCP(1251);
		SetConsoleCP(1251);
		int sum=0;
		setlocale(LC_CTYPE, "Rus");
		while (true)
		{
			int choice;
			cout << endl;
			cout << "1. Ввод элемента в стек" << endl;
		

			cout << "2. Вывод элемента стека" << endl;
			

			cout << "3. Выход" << endl;
		
			cout << "Выбор: ";

			cin >> choice;
			switch (choice)
			{
			case 1: { int x; cout << "Элемент:"; cin >> x;  st.push(x); break; }
			case 2: {
				if (st.empty())
				{
					cout << "стек пуст"; break;
				}
				int x = st.top(); st.pop(); sum += x;
				if (sum > 10)
				{
					cout << "Сумма выведенных элементов:" << sum << endl << "Размер стека:" << st.size(); return 0;
					
				}
				cout << "Элемент:"<< x<<endl;
				 break;
			}
				  break;
			
			case 3:  exit(0);
		

			default:cout << "Нет такого варианта.Попробуйте ещё раз."; cin.clear(); cin.ignore(10000, '\n');
			}
		
	}
	return 0;
}