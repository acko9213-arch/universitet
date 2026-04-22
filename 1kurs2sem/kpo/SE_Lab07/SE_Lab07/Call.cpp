#include "Call.h"

int _cdecl Call::cd(int x, int b, int c)
{
	return x + b + c;
}
int _stdcall Call::stdc(int& a, int b, int c)
{
	return a * b * c;
}
int _fastcall Call::fastc(int a, int b, int c, int d)
{
	return a + b + c + d;
}