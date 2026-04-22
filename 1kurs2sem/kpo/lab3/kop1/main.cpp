#include "stdafx.h"
#include "poryd.h"
#include "visok.h"
#include "porydmecyz.h"
#include "vichdata.h"
int main()
{
	setlocale(LC_CTYPE, "RUSSIAN");
	int data, dr = 3001, dendr = 30, dodr, goddata = 365, sum1 = 0,goddr=2008; bool vesok1 = true;
	cout << "Введите дату в формате ДДММГГГГ:";
	cin >> data;
	int dendata = data / 1000000, mecyz = (data / 10000) % 100, god = data % 10000;

	if ( dendata <= 31 && mecyz <= 12 && data < 100000000 && data>1000000)
	{
		{
		 vesok1=visok(god);
		}
		
		sum1 = poryd(mecyz, dendata,vesok1);
		if (vesok1)
		{
			cout << "Этот год високосный" << endl;
		}
		else
		{
			cout << "Этот год не високосный" << endl;
		}
		porydmecyz(mecyz);

		cout << "Порядковый номер дня:" << sum1 << endl;

		if (god <= goddr && mecyz <= dr % 100 && dendata < dr / 100)
		{
			cout << "Я ещё не родился." << endl;
			
		}
		if (god < goddr)
		{
			cout << "Я ещё не родился." << endl;
			
		}



		if (data / 10000 == dr)
		{
			cout << "Cегодня мой день рождения!!!" << endl;
		}
		else
		{
			if (vesok1)
			{
				goddata++;

			}
			if (mecyz <= dr%100 && dendata <= dr/100)
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
	vichdata(vesok1,god);
	system("pause"); return 0;

}