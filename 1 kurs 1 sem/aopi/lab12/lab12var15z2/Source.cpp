#include <iostream>
#include <ctime>

void main()
{
    setlocale(LC_CTYPE, "Russian");
    using namespace std;

    int F[150],D[150],i,f,d,max;

    cout << "Введите размер массива F "; cin >> f;
    cout << "Массив F:" << endl;

    srand(time(NULL));
  
    for (i = 0; i < f; i++)
    {
        *(F + i) = rand() % 200 - 100;
        cout << *(F+i) << " ";
    }
    max = *F;
    for (i = 1; i < f; i++)
    {
        if (*(F + i) >max)
        {
            max = *(F + i);
        }
        
    }
    cout << endl;
    
    cout << "Введите размер массива D "; cin >> d;
    cout << "Массив D:" << endl;
    for (i = 0; i < d; i++)
    {
        *(D + i) = rand() % 200 - 100;
        cout << *(D + i) << " ";
    }   cout << endl;
    bool find = false;
    for (i = 0; i < d; i++)
    {
        if (*(D + i) == max)
        {
            find = true; break;
        }
       
    }
    if (find==true)
    {
        cout << "В массиве D есть максимальное число массива F"; 
    }
    else {
        cout << "В массиве D нет максимального числа массива F";
        
    }

}
