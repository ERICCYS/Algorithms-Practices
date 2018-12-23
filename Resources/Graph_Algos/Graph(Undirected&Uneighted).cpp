// A simple representation of graph using STL, 
// for the purpose of competitive programming 

// #include <bits/stdc++.h> is equivalent to include all the libraries inside.
// From SWE's perspective, it is not eficient because it includes many uncessary libraries.
// For competitive programming, it is a good idea.

#include <bits/stdc++.h>
using namespace std;

// A utility function to add an edge in an 
// undirected graph. 
void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void DFSUntil (int u, vector<int> adj[], vector<bool> &visited) {
    visited[u] = true;
    cout << u << " ";
    for (int i = 0; i < adj[u].size(); i++) {
        if (visited[adj[u][i]] == false) {
            DFSUntil(adj[u][i], adj, visited);
        }
    }
}

void DFS(vector<int> adj[], int V) {
    vector<bool> visited(V, false);
    for (int u = 0; u < V; u++) {
        if (visited[u] == false) {
            DFSUntil(u, adj, visited);
        }
    }
}

void printGraph(vector <int> adj[], int V) {
    int v, w;
    for (int u = 0; u < V; u++) {
        cout << "Node" << u << " makes an edge with: " << endl;
        for (auto it = adj[u].begin(); it != adj[u].end(); it++) {
            v = *it;
            cout << "\tNode " << v << endl;
        }
        cout << endl;
    }
}
int main() {
    int V = 5;

    vector<int> adj[V];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 3, 4);
    printGraph(adj, V);
    DFS(adj, V);
    return 0;
}