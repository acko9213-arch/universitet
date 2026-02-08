#include <iostream>
#include <ctime>

void main()
{
    setlocale(LC_CTYPE, "Russian");
    using namespace std;

    int i, k, n, arr[10], rmn = 0, rmx = 99;

    cout << "Введите размер массива k:";
    cin >> k;
    cout << "Насколько сместить массив влево:";
    cin >> n;
    cout << "Массив arr:" << endl;

    srand(time(NULL));

    for (i = 0; i < k; i++)
    {
        arr[i] = (int)(((double)rand() / (double)RAND_MAX) * (rmx - rmn) + rmn);
        cout << arr[i] << ", ";
    }
    cout << endl;
    cout << "Смещённый массив arr:" << endl;
    for (i = 0; i < k - n; i++)
    {
        arr[i] = arr[i + n];
    }
    for (i = 0; i < k - n; i++)
    {

        cout << arr[i] << ", ";
    }
}