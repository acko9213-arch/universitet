#include <iostream>
#include <time.h>
#include <ctime>
using namespace std;
void bublesort(int* arr,long long size)
{
	cout << endl;
	int buf;
	for (int j = 0; j <size; j++)
	{
	
		for (int i = 1; i<size-j; i++)
		{
			
			if (arr[i] < arr[i - 1])
			{
				buf = arr[i-1];
				arr[i-1] = arr[i];
				arr[i] = buf;

			}
		
		}
	}
	cout << endl << "Отсортированный пузырьком массив:";
	
}
void insertsort(int* arr, long long size)
{
	
		cout << endl;
		int buf;
		for (int j = 1; j < size; j++)
		{
			
			if (arr[j] < arr[j-1])
			{ 
				for (int i = j; i>0; i--)
				{
					
					if (arr[i-1] > arr[i])
					{
						buf = arr[i];
						arr[i] = arr[i-1];
						arr[i-1] = buf;

					}
					else 
					{
						break;
					}

				}
			}
		}
		cout << endl << "Отсортированный вставкой массив:";
		}
void selectionsort(int* arr, long long size)
{

	cout << endl;
	int buf,min,k;
	
	for (int i = 0; i < size; i++)
	{ 
		min = arr[i];
		k = i;
		for (int j=1+i; j < size;j++ )
		{
			if (min > arr[j])
			{
				min = arr[j];
				k = j;
			}
		}
		
			buf = arr[k];
			arr[k] = arr[i];
			arr[i] = buf;
	
	}
	cout << endl << "Отсортированный выбором массив:";

}
void fastsort(int* arr, int left, int right)
{
	if (left < right)
	{
		int buf;
		int sr = arr[right];  
		int i = left - 1;

		for (int j = left; j < right; j++)
		{
			if (arr[j] <= sr)
			{
				i++;
				buf = arr[i];
				arr[i] = arr[j];
				arr[j] = buf;
			}
		}
		
		buf = arr[i + 1];
		arr[i + 1] = arr[right];
		arr[right] = buf;

		int p = i + 1;  
		fastsort(arr, left, p - 1);
		fastsort(arr, p + 1, right);
	}
}
int main()
{
	clock_t start, end;
	double t;
	setlocale(LC_CTYPE, "RUS");
	long long N;
	cout << "Введите число N:";
	cin >> N;
	int *A = new int[N];
	int* B = new int[N];
	int* C = new int[N];
	int* D = new int[N];
	int* E = new int[N];
	srand(time(0)); 
	cout << "Неотсортированный массив: " ;
	for (long long i = 0;i<N ; i++)
	{
		
		C[i] = D[i] = E[i] = B[i] = A[i] = rand();
		cout << D[i]<<" ";
	
	}
	start = clock();
	bublesort(B, N);
	end = clock();
	for (int j = 0; j < N; j++)
	{
		cout << B[j] << ' ';
	}
	t = (double)(end - start) / CLOCKS_PER_SEC;
	cout << endl << "Время выполнения сортировки: " << t << " секунд";


	start = clock();
	insertsort(C, N);
	end = clock();
	for (int j = 0; j < N; j++)
	{
		cout << C[j] << ' ';
	}



	t = (double)(end - start) / CLOCKS_PER_SEC;
	cout << endl << "Время выполнения сортировки: " << t << " секунд";



	start = clock();
	selectionsort(D, N);
	end = clock();
	for (int j = 0; j < N; j++)
	{
		cout << D[j] << ' ';
	}


	t = (double)(end - start) / CLOCKS_PER_SEC;
	cout << endl << "Время выполнения сортировки: " << t << " секунд";


	start = clock();
	fastsort(E,0, N-1);
	cout << endl << "Быстроотсортированный массив:";
	end = clock();

	for (int j = 0; j < N; j++)
	{
		cout << E[j] << ' ';
	}


	t = (double)(end - start) / CLOCKS_PER_SEC;
	cout << endl << "Время выполнения сортировки: " << t << " секунд";
	delete[] A; delete[] B; delete[] E; delete[] C; delete[] D;
	return 0;
}