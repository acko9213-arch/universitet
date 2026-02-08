#include <iostream>
#include <stdio.h>
using namespace std;
int main()

{
	int a, b, c;
	setlocale(LC_CTYPE, "russian");
	printf("Введите номер квартиры:");
	scanf_s ("%d", &a);
		b = (a - 1) / 36 + 1;
		c = ((a - 1) % 36) / 4 + 1;
		printf("Номер подъезда - %d\n", b);
		printf("Номер этажа - %d\n", b);
	return 0;
}