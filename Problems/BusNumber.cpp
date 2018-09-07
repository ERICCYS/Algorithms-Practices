#include <iostream>
#include <algorithm>

using namespace std;


#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)

int main() {
    int N;
    cin >> N;

    int B[N] = {0};
    FOR(i, 0, N - 1) {
        cin >> B[i];
    }

    sort(B, B + N);

    int R[N] = {0};

    FOR (i, 1, N - 1) {
        if (B[i] == B[i - 1] + 1) {
            R[i] = R[i - 1] + 1;
        }
        continue;
    }

    cout << B[0];
    FOR (i, 1, N - 1) {
        if (R[i] == 0) {
            cout << " " << B[i];
        }
        else if (R[i] == 1 && (i == N - 1 || R[i + 1] == 0)) {
            cout << " " << B[i];
        }
        else if (R[i] > 1 && (i == N - 1 || R[i + 1] == 0)) {
            cout << "-" << B[i];
        }
        else
            continue;
    }

    return 0;
}
