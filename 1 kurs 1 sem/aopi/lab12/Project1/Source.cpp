#include <iostream>
#include <ctime>

void main()
{
    setlocale(LC_CTYPE, "Russian");
    using namespace std;

    int i, k, n, arr[150],j;

    cout << "Введите размер массива"; cin >> n;
    cout << "Массив arr:" << endl;

    srand(time(NULL));
    for (i = 0; i < n; i++)
    {
        *(arr + i) = rand() % 200 - 100;
        cout << *(arr+i) << " ";

    }
    cout<< endl;
    for (i = 0; i < n-1; i++)
    {
        for (j=0; j < n-1; j++)
        {
            
            
            if (*(arr + j) < 0)
            {                                                                           
                k = *(arr + j+1);
                *(arr + j + 1)=*(arr + j);
                    *(arr + j) = k;
            }
            
        }
    }
    for (int i = 0; i < n; i++) {
        cout << *(arr + i) << " ";
    }
}