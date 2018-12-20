#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    vector<int> U;
    unordered_map<int, int> M;
    priority_queue<int, vector<int>, greater<int>> V;
    int id;
    for (int i = 0; i < T; i++) {
        cin >> id;
        U.push_back(id);
        M[id]++;
    }
    if (U[U.size()-1] != T+1) {
        cout << "Error";
        return 0;
    }
    for(int i = 1; i <= T + 1; i++) {
        if (M.find(i) == M.end()) {
            // vertices that has never been a parent.
            V.push(i);
        }
    }
    for (int i = 0; i < T; i++) {
        cout << V.top() << endl;
        V.pop();
        int u = U[i];
        if(--M[u] == 0) {
            // if there is no more u remaining in the U, it means U becomes an leaf.
            V.push(u);
        }
        if (V.empty()) {
            cout << "Error";
            return 0;
        }
    }
    return 0;
}