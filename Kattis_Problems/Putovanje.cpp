#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, C, f;
    scanf("%d %d", &N, &C);
    vector<int> fs;
    for(int i = 0; i < N; i++) {
        scanf("%d", &f);
        fs.push_back(f);
    }
    int maxcnt, cnt, j, c;
    maxcnt = 0;
    for (int i = 0; i < N; i++) {
        c = C; cnt = 0; 
        j = i;
        while (j < N) {
            if (c-fs[j] >= 0) {c -= fs[j]; cnt++;}
            j++;
        }
        maxcnt = max(maxcnt, cnt);
    }
    printf("%d\n", maxcnt);
    return 0;
}