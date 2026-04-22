#include "stdafx.h"
int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
int poryd(int x,int z)
{
	
	int sum=0;


	for (int i = 0; i < x - 1; i++)
	{
		sum += month[i];

	}

	sum += z;
	return sum;

}
