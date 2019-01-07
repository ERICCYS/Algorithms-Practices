#include <iostream>
using namespace std;

#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)
#define REP(i, n) FOR(i, 0, (n) - 1)
int main() {
    int N;
    cin >> N;

    int A[N];
    REP(i, N) {
        cin >> A[i];
    }

    int cnt = 1;
    int G[N] = {0};
    G[0] = A[0];

    bool flag = true;
    int Gi = 0;
    int pre_index = 0; // Record the last index we start from

    while (flag) {
        FOR(i, pre_index, N - 1) {
            if (A[i] > G[Gi]) {
                G[++Gi] = A[i];
                pre_index = i + 1;
                cnt++;
                if (i != (N - 1))
                    break;
            }
            if (i == (N - 1))
                flag = false;
        }
    }

    cout << cnt << endl;
    REP(i, cnt) {
        cout << G[i] << " ";
    }
    cout << endl;

}
