#define ST
#include <iostream>
#include "stroka.h"
#include <string>
#include <Windows.h>
using namespace stroks;
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_CTYPE, "RUS");
	char a[50], b[50];
	cout << "Введите строку a:";
	cin.getline(a, 49);
	cout << "Введите строку б:";
	cin.getline(b, 49);
	cout << dlina(a) << endl << dlina(b);
	cout << endl << konk(a, b) << endl;
	if (palin(a))
	{
		cout << "Это палиндром";
	}
	else {
		cout << "Не палиндром";
	}
	return 0;
}