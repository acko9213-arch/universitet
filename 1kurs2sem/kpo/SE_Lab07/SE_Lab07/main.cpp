#include <iostream>
#include "Call.h"
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "rus");
	int a=4, b=1, c=10, d=7;
	int z=Call::cd(a, b, c);
	int z2=Call::stdc(a, b, c);
	int z3=Call::fastc(a, b, c, d);
    return 0;

}