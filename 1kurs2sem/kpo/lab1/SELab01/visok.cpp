#include "stdafx.h"
extern int month[];
bool vesok = true;
void visok(int x)
{
	
	if (x % 4 != 0)
	{

		vesok = false;
	}
	else
	{
		month[1] += 1;
	}
}