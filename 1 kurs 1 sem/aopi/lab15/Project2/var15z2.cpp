#include <iostream>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    setlocale(LC_CTYPE, "Russian");
    int n, m,cshet=0;
    cout << "Enter rows: ";
    cin >> n;
    cout << "Enter columns: ";
    cin >> m;

    
    int** A = new int* [n];
    for (int i = 0; i < n; i++)
        A[i] = new int[m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          
            A[i][j] = rand() % 2-1;
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }
    bool t = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (A[i][j] == 0)
            {
                cshet++;
                break;
            }
        }
     
    }
    cout << endl;
    if (cshet == n)
    {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (A[i][j] < 0)
                {
                    A[i][j] = 0;
                }
                cout << A[i][j] << "\t";
            }
            cout << endl;
        }
    }
    else
        cout << "нулей не обнаружено в каждлой строке";
    for (int k = 0; k < n; k++) {
        delete A[k];
    }
	delete[] A;
	return 0;
}