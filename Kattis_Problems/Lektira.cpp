#include<bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)

void check(string S, string& Opt, int i, int j) {
    reverse(S.begin(), S.begin()+i);
    reverse(S.begin()+i, S.begin()+j);
    reverse(S.begin()+j, S.end());
    if (S < Opt) {
        Opt = S;
    }
}

int main() {
    string S;
    cin >> S;
    string Opt(S);

    FOR(i, 1, S.length() - 2) {
        FOR(j, i + 1, S.length() - 1) {
            check(S, Opt, i, j);
        }
    }
    cout << Opt;
}
