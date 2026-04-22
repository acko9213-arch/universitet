#include "stdafx.h"

void vichdata(bool visok,int god)
{
	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (visok)
	{
		month[1] += 1;
}
	cout << "Введите номер порядкового дня:";
	int a;
	cin >> a;
	if (!visok)
	{
		if (a < 1 || a>365)
		{
			cout << "Вы ввели несуществующий порядковый номера" << endl;
			exit(1);
		}
	}
	else
			if (a < 1 || a>366)
			{
				cout << "Вы ввели несуществующий порядковый номера." << endl;
				exit(1);
			}
	
	if (a == 153 && visok )
	{
		cout << "Сегодня первый день лета" <<endl;
	}
	else
	if (a == 152 && !visok)
	{
		cout << "Сегодня первый день лета" <<endl;
	}
	if (a == 256)
	{
		cout << "Сегодня День программиста" << endl;
	}
	int i = 0;
	for (i ; month[i]!='\0'; i++)
	{
		if (a <32)
		{
			break;
		}

		a = a - month[i];
	}
	cout << "Число по заданному порядковому номеру дня:"<<a << endl;
	cout << "Месяц по заданному порядковому номеру дня:"<<i+1 << endl;
	cout << "Год по заданному порядковому номеру дня:" << god << endl;
}