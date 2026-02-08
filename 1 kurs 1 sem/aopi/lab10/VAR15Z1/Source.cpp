#include <iostream>
#include <ctime>

void main()
{
    setlocale(LC_CTYPE, "Russian");
    using namespace std;
    const int N = 500;
    int i, sz, A[N], rmn = -99, rmx = 99,cshet=0,n=0,X[N],x=0;

    cout << "Введите размер массива ";
    cin >> sz;
    cout << "Массив A:" << endl;

    srand(time(NULL));

    for (i = 0; i < N; i++)
    {
        A[i] = (int)(((double)rand() / (double)RAND_MAX) * (rmx - rmn) + rmn);
       
    }
    for (i = 0; i < sz; i++)
    {
        

        cout << A[i] << ", ";

    }
    cout << endl;
    for (i = 0; i < sz; i++)
    {
        
        if (i % 3 == 0 && i > 2)
        {
            
            i = i + 1;
            cshet++;
     
            
        }
        X[n] = A[i];
        cout << X[n] << ", ";
        n = n + 1;
    }



    sz = sz - cshet; cout << endl; i = 0; cshet = sz;
  
    for (i=0; i<cshet; i++) 
    {
        if (X[i] < 0)
        {
            for (int j = cshet; j > i + 1; j--)
                X[j] = X[j - 1];

            X[i + 1] = 10;  
            cshet++;        
            i++;
            x += 1;
        } 
        
    }
    for (i = 0; i < cshet; i++)
    {
        cout << X[i] << ", ";
    }
}