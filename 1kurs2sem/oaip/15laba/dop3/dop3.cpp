#include <iostream>

using namespace std;


struct Node {
    int vertex;
    Node* next;
};
Node* createNode(int v) {
    Node* newNode = new Node;
    newNode->vertex = v;
    newNode->next = nullptr;
    return newNode;
}


void addEdge(Node** adj, int u, int v) {

    Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}


void dfs(int v, Node** adj, bool* visited, int& count) {
    visited[v] = true;
    count++;

   
    Node* current = adj[v];
    while (current != NULL) {
        if (!visited[current->vertex]) {
            dfs(current->vertex, adj, visited, count);
        }
        current = current->next;
    }
}

int largestComponent(Node** adj, int n) {
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    int maxSize = 0;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            int compSize = 0;
            dfs(i, adj, visited, compSize);
            if (compSize > maxSize) {
                maxSize = compSize;
            }
        }
    }

    delete[] visited;
    return maxSize;
}
void freeGraph(Node** adj, int n) {
    for (int i = 0; i < n; ++i) {
        Node* current = adj[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] adj;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int n = 7;
    Node** adj = new Node * [n];
    for (int i = 0; i < n; ++i) {
        adj[i] = NULL;
    }

    addEdge(adj, 0, 1);
    
    addEdge(adj, 1, 2);
    
    addEdge(adj, 2, 3);
   
    addEdge(adj, 0, 3);

    
    addEdge(adj, 4, 5);
    
    addEdge(adj, 5, 6);

    int largest = largestComponent(adj, n);
    cout << "Размер наибольшей компоненты связности: " << largest << " вершин\n";

    
    freeGraph(adj, n);

    return 0;
}