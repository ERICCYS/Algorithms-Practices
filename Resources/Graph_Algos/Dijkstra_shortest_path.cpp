// Program to find Dijkstra's shortest path using priority_queue in STL
// Undirected Graph
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F

typedef pair<int, int> pii;


void print_pq(priority_queue<pii, vector <pii> , greater<pii>> pq) {
    priority_queue <pii, vector <pii> , greater<pii>> pq_1 = pq;
    while (!pq_1.empty()) {
        cout << pq_1.top().first << ", " << pq_1.top().second;
        cout << '\n';
        pq_1.pop();
    }
    cout << '\n';
}

void addEdge(vector <pii> adj[], int u, int v, int wt) {
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

void shortestPath (vector <pii> adj[], int V, int src) {
    // Create a priority queue to store vertices that 
    // are being preprocessed. This is weird syntax in C++. 
    int d[V];
    int pi[V];
    // int S[V];
    for (int i = 0; i < V; i++) {
        d[i] = INF;
        pi[i] = -1;
        // S[i] = 0;
    }
    d[src] = 0;

    priority_queue <pii, vector <pii> , greater<pii>> pq;

    pq.push(make_pair(0, src));

    while (!pq.empty()) {
        int u = pq.top().second;
        // S[u] = 1; 
        // We have made sure the vertex u's shortest path.
        pq.pop();

        for (auto x : adj[u]) {
            int v = x.first;
            int weight = x.second;
            if (d[v] > d[u] + weight) {
                d[v] = d[u] + weight;
                pi[v] = u;
                pq.push(make_pair(d[v], v));
            }
        }
        print_pq(pq);
    }

    // Print shortest distances stored in d[] 
    printf("Vertex Distance from Source\n"); 
    for (int i = 0; i < V; i++) 
        cout << i << '\t' << d[i] << endl;
        
    for (int i = 0; i < V; i++) {
        cout << "Shortest path from " << i << " to " << src << ": ";
        cout << i;
        int parent = pi[i];
        while (parent != -1) {
            cout << " -> " << parent;
            parent = pi[parent];
        }
        cout << endl;
    }
}

int main() {
    int V = 9; 
    vector<pii> adj[V]; 
  
    // making above shown graph 
    addEdge(adj, 0, 1, 4); 
    addEdge(adj, 0, 7, 8); 
    addEdge(adj, 1, 2, 8); 
    addEdge(adj, 1, 7, 11); 
    addEdge(adj, 2, 3, 7); 
    addEdge(adj, 2, 8, 2); 
    addEdge(adj, 2, 5, 4); 
    addEdge(adj, 3, 4, 9); 
    addEdge(adj, 3, 5, 14); 
    addEdge(adj, 4, 5, 10); 
    addEdge(adj, 5, 6, 2); 
    addEdge(adj, 6, 7, 1); 
    addEdge(adj, 6, 8, 6); 
    addEdge(adj, 7, 8, 7); 
  
    shortestPath(adj, V, 0); 
    return 0;
}