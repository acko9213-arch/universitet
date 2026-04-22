#include "stdafx.h"
int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
int poryd(int mecyz,int dendata,bool vesok)
{
	
	int sum=0;

	if (vesok == true)
	{
		month[1] += 1;
	}
	for (int i = 0; i < mecyz - 1; i++)
	{
		sum += month[i];

	}
	if (dendata > month[mecyz - 1])
	{
		cout << "Вы ввели дату в неправильном формате." << endl;
		system("pause"); exit(1);
	}

	sum += z;
	return sum;

}
