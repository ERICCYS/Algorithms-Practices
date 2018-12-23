#include <bits/stdc++.h>
using namespace std;

void addEdge (vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void DFSUntil (int u, vector<int> adj[], vector<bool> &visited) {
    visited[u] = true;
    cout << u << " has been visited.\n";
    for (int i = 0; i < adj[u].size(); i++) {
        if (visited[adj[u][i]] == false) {
            DFSUntil(adj[u][i], adj, visited);
        }
    }
}

void DFS(vector <int> adj[], int V) {
    vector <bool> visited (V, false);
    for (int i = 0; i < V; i++) {
        if (visited[i] == false) {
            DFSUntil(i, adj, visited);
        }
    }
}
int main() {
    int V = 5;
    vector <int> adj[V];
    // An array of vector to represent the graph.
    // Number of element in the array means the number of nodes.
    // The vectors is the 'adjacancy lists'
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

    DFS(adj, V);
    return 0;
}