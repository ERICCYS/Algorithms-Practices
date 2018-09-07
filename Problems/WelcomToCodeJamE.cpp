#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)

int F(int b, int e, int m, char T[], string s) {
    int c = 0;
    FOR (i, b, e) {
        if (s[i] == T[m]) {
            c++;
        }
    }
    if (c == 0 || m == 0) {
        return c;
    }
    else {
        int P[c] = {0};
        int Pc = 0;
        FOR(i, b, e) {
            if (s[i] == T[m]) {
                P[Pc] = i;
                Pc++;
            }
        }
        // P[i] obtained

        int com = 0;
        FOR(i, 0, c - 1) {
            if (P[i] > 0)
                com += F(0, P[i] - 1, m - 1, T, s);
        }
        return com;
    }

}

int main() {
    int N;
    cin >> N;

    char T[20] = "welcome to code jam";

    int R[N] = {0};
    char S[31] = {'\0'};
    getchar();
    FOR (i, 0, N - 1) {
        cin.getline(S,31);
        string str(S);
        R[i] = F(0,str.length() - 1,18,T,str);
    }

    FOR (i, 0, N - 1) {
        if (R[i] >= 10000) {
            R[i] = R[i] % 10000;
        }
        if (R[i] >= 1000) {
            cout << "Case #" << (i + 1) << ": " << R[i] << endl;
        }
        else if (R[i] >= 100) {
            cout << "Case #" << (i + 1) << ": " << "0" << R[i] << endl;
        }
        else if (R[i] >= 10) {
            cout << "Case #" << (i + 1) << ": " << "00" << R[i] << endl;
        }
        else {
            cout << "Case #" << (i + 1) << ": " << "000" << R[i] << endl;
        }

    }
}
