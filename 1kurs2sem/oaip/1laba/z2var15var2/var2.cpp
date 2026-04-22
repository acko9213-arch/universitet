#include <cstdlib>
#include <iostream>
#include <cstdarg>
using namespace std;
void perevod(int num, ...)
{
	char buffer[33];
	va_list list;
	va_start(list, num);

	for (int i = 1; i <= num; i++)
	{
		int abc = va_arg(list, int);
		cout << "Число в десятичной коде " << abc;
		_itoa_s(abc, buffer, 2);
		cout << " Число в двоичном коде " << buffer << endl;

	}
	va_end(list);
}
int main()
{
	setlocale(LC_CTYPE, "russian");
	perevod(5, 4, 2, 8, 9, 9);

	return 0;
}