#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define FOR(i, a, b) for (int (i) = (a); i <= (b); (i)++)


int main() {
    int C;
    cin >> C;

    int R[C] = {0};
    FOR(j, 0, C - 1) {
        int N;
        cin >> N;
        string S[N] = {"\0"};
        FOR (i, 0, N - 1) {
            cin >> S[i];
        }

        sort(S, S + N);

        int r = 0;
        FOR (i, 0, N - 2) {
            if (S[i].length() <= S[i + 1].length()) {
                if (S[i + 1].compare(0,S[i].length(), S[i]) == 0) {
                    r = 1;
                    break;
                }
            }
            else
                continue;
        }
        R[j] = r;
    }

    FOR (j, 0, C - 1) {
        if (R[j] == 0) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
