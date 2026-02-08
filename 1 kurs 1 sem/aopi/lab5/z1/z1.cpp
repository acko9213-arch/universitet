#include <iostream>
int main()
{
	int a, b, c, d;
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	cout << "¬ведите первое число ";
	cin >> a;
	cout << "¬ведите второе число ";
	cin >> b;
	cout << "¬ведите третье число ";
	cin >> c;
	d = (a % 5 == 0 ? a : 0) + (b % 5 == 0 ? b : 0) + (c % 5 == 0 ? c : 0);
	cout << d;



	return 0;
}