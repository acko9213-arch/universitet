#include <iostream>
using namespace std;

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

    selectionSort(arr, n);

    cout << "После сортировки: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}