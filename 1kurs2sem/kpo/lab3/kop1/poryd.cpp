#include "stdafx.h"
int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
int poryd(int x,int z,bool y)
{
	
	int sum=0;

	if (y == true)
	{
		month[1] += 1;
	}
	for (int i = 0; i < x - 1; i++)
	{
		sum += month[i];

	}
	if (z > month[x - 1])
	{
		cout << "Вы ввели дату в неправильном формате." << endl;
		system("pause"); exit(1);
	}

	sum += z;
	return sum;

}
