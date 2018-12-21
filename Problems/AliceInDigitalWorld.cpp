#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int(i) = (a); (i) <= (b); (i)++)

int Search(int m, int Mi, int A[], int n) {
    int ans = m;
    int index = Mi - 1;
    while (index >= 0) {
        if (A[index] > m) {
            ans += A[index];
            index--;
            continue;
        }
        break;
    }
    index = Mi + 1;
    while (index < n) {
        if (A[index] > m) {
            ans += A[index];
            index++;
            continue;
        }
        break;
    }

    return ans;
}

int main() {
    int T;
    cin >> T;
    FOR(t, 0 , T - 1) {
        int n, m;
        cin >> n >>  m;
        int A[n];
        int M[n] = {-1};
        int M_index = 0;
        FOR(i, 0, n - 1) {
            cin >> A[i];
            if (A[i] == m) {
                M[M_index++] = i;
            }
        }
        int ans = m;
        FOR(i, 0, M_index - 1) {
            ans = max(ans, Search(m, M[i], A, n));
        }

        cout << ans << endl;
    }

}