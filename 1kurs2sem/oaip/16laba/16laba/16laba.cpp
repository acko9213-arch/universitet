#include <iostream>
using namespace std;
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
void selectionSort(int* arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            swap(arr[i], arr[minIndex]);
        }
    }
}
int main()
{
	setlocale(LC_CTYPE, "RUS");
	int A[100], B[100],C[100], v, n;
	cout << "Введите количество элементов которые введёте в A:"; cin >> v;
	cout << "Ввод в А:" << endl;
	for (int i = 0; i < v; i++) {
		cin >> A[i];
	}
	cout << "Введите количество элементов которые введёте в B:"; cin >> n;
	cout << "Ввод в B:" << endl;
	for (int i = 0; i < n; i++) {
		cin >> B[i];
	}
	int max=B[0];
	for (int i = 1; i < n; i++)
	{
		if (B[i] > max)
		{
			max = B[i];
		}
	}
	int j = 0;
	for (int i = 0; i < v; i++)
	{
		if (A[i]<max)
		{
			C[j] = A[i];
			j++;
		}
	}

	int* D = new int[j];
	int* V = new int[j];
	for (long long i = 0; i < j; i++)
	{

		V[i] = D[i]=C[i];
		cout << V[i] << " ";

	}
	cout << endl;
	
	for (int i = 0; i < j; i++)
	{
		for (int g = 0; g < j - i-1; g++)
		{
			if (D[g] > D[g + 1])
			{
				swap(D[g], D[g + 1]);
			}
		}
	}
	for (long long i = 0; i < j; i++)
	{
		cout << D[i] << " ";

	}
	cout << endl;
	fastsort(V, 0, j - 1);
	for (long long i = 0; i < j; i++)
	{
		cout << V[i] << " ";

	}
	return 0;
}
