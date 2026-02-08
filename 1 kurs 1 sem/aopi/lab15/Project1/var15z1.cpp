#include <iostream>
#include <ctime>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int size,cshet=0,j,l=0,k=0;
	double c;
	cout << "Enter size ";
	cin >> size;
	cout << "Enter c ";
	cin >> c;
	double *A = new double[size];
	srand(time(0));
	for (j = 0; j < size; j++)
	{
		A[j] = -99 + (double)rand() / RAND_MAX * 198;
		cout << A[j] << " ";
		if (A[j] < c) {
			cshet++;
		}
	}
	
	for (int i = size-1, j = 0; i >= j; i--)
	{
		if (A[i] < 0)
		{
			k= 1+i;
			for (k; k < size; k++)
			{
				l += (int)A[k];
			}
			break;
		}
	}
	
	cout <<endl << "Количество повторения чисел меньших "<<c<<":"<<cshet<<endl<<"Cумма:"<<l;
	delete[] A;
	return 0;
}