#include<bits/stdc++.h>
using namespace std;

bool join[12];
bool join_copy[12];

int main() {
    int N, S, R;
    scanf("%d %d %d", &N, &S, &R);
    memset(join, 1, sizeof(join));
    vector<int> damaged(S);
    vector<int> reserved(R);
    for(int i = 0; i < S; i++) { cin >> damaged[i];  join[damaged[i]] = 0; }
    for(int i = 0; i < R; i++) { cin >> reserved[i]; }
    int cnt, min_cnt = 10;
    for (int i = 0; i < (1<<R); i++) {
        // cout << i << endl;
        for (int j = 0; j < 12; j++) { join_copy[j] = join[j]; }
        for (int j = 0; j < R; j++) {
            if ((i & (1<<j))) { join_copy[reserved[j] + 1] = 1; }
            else { join_copy[reserved[j] - 1] = 1; }
        }
        cnt = 0;
        for (int j = 0; j < 12; j++) { if(!join_copy[j]) cnt++; }
        min_cnt = min(min_cnt, cnt);
    }
    printf("%d", min_cnt);
    return 0;
}