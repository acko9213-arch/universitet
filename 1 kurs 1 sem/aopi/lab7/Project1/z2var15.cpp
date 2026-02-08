#include <cmath>
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int q, b, a, d, c;
	cout << "Введите q=";
	cin >> q;
	cout << "Введите b=";
	cin >> b;
	for (int n = 1; n < q; n++)
	{
		a = n / 10;
		c = n % 10;
		d = pow((a + c), 2);
		if (d == b)
		{
			cout << n << endl;
		}

	}
	if (d != b)
	{
		cout << "Таких чисел нету.";
	}
	return 0;
}