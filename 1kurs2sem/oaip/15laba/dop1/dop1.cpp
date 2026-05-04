#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int INF = 1e9;

void floydWarshall(vector<vector<int>>& dist, int n) {

    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main() {
    setlocale(LC_ALL, "Russian");

    int n = 4;
    vector<vector<int>> dist(n, vector<int>(n, INF));


    for (int i = 0; i < n; ++i) dist[i][i] = 0;


    dist[0][1] = 5;
    dist[0][3] = 10;
    dist[1][2] = 3;
    dist[2][3] = 1;
    dist[3][1] = -4; 

    floydWarshall(dist, n);

    cout << "Кратчайшие расстояния между всеми парами вершин:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] >= INF) cout << setw(5) << "INF";
            else cout << setw(5) << dist[i][j];
        }
        cout << '\n';
    }

    bool negativeCycle = false;
    for (int i = 0; i < n; ++i)
        if (dist[i][i] < 0) negativeCycle = true;

    if (negativeCycle)
        cout << "\nОбнаружен отрицательный цикл\n";
    else
        cout << "\nОтрицательных циклов нет, алгоритм корректен.\n";

    return 0;
}