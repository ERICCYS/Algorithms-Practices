#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)
#define SIZE 101
#define MOD 1001113

ull GetPDC(int N, int d, ull Memo[][SIZE]) {
    if (d == (N - 1) || d == 0) {
        Memo[N][d] = 1;
    }
    else if (Memo[N][d] == 0){
        Memo[N][d] = ((d + 1) * GetPDC((N - 1), d, Memo) + (N - d) * GetPDC (N - 1, d - 1, Memo)) % MOD;
    }
    return Memo[N][d];
}


int main() {
    ull Memo[SIZE][SIZE];

    FOR(i, 0, SIZE - 1) {
        FOR(j, 0, SIZE - 1) {
            Memo[i][j] = 0;
        }
    }
    int T;
    cin >> T;
    FOR(i, 1, T) {
        int buf;
        int N, d;
        cin >> buf >> N >> d;;
        cout << i << " " << GetPDC(N, d, Memo) << endl;
    }

}
