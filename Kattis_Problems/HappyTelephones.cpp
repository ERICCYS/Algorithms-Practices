#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

bool inside(pii A, pii B) {
    if (A.first <= B.first && A.second >= B.second && B.second - B.first >= 1) {return true;}
    if (A.first >= B.first && A.second <= B.second && A.second - A.first >= 1) {return true;}
    if (A.second <= B.second && A.second - B.first >= 1) {return true;}
    if (A.first >= B.first && B.second - A.first >= 1) {return true;}
    return false;
}

int main() {
    int N, M;
    int sr, de, st, du, s, d;
    vpii calls;
    vpii intervals;
    int cnt;
    while(1) {
        scanf("%d %d", &N, &M);
        if (N == 0 && M == 0) {break;}
        calls.clear();
        intervals.clear();
        for (int i = 0; i < N; i++) {
            scanf("%d %d %d %d", &sr, &de, &st, &du);
            calls.push_back(make_pair(st, st + du));
        }
        for (int i = 0; i < M; i++) {
            scanf("%d %d", &s, &d);
            intervals.push_back(make_pair(s, s + d));
        }
        for (int i = 0; i < M; i++) {
            cnt = 0;
            // cout << "Checking " << intervals[i].first << ", " << intervals[i].second << endl; 
            for (int j = 0; j < N; j++) {
                // cout << "Checking " << calls[j].first << ", " << calls[j].second << endl; 
                if(inside(calls[j], intervals[i])) {
                    // cout << "Inside" << endl;
                    cnt++;
                }
            }
            printf("%d \n", cnt);
        }
    }
    return 0;
}
