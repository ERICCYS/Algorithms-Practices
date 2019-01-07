#include<bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)

int main() {
    int N;
    int M;
    cin >> N >> M;

    int P[N] = {0};
    FOR(i,0,N - 1) {
        cin >> P[i];
    }

    FOR(i, 0, N - 1) {
        P[i] -= M;
    }

    int Max_TP = 0;
    int TP = 0;
    int TP_pre = 0;
    FOR(i, 0, N - 1) {
        TP_pre = TP;
        TP += P[i];
        if (TP < 0) {
            TP = 0;
        }
        else {
            Max_TP = max(Max_TP, TP);
        }
    }

    cout << Max_TP << endl;
}
