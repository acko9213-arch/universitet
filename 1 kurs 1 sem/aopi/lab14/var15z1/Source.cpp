#include <iostream>
#include <ctime>
int main()
{
	using namespace std;
	setlocale(LC_CTYPE, "Russian");
	int n, A[150][150],i,j,n1,sum1=0,s=0;
	srand((unsigned)time(NULL));
	cout << "Введите количество строк массива и количество элементов в строке:";
	cin >> n;
	cout << "A=";
	for (j = 0; j <=n-1; j++)
	{
		if (j != 0) { cout << "\n"; }
		cout << "{";
		for (i = 0; i <=n-1; i++)
		{

			A[j][i] = -99 + rand() % 200;
			cout << A[j][i];
			if(i!=n)
			{
				cout << ",";
			}
		}
		cout << "}";
	}
	n1 = n;
	for (j = 0; j < n1; j++)
	{
	    
		s += 1;
		i = s;
		
			for (i; i < n;i++)
			{
				sum1 += A[j][i];
			}
		
	}

	cout << endl << "Сумма верхней части:" << sum1 << endl;
	sum1 = 0; s = 0;
	for (j = 1; j < n1; j++)
	{
         s += 1;
		for (i=0; i < s; i++)
		{
			sum1 += A[j][i];
		}

	}
	cout << "Сумма нижней части:" << sum1;
	return 0;
}