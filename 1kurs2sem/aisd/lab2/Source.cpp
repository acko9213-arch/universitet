#include <iostream>
using namespace std;
void binpoisk(long long z)
{
	static long long verxgr = z * 2, nizgr = 0, i = z * 2;
	cout << "Число X:" << z;
	cout << endl << "Выберите верный вариант.(1-мало,2-много,3-угадал)" << endl;
	int a;
	cin >> a;
	switch (a)
	{
	case 1: {
		nizgr = z; 
		z = nizgr + ((verxgr - nizgr) / 2); binpoisk(z); break;
	}
	case 2:
	{
		verxgr = z; 
		z = verxgr - ((verxgr - nizgr) / 2);
		 binpoisk(z); break;
	}
	case 3:
	{

		z = 0;
		while (i != 1) {
			z++;
			cout << i << endl;
			if (i % 2 == 1)
				i = (i / 2) + 1;
			else
				i = i / 2;
		}
		cout << i << endl;
		cout << "Максимальное число шагов = " << z;
		break;

	}
	default:
	{
		cout << "Вы ввели неверный вариант.Попробуйте снова" <<endl; binpoisk(z); break;

	}
	}
}
int main()
{
	setlocale(LC_CTYPE, "rus");
	long long N;
	static long long K;
	cout << "Введите диапазон числа: ";
	cin >> N;
	if (N % 2 != 0)
	{
		K = (N + 1) / 2;
	}
	else
	{
		K= N/2;
	}
	binpoisk(K);
	
	return 0;
}