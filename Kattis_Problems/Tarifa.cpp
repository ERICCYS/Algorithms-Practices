#include <iostream>

using namespace std;

#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)

int main() {
    int M;
    cin >> M;

    int N;
    cin >> N;

    int P[N] = {0};
    FOR(i, 0, N - 1) {
        cin >> P[i];
    }

    int R = M;

    FOR(i, 0 , N - 1) {
        R += (M - P[i]);
    }
    cout << R;
}
