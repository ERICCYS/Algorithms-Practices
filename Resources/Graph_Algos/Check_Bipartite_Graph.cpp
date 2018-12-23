// Following is a simple algorithm to find out whether 
// a given graph is Birpartite or not using Breadth First Search (BFS).

// 1. Assign RED color to the source vertex (putting into set U).
// 2. Color all the neighbors with BLUE color (putting into set V).
// 3. Color all neighbor’s neighbor with RED color (putting into set U).
// 4. This way, assign color to all vertices such that it satisfies all the constraints of m way coloring problem where m = 2.
// 5. While assigning colors, if we find a neighbor which is colored with same color as current vertex, 
// then the graph cannot be colored with 2 vertices (or graph is not Bipartite)

// Note: Disconnected graph can also be bipartite, so we need to do BFS for every vertex
#include <bits/stdc++.h>
using namespace std;
#define V 4
void addEdge(int adj[][V], int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 0;
}

bool isBipartiteUntil(int adj[][V], int src, int color[]) {
    // Create a color array to store colors assigned to all veritces.  
    // Vertex number is used as index in this array.  
    // The value '-1' of colorArr[i] is used to indicate that no color is assigned to vertex 'i'.   
    // The value 1 is used to indicate first color is assigned  
    // The value 0 indicates second color is assigned.

    color[src] = 1;

    queue <int> q;
    q.push(src);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (adj[u][u] == 1) {
            // If the graph contains self-loop, then it is not bipartite
            return false;
        }

        for (int v = 0; v < V; v++) {
            // Check the verteice that is adjacent to u
            if (adj[u][v] == 1 && color[v] == -1) {
                // Assign alternate color to this adjacent v of u 
                color[v] = 1 - color[u];
                q.push(v);
            }

            else if (adj[u][v] == 1 && color[v] == color[u]) {
                // An edge from u to v exists and v is colored with same color as u 
                return false;
            }
        }
    }

    return true;
}

bool isBipartite(int adj[][V]) {
    int color[V];
    for (int i = 0; i < V; i++) {
        color[i] = -1;
    }

    for (int i = 0; i < V; i++) {
        if (color[i] == -1) {
            if (isBipartiteUntil(adj, i, color) == false)
                return false;
        }
    }
    return true;
}

int main() {
    int adj[][V] = {{0, 1, 0, 1}, 
                    {1, 0, 1, 0}, 
                    {0, 1, 0, 1}, 
                    {1, 0, 1, 0} 
    };

    isBipartite(adj) ? cout << "Yes\n" : cout << "No\n";

    int adj1[][V] = {{0, 0, 0, 0}, 
                    {0, 0, 0, 0}, 
                    {0, 0, 0, 0}, 
                    {0, 0, 0, 0} 
    };
    isBipartite(adj1) ? cout << "Yes\n" : cout << "No\n";
    return 0;
}