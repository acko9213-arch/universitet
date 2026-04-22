#include "stdafx.h"


bool visok(int x)
{
	bool vesok = true;
	if (x % 4 != 0 && (x % 100 == 0 || x % 400 != 0))
	{
		vesok = false;
	}
	return vesok;
}