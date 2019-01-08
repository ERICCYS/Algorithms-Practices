#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, M, a, b, cnt = 0;
    bool valid;
    scanf("%d %d", &N, &M);
    vector<pair<int, int>> constrains;
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &a, &b);
        constrains.push_back(make_pair(a,b));
    }
    for (int i = 0; i < (1<<N); i++) {
        valid = true;
        for (int j = 0; j < M; j++) {
            if (!valid) { break; }
            valid = valid && (!((i & (1<<(constrains[j].first - 1))) && (i & (1<<(constrains[j].second - 1)))));
        }
        if (valid) { cnt++; }
    } 
    printf("%d\n",cnt);
    return 0;
}