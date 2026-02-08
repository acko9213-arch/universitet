#include <iostream>
#include <ctime>
using namespace std;
void baby(int n,int m,int **p);
int main() {
    srand(time(0));
    setlocale(LC_CTYPE, "Russian");
    int n, m;
    cout << "Enter rows: ";
    cin >> n;
    cout << "Enter columns: ";
    cin >> m;

    
    int** A = new int* [n];
    for (int i = 0; i < n; i++)
        A[i] = new int[m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            A[i][j] = rand() % 3 - 1;
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }
    baby(n, m, A);
    for (int k = 0; k < n; k++) {
        delete A[k];
    }
    delete[] A;
    return 0;
}





void baby(int n, int m, int** p){
    bool t = true; int cshet = 0, b = -1;
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            if (p[j][i] > 0)
            {
                cshet++;
                break;
            }

        }
    }
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            if (p[j][i] > 0)
            {
                break;
            }
            b = i; break;
        }
        if (b == i)
        {
            break;
        }
    }





    cout << endl;
    if (cshet != n)
    {
        int j = 0;
        for (int i = 0; i < n; i++) {
            p[i][j] = abs(p[i][j]);
        }
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {
                cout << p[i][j] << " ";

            }
            cout << endl;
        }
    }
    else
        cout << "В каждой строке есть хотя бы одно положительное число";
}