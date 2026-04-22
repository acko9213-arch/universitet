#include <iostream>
using namespace std;
#include <ctime>
#include <vector>
int main()
{
	setlocale(LC_CTYPE, "RUS");
	int N,sum=0;
	cout << "Введите число N:";
	cin >> N;
	if (N < 1 || N>9999)
	{
		exit(1);
	}
	vector <int> v1;
	srand(time(0));
	cout << "Результаты участников: ";
	for (int i = 0; i < N; i++)
	{
		v1.push_back(rand() % 100 + 1);
		cout << v1[i] << " ";
	}
	cout << endl;
	cout << "Результаты побидителей:";
	for (int i = 0; i < 3;i++)
	{
		int max = 0;
		for (int j = 0; j < v1.size(); j++)
		{
			if (v1[j] >max)
			{
				max = v1[j]; 
			}
		}
		for (int j = 0; j < v1.size(); j++)
		{
			if (max == v1[j])
			{
				sum++; cout <<  max<<" ";
				v1.erase(v1.begin() + j);
			}
		}
	}
	cout <<endl<< "Призёры:"<<sum;
	return 0;
}