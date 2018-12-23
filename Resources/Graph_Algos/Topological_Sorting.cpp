// Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering 
// of vertices such that for every directed edge uv, vertex u comes before v in the ordering. 
// Topological Sorting for a graph is not possible if the graph is not a DAG.

#include <bits/stdc++.h>
using namespace std;

void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
}

void topologicalSortUntil(vector<int> adj[], int u, vector <bool> &visited, stack<int> &s)  {
    // cout << "Visiting " << u << endl;
    visited[u] = true;
    for (auto x : adj[u]) {
        if (!visited[x]) {
            topologicalSortUntil(adj, x, visited, s);
        }
    }
    cout << "Push " << u << " to the stack\n";
    s.push(u);
}

void topologicalSort(vector <int> adj[], int V) {
    stack <int> s;
    vector <bool> visited(V, false);

    for (int i = 0; i < V; i++) {
        if (visited[i] == false) {
            topologicalSortUntil(adj, i, visited, s);
        }
    }

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main()
{
    int V = 6;
    vector <int> adj[V];
    
    addEdge(adj, 5, 2); 
    addEdge(adj, 5, 0); 
    addEdge(adj, 4, 0); 
    addEdge(adj, 4, 1); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 3, 1); 
  
    cout << "Following is a Topological Sort of the given graph \n";
    topologicalSort(adj, V);
    return 0;
}
