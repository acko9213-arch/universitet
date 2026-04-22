#include "stdafx.h"


bool visok(int god)
{
	bool vesok = true;
	if (god % 4 != 0 && (god % 100 == 0 || god % 400 != 0))
	{
		vesok = false;
	}
	return vesok;
}