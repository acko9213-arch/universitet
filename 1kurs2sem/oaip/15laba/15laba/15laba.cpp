#include <iostream>
#include <list>
#include <stdarg.h>
#include <queue>
using namespace std;

const int MAX = 15;
list<int> adjList[MAX];
int n = 5; 

void addEdge(int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}


void addEdges(int edgeCount, ...) {
    va_list args;
    va_start(args, edgeCount);
    for (int i = 0; i < edgeCount; i++) {
        int u = va_arg(args, int);
        int v = va_arg(args, int);
        addEdge(u, v);
        cout << "Добавлено ребро: " << u << " - " << v << "\n";
    }
    va_end(args);
}

int pick(int z, int d) {
    int dist[MAX];
    for (int i = 0; i < MAX; i++) dist[i] = -1;

    queue<int> q;
    q.push(z);
    dist[z] = 0;

    int count = 0;
    cout << "BFS с вершины " << z << " (d=" << d << "): ";

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int x : adjList[current]) {
            if (dist[x] == -1) {
                dist[x] = dist[current] + 1;
                if (dist[x] <= d) {
                    count++;
                    q.push(x);
                }
            }
        }
    }
    cout << "\n";
    return count;
}

int main() {
    setlocale(LC_CTYPE, "Rus");

   
    addEdges(1, 0, 1);             
    addEdges(2, 0, 4, 1, 2);      
    addEdges(3, 1, 3, 1, 4, 2, 3); 

    int d;
    cout << "\nВведите максимальную длину пути: ";
    cin >> d;

    cout << "\nРезультат:\n";
    for (int v = 0; v < n; v++) {
        cout << "Вершина " << v << ": "
            << pick(v, d)
            << " вершин достижимы за <= " << d << " шагов\n\n";
    }

    return 0;
}