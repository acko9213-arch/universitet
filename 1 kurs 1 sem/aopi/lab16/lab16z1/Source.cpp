#include <iostream>
#include <ctime>
using namespace std;
void baby(double** A, double C, int size)
{
	double d, sum;
	int r, g, j=0;

	d = abs(A[0][0]);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (abs(A[i][j]) > d)
			{
				d = A[i][j];
				r = i;

			}
		}

	}
	sum = 1;
	for (r += 1; r < size; r++)
	{
		for (g = j + 1; g < size; g++)
		{
			sum *= A[r][g];

		}

	}
	if (sum == 1) { cout << "Нету чисел"; }
	else
	{
		cout << "Произведение чисел =" << sum;
	}
}
int main()
{ 
	setlocale(LC_CTYPE, "Russian");
	int size,d=0,i;
	double** A,C;
		cout << "Enter size ";
		cin >> size;
		cout << "Enter C ";
		cin >> C;
		srand(time(0));
		A = new double* [size];
		for (int i = 0; i < size; i++)
		{
			A[i] = new double[size];
			for (int j = 0; j < size; j++)
			{
				A[i][j] = -99 + (double)rand() / RAND_MAX * 198;
				cout << A[i][j] <<" ";
				if (A[i][j] > C)
				{
					d++;
				}

			}
			cout << endl;
		}
		cout << "Количество чисел больших " << C << "=" << d << endl;
		
		
		baby(A, C, size);
		for (int k = 0; k < size; k++) 
			delete[] A[k];
		delete[] A;

	return 0;
}
