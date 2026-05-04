
#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int v, const vector<vector<bool>>& graph, const vector<int>& color, int c) {
    for (int u = 0; u < graph.size(); ++u)
        if (graph[v][u] && color[u] == c)
            return false;
    return true;
}

bool graphColoringUtil(const vector<vector<bool>>& graph, int m, vector<int>& color, int v) {
    int n = graph.size();
    if (v == n) return true; 

    for (int c = 1; c <= m; ++c) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1))
                return true;
            color[v] = 0; 
        }
    }
    return false;
}

bool graphColoring(const vector<vector<bool>>& graph, int m, vector<int>& color) {
    return graphColoringUtil(graph, m, color, 0);
}

int main() {
    setlocale(LC_ALL, "Russian");

    
    int n = 5;
    vector<vector<bool>> graph(n, vector<bool>(n, false));

    graph[0][1] = graph[1][0] = true;
    graph[0][2] = graph[2][0] = true;
    graph[1][2] = graph[2][1] = true;
    graph[1][3] = graph[3][1] = true;
    graph[2][4] = graph[4][2] = true;
    graph[3][4] = graph[4][3] = true;

    int m = 3;
    vector<int> color(n, 0);

    if (graphColoring(graph, m, color)) {
        cout << "Граф можно раскрасить в " << m << " цвета:\n";
        for (int i = 0; i < n; ++i)
            cout << "Вершина " << i << " -> цвет " << color[i] << '\n';
    }
    else {
        cout << "Граф нельзя раскрасить в " << m << " цветов.\n";
    }

    return 0;
}