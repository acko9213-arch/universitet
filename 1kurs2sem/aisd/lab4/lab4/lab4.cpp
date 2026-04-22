#include <iostream>
using namespace std;
#include <ctime>
#include <vector>
int main()
{
		setlocale(LC_CTYPE, "RUS");
		int N;
		cout << "Введите число N:";
		cin >> N;
		if (N < 1 || N>9999)
		{
			exit(1);
		}
		vector <int> v1, vmin, vmax;
		int j;
		srand(time(0));
		cout << "Список цен: ";
		for (int i = 0; i < N; i++)
		{
			v1.push_back(rand() % 100 + 1);
			cout << v1[i] << " ";
		}
		cout << endl;
		for (int i = 0; i < N / 2; i++)
		{
			int min = 101,temp=0;
			for (j = 0; j < v1.size(); j++)
			{
				if (v1[j] < min)
				{
					min = v1[j]; temp = j;
				}
			}
			vmin.push_back(v1[temp]);
			v1.erase(v1.begin() + temp);
		}
		int temp = 0,sum=0; j = 0;
		for (int i=0;i<N;i++)
		{
			if (!((i + 1) % 2==0))
			{ 
				vmax.push_back(v1[j]);sum+=v1[j]; j++;	
			}
			else
			{
				vmax.push_back(vmin[temp]);
				temp++;
			}
		}
		for (int i :vmax)
		{
			cout << i << " ";
		}
		cout << " - это один из возможных вариантов вывода."<<endl<<sum <<" - максимальная сумма чека.";
	return 0;
}