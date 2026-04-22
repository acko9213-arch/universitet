
#include <iostream>
#include <time.h>
using namespace std;
void cikl(int x, long long v, long long  z)
{
	clock_t start, end;
	double time;
	setlocale(LC_CTYPE, "russian");

	unsigned long long y;
	start = clock();

	for (int i = 3; i <= x; i++)
	{
		y = v + z;
		z = v; v = y;
	}
	end = clock();
	time = (int)(end - start) / CLOCKS_PER_SEC;
	int time1 = time / 60;
	cout << "N-ое число Фибоначчи циклом:" << y << endl << "Расчетное время циклом " << time1 << " минут " << time << " секунд." << endl;
}



long long  rekurs(int x)
{



	if (x == 0 || x == 1)
	{		
		return x;
	}
	return rekurs(x - 1) + rekurs(x - 2);

}
int main()
{
	clock_t start1, end1;
	double time2;
	setlocale(LC_CTYPE, "russian");
	cout << "Введите N-ое число Фибоначи:";
	int N;
	unsigned long long F1 = 0, F2 = 1;;
	int i=2;
	cin >> N;
	if (N == 1 || N == 2 ) {
		N = 1;
		cout <<"N-ое число Фибоначчи:" << N;
		return 0;
	}
	if (N == 0)
	{
		cout << "N-ое число Фибоначчи:" << N;
		return 0;
	}
	if (N < 0)
	{
		exit(1);
	}
	cikl(N, F2, F1);
	start1 = clock();
	cout << "N-ое число Фибоначчи рекурсией:" << rekurs(N - 1) << endl;
	end1 = clock();
	time2 = (int)(end1 - start1) / CLOCKS_PER_SEC;
	cout << "Расчетное время циклом " << (int)time2 / 60 << " минут " << (int)time2 % 60 << " секунд." << endl;
	return 0;

}