#include <iostream>
using namespace std;

void insertsort(int* arr, long long size)
{

	cout << endl;
	int buf;
	for (int j = 1; j < size; j++)
	{

		if (arr[j] < arr[j - 1])
		{
			for (int i = j; i > 0; i--)
			{

				if (arr[i - 1] > arr[i])
				{
					buf = arr[i];
					arr[i] = arr[i - 1];
					arr[i - 1] = buf;

				}
				else
				{
					break;
				}

			}
		}
	}
	
}


int main()
{
    setlocale(LC_CTYPE, "RUS");
    int n;

    cout << "Введите количество элементов: ";
    cin >> n;

    int* arr = new int[n];

    cout << "Введите элементы: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "До сортировки: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    insertsort(arr, n);

    cout << "После сортировки: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}