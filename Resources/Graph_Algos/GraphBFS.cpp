#include <bits/stdc++.h>
using namespace std;
#define pb push_back

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].pb(v);
    adj[v].pb(u);
}

void BFS(vector<int> adj[], int V, vector<bool> &visited) {
    for (int u = 0; u < V; u++){
        if (visited[u] == true)
            continue;
        queue <int> q;
        q.push(u);
        visited[u] = true;
        cout << "Node " << u << " is visited\n"; 
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            for (auto it = adj[front].begin(); it != adj[front].end(); it++) {
                if (visited[*it] == false) {
                    q.push(*it);
                    visited[*it] = true;
                    cout << "Node " << *it << " is visited\n";
                }
            }
        }
        cout << "A round of BFS is done\n\n";
    }
}


int main() {
    int V = 7;
    vector <int> adj[V];
    vector <bool> visited(V, false);

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 4, 6);

    BFS(adj, V, visited);
    return 0;
}