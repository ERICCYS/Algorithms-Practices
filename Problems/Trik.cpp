#include <iostream>
#include <string>
using namespace std;

#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)

int main() {
    string S = "\0";

    int P = 1;

    cin >> S;

    FOR (i, 0, 49) {
        if (S[i] == 'A') {
            if (P == 1)
                P = 2;
            else if (P == 2)
                P = 1;
//            cout << "Now P is " << P;
        }
        else if (S[i] == 'B') {
            if (P == 2)
                P = 3;
            else if (P == 3)
                P = 2;
//            cout << "Now P is " << P;
        }
        else if (S[i] == 'C') {
            if (P == 1)
                P = 3;
            else if (P == 3)
                P = 1;
//            cout << "Now P is " << P;
        }
        else
            break;
    }

    cout << P;
    return 0;
}
