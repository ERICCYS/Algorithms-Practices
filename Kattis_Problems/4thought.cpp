#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int(i) = (a); (i) <= (b); (i)++)

int Execute(int x, int y, int z) {
    char opx = (x == 0) ? '+' : (x == 1) ? '-' : (x == 2) ? '*' : '/';
    char opy = (y == 0) ? '+' : (y == 1) ? '-' : (y == 2) ? '*' : '/';
    char opz = (z == 0) ? '+' : (z == 1) ? '-' : (z == 2) ? '*' : '/';

    if (opx == '+') {
        if (opy == '+') {
            if (opz == '+') return (4 + 4 + 4 + 4);
            if (opz == '-') return (4 + 4 + 4 - 4);
            if (opz == '*') return (4 + 4 + 4 * 4);
            if (opz == '/') return (4 + 4 + 4 / 4);
        }
        if (opy == '-') {
            if (opz == '+') return (4 + 4 - 4 + 4);
            if (opz == '-') return (4 + 4 - 4 - 4);
            if (opz == '*') return (4 + 4 - 4 * 4);
            if (opz == '/') return (4 + 4 - 4 / 4);
        }
        if (opy == '*') {
            if (opz == '+') return (4 + 4 * 4 + 4);
            if (opz == '-') return (4 + 4 * 4 - 4);
            if (opz == '*') return (4 + 4 * 4 * 4);
            if (opz == '/') return (4 + 4 * 4 / 4);
        }
        if (opy == '/') {
            if (opz == '+') return (4 + 4 / 4 + 4);
            if (opz == '-') return (4 + 4 / 4 - 4);
            if (opz == '*') return (4 + 4 / 4 * 4);
            if (opz == '/') return (4 + 4 / 4 / 4);
        }
    }
    if (opx == '-') {
        if (opy == '+') {
            if (opz == '+') return (4 - 4 + 4 + 4);
            if (opz == '-') return (4 - 4 + 4 - 4);
            if (opz == '*') return (4 - 4 + 4 * 4);
            if (opz == '/') return (4 - 4 + 4 / 4);
        }
        if (opy == '-') {
            if (opz == '+') return (4 - 4 - 4 + 4);
            if (opz == '-') return (4 - 4 - 4 - 4);
            if (opz == '*') return (4 - 4 - 4 * 4);
            if (opz == '/') return (4 - 4 - 4 / 4);
        }
        if (opy == '*') {
            if (opz == '+') return (4 - 4 * 4 + 4);
            if (opz == '-') return (4 - 4 * 4 - 4);
            if (opz == '*') return (4 - 4 * 4 * 4);
            if (opz == '/') return (4 - 4 * 4 / 4);
        }
        if (opy == '/') {
            if (opz == '+') return (4 - 4 / 4 + 4);
            if (opz == '-') return (4 - 4 / 4 - 4);
            if (opz == '*') return (4 - 4 / 4 * 4);
            if (opz == '/') return (4 - 4 / 4 / 4);
        }
    }
    if (opx == '*') {
        if (opy == '+') {
            if (opz == '+') return (4 * 4 + 4 + 4);
            if (opz == '-') return (4 * 4 + 4 - 4);
            if (opz == '*') return (4 * 4 + 4 * 4);
            if (opz == '/') return (4 * 4 + 4 / 4);
        }
        if (opy == '-') {
            if (opz == '+') return (4 * 4 - 4 + 4);
            if (opz == '-') return (4 * 4 - 4 - 4);
            if (opz == '*') return (4 * 4 - 4 * 4);
            if (opz == '/') return (4 * 4 - 4 / 4);
        }
        if (opy == '*') {
            if (opz == '+') return (4 * 4 * 4 + 4);
            if (opz == '-') return (4 * 4 * 4 - 4);
            if (opz == '*') return (4 * 4 * 4 * 4);
            if (opz == '/') return (4 * 4 * 4 / 4);
        }
        if (opy == '/') {
            if (opz == '+') return (4 * 4 / 4 + 4);
            if (opz == '-') return (4 * 4 / 4 - 4);
            if (opz == '*') return (4 * 4 / 4 * 4);
            if (opz == '/') return (4 * 4 / 4 / 4);
        }
    }
    if (opx == '/') {
        if (opy == '+') {
            if (opz == '+') return (4 / 4 + 4 + 4);
            if (opz == '-') return (4 / 4 + 4 - 4);
            if (opz == '*') return (4 / 4 + 4 * 4);
            if (opz == '/') return (4 / 4 + 4 / 4);
        }
        if (opy == '-') {
            if (opz == '+') return (4 / 4 - 4 + 4);
            if (opz == '-') return (4 / 4 - 4 - 4);
            if (opz == '*') return (4 / 4 - 4 * 4);
            if (opz == '/') return (4 / 4 - 4 / 4);
        }
        if (opy == '*') {
            if (opz == '+') return (4 / 4 * 4 + 4);
            if (opz == '-') return (4 / 4 * 4 - 4);
            if (opz == '*') return (4 / 4 * 4 * 4);
            if (opz == '/') return (4 / 4 * 4 / 4);
        }
        if (opy == '/') {
            if (opz == '+') return (4 / 4 / 4 + 4);
            if (opz == '-') return (4 / 4 / 4 - 4);
            if (opz == '*') return (4 / 4 / 4 * 4);
            if (opz == '/') return (4 / 4 / 4 / 4);
        }
    }
}

void PrintString(int x, int y, int z, int n) {
    char opx = (x == 0) ? '+' : (x == 1) ? '-' : (x == 2) ? '*' : '/';
    char opy = (y == 0) ? '+' : (y == 1) ? '-' : (y == 2) ? '*' : '/';
    char opz = (z == 0) ? '+' : (z == 1) ? '-' : (z == 2) ? '*' : '/';

    cout << "4 " << opx << " 4 " << opy << " 4 " << opz << " 4 = " << n << endl;
}

void Search(int n, int R[][4][4]) {
    FOR(i, 0, 3) {
        FOR(j, 0, 3) {
            FOR(k, 0, 3) {
                if (R[i][j][k] == n) {
                    PrintString(i, j, k, n);
                    return ;
                }
            }
        }
    }
    cout << "no solution" << endl;    
}

int main() {
    int T;
    cin >> T;

    int R[4][4][4];

    FOR(i, 0, 3) {
        FOR(j, 0, 3) {
            FOR(k, 0, 3) {
                R[i][j][k] = Execute(i, j, k);
            }
        }
    }
    int n;
    FOR(t, 0, T - 1) {
        cin >> n;
        Search(n, R);
    }
}