#include<bits/stdc++.h>
using namespace std;
#define SIZE 12

int N, M, cnt;
bool used[SIZE];
bool first_result;
vector<string> cols;
vector<string> cur;
vector<string> best;
map<string, set<string>> cons;

void DFS(int p) {
    if (p == N) { // Found a valid solution
        cnt++;
        if (first_result) {
            for (int i = 0; i < N; i++) { best[i] = cur[i]; }
            first_result = false;
        }
        return;
    }

    for (int i = 0; i < N; i++) {
        if (used[i]) { continue; }
        if (cur.empty() || cons[cur.back()].find(cols[i]) == cons[cur.back()].end()) { // This color can be used in this case
            used[i] = true;
            cur.push_back(cols[i]);
            DFS(p + 1);
            // Backtrack: After finish this, pop the recent added and set used[this_item] to false.
            cur.pop_back();
            used[i] = false;
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    string a, b;
    while (T--) {
        scanf("%d", &N);
        cols.clear(); cols.resize(N); 
        for (int i = 0; i < N; i++) { cin >> cols[i]; }
        scanf("%d", &M);
        cons.clear();
        for (int i = 0; i < M; i++) { 
            cin >> a >> b;
            cons[a].insert(b); cons[b].insert(a);
        }

        cnt = 0;
        first_result = true;
        best.clear(); best.resize(N);

        DFS(0);
        printf("%d\n", cnt);
        for (int i = 0; i < N; i++) { cout << best[i] << " "; }
        printf("\n");
    }
    return 0;
}