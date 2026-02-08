#include <iostream>

using namespace std;

int main() {
	setlocale(LC_CTYPE, "Russian");
	int a,b,p,q,r,s;
	cout << "Введите длину застройки:";
	cin >> a;
	cout << "Введите ширину застройки:";
	cin >> b;
	cout << "Введите длину  1 дома:";
	cin >> p;
	cout << "Введите ширину 1 дома:";
	cin >> q;
	cout << "Введите длину 2 дома:";
	cin >> r;
	cout << "Введите ширину 2 дома:";
	cin >> s;
	if (p<=b and q+s<=a or r <= b and q + s <= a)
		{ cout << "Возможно поставить 2 дома"; }
	else
		cout << "Неозможно поставить 2 дома";
    return 0;
}