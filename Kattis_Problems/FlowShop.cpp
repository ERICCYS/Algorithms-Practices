#include<bits/stdc++.h>
using namespace std;

int P[1001][1001];

int relu(int x) {
    return (x >= 0) ? x : 0;
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < 1001; i++) {
        P[i][0] = 0;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> P[i][j];
        }
    }

    for (int j = 1; j <= M; j++) {
        P[1][j] += P[1][j-1];
    }

    for (int i = 2; i <= N; i++) {
        P[i][1] += P[i-1][1];
        for (int j = 2; j <= M; j++) {
            P[i][j] += P[i][j-1] + relu(P[i-1][j] - P[i][j-1]);
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << P[i][M] << " ";
    }
    
    return 0;
}