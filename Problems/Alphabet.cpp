#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)

int LongestIncSub(string S) {
    int N = S.length();
    char A[N];

    FOR(i, 0, N - 1) {
        A[i] = S[i];
    }

    int LIS[N];
    LIS[0] = 1;
    FOR(j, 0, N - 1) {
        LIS[j] = 1;
        FOR(k, 0, j - 1) {
            if (A[j] > A[k]) {
                LIS[j] = max(LIS[j], LIS[k] + 1);
            }
        }
    }

    int max_len = LIS[0];
    FOR(i, 0, N - 1) {
        if (max_len < LIS[i])
            max_len = LIS[i];
    }
    return max_len;
}


int main() {
    string S;
    cin >> S;
    int N = 0;
    N = LongestIncSub(S);
    cout << (26 - N) << endl;


    return 0;
}
