#include<bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int(i) = (a); (i) <= (b); (i)++)
#define SIZE 100

int CheckFlies(int vr_start, int hr_start, int len, int Map[][SIZE]) {
    int cnt = 0;
    FOR(i, (vr_start + 1), (vr_start + len - 2)) {
        FOR(j, (hr_start + 1), (hr_start + len - 2)) {
            if (Map[i][j] == 1) {
                cnt++;
            }
        }
    }

    return cnt;
}

int main() {
    int R, S, K;
    cin >> R >> S >> K;
    string Str[R];
    FOR(i, 0, R - 1) {
        cin >> Str[i];
    }

    char A[R][S];
    int Map[SIZE][SIZE] = {{0,0}};
    FOR(i, 0, R - 1) {
        FOR(j, 0, S - 1) {
            A[i][j] = Str[i][j];
            if (Str[i][j] == '*') {
                Map[i][j] = 1;
            } else {
                Map[i][j] = 0;
            }
        }
    }

    int vr = 0;
    int hr = 0;

    int flies = 0;

    FOR(i, 0, R - K) {
        FOR(j, 0, S - K) {
            if (CheckFlies(i, j, K, Map) > flies) {
                vr = i;
                hr = j;
                flies = CheckFlies(i, j, K, Map);
            }
        }
    }

    cout << flies << endl;
//    cout << vr << " " << hr << endl;

    A[vr][hr] = '+';
    A[vr + K - 1][hr] = '+';
    A[vr][hr + K - 1] = '+';
    A[vr + K - 1][hr + K - 1] = '+';

    FOR(i, vr + 1, vr + K - 2) {
        A[i][hr] = '|';
    }
    FOR(i, vr + 1, vr + K - 2) {
        A[i][hr + K - 1] = '|';
    }

    FOR(j, hr + 1, hr + K - 2) {
        A[vr][j] = '-';
    }
    FOR(j, hr + 1, hr + K - 2) {
        A[vr + K - 1][j] = '-';
    }

    FOR(i, 0, R - 1) {
        FOR(j, 0, S - 1) {
            cout << A[i][j];
        }
        cout << endl;
    }
}
