#include <iostream>

int main()
{
    using namespace std;
    setlocale(LC_CTYPE, "Russian");
    int n, A[4][4] = {
        {3,0,-1,0 },
        {1,-8,-9,0},
        {4,6,-2,0},
         { 2,-1,-9,0 }
    }
    , i = 0, j, Y, k;

    for (j = 0; j < 4; j++)
    {
        if (A[i][j] == 0)
        {
            Y = i;
            for (n = 0; n < 3; n++)
            {
                Y += 1;
                if (A[Y][j] != 0)
                {
                    break;
                }
                else { k = j; break; }
            }
        }
    }
    for (i = 0; i < 4; i++)
    {
        A[k][i] *= (-1);
    }
    cout << "A=";
    n = 4;
    for (j = 0; j <= n - 1; j++)
    {
        if (j != 0) { cout << "\n"; }
        cout << "{";
        for (i = 0; i <= n - 1; i++)
        {
            cout << A[j][i];
            if (i != n)
            {
                cout << ",";
            }
        }
        cout << "}";
    }

    return 0;
}