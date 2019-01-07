#include<bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)

int main() {
    int n;
    cin >> n;

    int length = 2 + ((n-1) / 25);
    char S[length];

    if (n <= 25) {
        S[0] = 'a';
        S[1] = (char)('a' + n);
        FOR(i, 0, length - 1) {
            cout << S[i];
        }
        cout << endl;
    }
    else {
        bool IfA = 1;
        FOR(i, 0, length - 1) {
            S[i] = IfA ? 'a' : 'z';
            IfA = !IfA;
        }
        if (n == 25 * (length - 1)) {
            FOR(i, 0, length - 1) {
                cout << S[i];
            }
            cout << endl;
        }
        else {
            if (length == 3) {
                char posChar = (char)('a' + ((n + 1) / 2));
                S[1] = posChar;
                if (n % 2 != 0) {
                    S[2] = 'b';
                }
            }
            else {
                int dif = n - 25 * (length - 3);
                char posChar = (char)('a' + (dif + 1)/ 2);
                S[1] = posChar;
                if (dif % 2 != 0) {
                    if (S[length - 1] == 'z') {
                        S[length - 1] = 'y';
                    }
                    else {
                        S[length - 1] = 'b';
                    }
                }
            }
            FOR(i, 0, length - 1) {
                cout << S[i];
            }
            cout << endl;
        }
    }
}
