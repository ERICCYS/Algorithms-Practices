#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

ull total = 0;
ull sub_total = 0;
ull P2[41];
vector<int> weights;
vector<int> less_weights;
vector<int> cur;

void DFS(int p) {
    for (int i = p; i < less_weights.size(); i++) {
        if ((accumulate(cur.begin(), cur.end(), 0) + less_weights[i]) < 200) {
            cur.push_back(less_weights[i]);
            sub_total += accumulate(cur.begin(), cur.end(), 0);
            DFS(i + 1); 
            cur.pop_back();
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    weights.resize(N);
    for(int i = 0; i < N; i++) { scanf("%d", &weights[i]); }
    less_weights.clear();
    for(int i = 0; i < N; i++) { if(weights[i] < 200) less_weights.push_back(weights[i]); }
    sort(less_weights.begin(), less_weights.end());
    cur.clear();
    if (less_weights.size() > 0) { DFS(0); }

    P2[0] = 1;
    for (int i = 1; i < 41; i++) { P2[i] = P2[i-1] * 2; }

    total = accumulate(weights.begin(), weights.end(), 0) * P2[N-1];
    cout << total - sub_total;
    return 0;
}