#include <iostream>
using namespace std;

#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)

int main() {
    int M, P, L, E, R, S, N;
    int pre_M;
    int pre_L;
    int pre_P;
    while (cin >> M && cin >> P && cin >> L && cin >> E && cin >> R && cin >> S && cin >> N) {
        FOR(i, 0, N - 1) {

            pre_M = M;
            pre_L = L;
            pre_P = P;

            M -= pre_M;
            L += pre_M * E;


            L -= pre_L;
            P += (int)(((1 / (double)R)) * pre_L);

            P -= pre_P;
            M += (int)(((1 / (double)S)) * pre_P);
        }
        cout << M << endl;
    }
}
