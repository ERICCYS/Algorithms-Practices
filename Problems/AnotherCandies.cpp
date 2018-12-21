#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int (i) = (a); (i) <= b; (i)++)
typedef unsigned long long ull;


int main() {
    int T;
    cin >> T;

    while (T--) {
        string s;
        getline(cin, s);

        int N;
        cin >> N;
        vector<int> R;
        ull buf;

        FOR(i, 0, N - 1) {
            cin >> buf;
            R.push_back(buf);
        }

        int total = 0;

        FOR(i, 0, N - 1) {
            total += R[i];
        }

        while (total > 0) {
            total -= N;
        }

        if (total == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}