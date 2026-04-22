#include <iostream>
using namespace std;

void shellSort(int* arr, int n)
{
    int gap = n / 2;

    while (gap > 0)
    {
 
        for (int i = gap; i < n; i++)
        {
            int key = arr[i];
            int j = i;

            while (j >= gap && arr[j - gap] > key)
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            arr[j] = key;
        }

        gap /= 2; 
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

    shellSort(arr, n);

    cout << "После сортировки: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}