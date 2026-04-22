
#include <iostream>
#include <cstdlib>
using namespace std;

int sum = 0, month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
bool vesok=true;
void visok(int x)
{
	if (x % 4 == 0 && (x % 100 != 0 || x % 400 == 0))
	{
		
		vesok = false; 
	}
	else 
	{
		month[1] += 1;  }
}
void poryd(int x,int z)
{
	

	
		for (int i = 0; i < x- 1; i++)
		{
			sum += month[i];

		}
	
	sum += z;
	cout << "Порядковый номер дня:" << sum << endl;
	
}


int main()
{
	bool poryd1;
	setlocale(LC_CTYPE, "RUSSIAN");
	int data,dr = 3001, dendr = 30, dodr,goddata=365;
	cout << "Введите дату в формате ДДММГГГГ:";
	cin >> data;
	int dendata = data / 1000000, mecyz = (data/10000)%100, god = data%10000;
	if (god <= 2026 && dendata <= 31 && mecyz <= 12 && data < 100000000 && data>1000000)
	{
		visok(god);
		if (vesok)
		{
			if (mecyz == 02 && dendata > 29)
			{
				cout << "Вы ввели дату в неправильном формате." << endl;
				system("pause"); return 0;
			}

		}
		else
		{
			if (mecyz == 02 && dendata > 28)
			{
				cout << "Вы ввели дату в неправильном формате." << endl;
				system("pause"); return 0;
			}
		}
		if (dendata > month[mecyz - 1])
		{
			cout << "Вы ввели дату в неправильном формате." << endl;
			system("pause"); exit(1);
		}

		if (vesok)
		{
			cout << "Этот год високосный" << endl;
		}
		else
		{
			cout << "Этот год не високосный" << endl;
		}
		poryd(mecyz,dendata);
		if (god <= 2008)
		{
			if (mecyz <= 01)
			{
				if (dendata < 30)
				{
					cout << "Я ещё не родился." << endl;
					system("pause"); return 0;
				}
			}
		}
		if (god < 2008)
		{
			cout << "Я ещё не родился." << endl;
			system("pause"); return 0;
		}

		


		if (data / 10000 == dr)
		{
			cout << "Cегодня мой день рождения!!!" <<endl;
		}
		else 
		{
			if (visok)
			{
				goddata++;

			}
			if (mecyz <= 01 && dendata <= 30)
			{
				dodr = dendr - sum;
				cout << "До моего дня рождения осталось:" << dodr << " дней"<<endl;
			}
			else
			{
				dodr = dendr + (goddata - sum)-1;
				cout << "До моего дня рождения осталось:" << dodr << " дней" << endl;
			}
		}
	}
	else{
		
			cout << "Вы ввели дату в неправильном формате." << endl;
			system("pause"); exit(1);
		
	}
	
	system("pause"); return 0;

}