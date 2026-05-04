#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "RUSSIAN");

	cout << "Введите число:";
	int a;
	if (cin >> a)
	{
		auto laymda = [a]() {
			return a>0;
			};
		if (laymda())
		{
			cout << "Число положительное";
		}
		else {
			cout << "Число не положительное";

		}
	}
	else
	{
		return 0;
	}
	return 0;
}
