#include <iostream>
#include <cmath>
using namespace std;

#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)

bool Algo1(int N, int M) {
    bool TLE = false;
    int T = 1;
    if (N > M) return true;
    FOR(i, 2, N) {
        T *= i;
        if (T > M) {
            TLE = true;
            break;
        }
    }
    return TLE;
}

bool Algo2 (int N, int M) {
    bool TLE = false;
    int T = 2;
    if (N > M) return true;
    FOR(i, 2, N) {
        T *= 2;
        if (T > M) {
            TLE = true;
            break;
        }
    }

    return TLE;
}

bool AlgoPoly (int N, int M, int e) {
    bool TLE = false;
    int T = N;
    if (N > M) return true;
    FOR(i, 2, e) {
        T *= N;
        if (T > M) {
            TLE = true;
            break;
        }
    }
    return TLE;
}

bool AlgoLog (int N, int M) {
    double T = N;
    if (N > M) return true;
    T *= log2(N);
    return (T > M);
}

int main() {
    int M, N, t;
    cin >> M >> N >> t;

    switch(t) {
        case 1:
            if (Algo1(N, M))
                cout << "TLE";
            else
                cout << "AC";
            break;
        case 2:
            if (Algo2(N, M))
                cout << "TLE";
            else
                cout << "AC";
            break;
        case 3:
        case 4:
        case 5:
            if (AlgoPoly(N, M, (7 - t)))
                cout << "TLE";
            else
                cout << "AC";
            break;
        case 6:
            if (AlgoLog(N, M))
                cout << "TLE";
            else
                cout << "AC";
            break;
        case 7:
            if (N > M)
                cout << "TLE";
            else
                cout << "AC";
            break;
    }
}