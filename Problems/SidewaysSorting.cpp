#include <iostream>
#include <algorithm>
using namespace std;
#define FOR(i, a, b) for(int (i) = (a); (i) <= b; (i)++)
#define ROF(i, a, b) for(int (i) = (a); (i) >= b; (i)--)

bool compare (string A, string B) {
    string A_bf = A;
    string B_bf = B;
    transform(A_bf.begin(), A_bf.end(), A_bf.begin(), ::tolower);
    transform(B_bf.begin(), B_bf.end(), B_bf.begin(), ::tolower);
    if (A_bf < B_bf)
        return true;
    else
        return false;
    
}
int main() {
    int r, c;
    while (1) {
        cin >> r >> c;
        if (r == 0 && c == 0)
            break;
        
        char A[r][c];
        FOR(i, 0, r - 1) {
            FOR(j, 0, c - 1) {
                cin >> A[i][j];
            }
        }
        string S[c];
        char buffer[r] = {'\0'};
        FOR(j, 0, c - 1) {
            FOR(i, 0, r - 1) {
                buffer[i] = A[i][j];
            }
            string s(buffer);
            S[j] = buffer;
        }

        sort(S, S + c, compare);

        FOR(i, 0, r - 1) {
            FOR(j, 0, c - 1) {
                cout << S[j][i];
            }
            cout << endl;
        }

        cout << endl;
        
    }
}