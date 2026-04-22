#include "stdafx.h"
extern int month[];
extern bool vesok;
int main()
{
	
	bool poryd1;
	setlocale(LC_CTYPE, "RUSSIAN");
	int data, dr = 3001, dendr = 30, dodr, goddata = 365,sum1=0;
	cout << "Введите дату в формате ДДММГГГГ:";
	cin >> data;
	int dendata = data / 1000000, mecyz = (data / 10000) % 100, god = data % 10000;
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
		sum1 = poryd(mecyz,dendata);
		cout << "Порядковый номер дня:" << sum1 << endl;
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
			cout << "Cегодня мой день рождения!!!" << endl;
		}
		else
		{
			if (visok)
			{
				goddata++;

			}
			if (mecyz <= 01 && dendata <= 30)
			{
				dodr = dendr - sum1;
				cout << "До моего дня рождения осталось:" << dodr << " дней" << endl;
			}
			else
			{
				dodr = dendr + (goddata - sum1) - 1;
				cout << "До моего дня рождения осталось:" << dodr << " дней" << endl;
			}
		}
	}
	else {

		cout << "Вы ввели дату в неправильном формате." << endl;
		system("pause"); exit(1);

	}

	system("pause"); return 0;

}