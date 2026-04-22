#include "stdafx.h"

void porydmecyz(int mecyz)
{
	char nazvmecyz[13][20] =
	{
		"Январь",
		"Февраль",
		"Март",
		"Апрель",
		"Май",
		"Июнь",
		"Июль",
		"Август",
		"Сентябрь","Октябрь","Ноябрь","Декабрь"
	};
	cout << "Порядковый номер месяца:" << mecyz << endl << "Название этого  месяца:" << nazvmecyz[mecyz - 1];
	
	
	cout << endl;

}