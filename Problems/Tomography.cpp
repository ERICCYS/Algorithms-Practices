#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)

bool checkAll(vector <int> A) {
    FOR(i, 0, A.size() - 1) {
        if (A[i] != 0)
            return false;
    }
    return true;
}

void printVector(vector <int> A) {
    FOR(i, 0, A.size() - 1) {
        cout << A[i] << ' ';
    }
    cout << '\n';
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> rs;
    vector<int> cs;
    int s;
    FOR(i, 0, m - 1){
        cin >> s;
        rs.push_back(s);
    }

    FOR(i, 0, n - 1){
        cin >> s;
        cs.push_back(s);
    }

    sort(rs.rbegin(), rs.rend());
    sort(cs.rbegin(), cs.rend());

    // printVector(rs);
    // printVector(cs);
    FOR(i, 0, n - 1) {
        FOR(j, 0, cs[i] - 1) {
            rs[j]--;
        }
        sort(rs.rbegin(), rs.rend());
        // printVector(rs);
    }

    if (checkAll(rs)) 
        cout << "Yes";
    else
        cout << "No";
}