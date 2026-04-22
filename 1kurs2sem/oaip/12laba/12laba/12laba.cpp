#include <iostream>
#include <queue>
using namespace std;
int size(queue <char>& q)
{ 
	int size=0;
	queue <char>& z = q;
	while (!z.empty())
	{

		size++;q.pop();
	}
	return  size;
}
void delet(queue <char>& q)
{
	q.pop();
	cout << "Элемент удален." << endl;
}
void output(queue <char>& q)
{
	cout << "Элемент:"<<q.front()<<endl;q.pop();
}
void input(queue <char>& q, char x,char etalon)
{
	if (x == etalon)
	{
		if (!q.empty())
		{
			q.pop();
			if (!q.empty())
			{
				q.pop();
			}
		}	 cout <<"Размер:" << size(q) << endl;
	}
	else
	{
		q.push(x);
	}

}
int main()
{
    queue <char> q;
	setlocale(LC_CTYPE, "Rus");
	char etalon;
	cout << "Введите эталонный символ: ";
	cin>> etalon;
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
		case 1: { char choice1; cin >> choice1;  input(q,choice1,etalon); break; }
		case 2: {
			output(q);	break;
		}
			  break;
		case 3: { delet(q);   break; }
		case 4: { cout<<size(q)<<endl; break; }
		case 5: {
			exit(1);
		}

		default:cout << "Нет такого варианта.Попробуйте ещё раз."; cin.clear(); cin.ignore(10000, '\n');
		}
	}

    return 0;
}
