#include <iostream>
using namespace std;


#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)

int main() {
    int T;

    cin >> T;

    FOR(i, 0, T - 1) {
        int D, M;
        cin >> D >> M;

        int Md[M] = {0};
        FOR(i, 0 , M-1) {
            cin >> Md[i];
        }
        bool Ht[M] = {0};
        FOR(i, 0, M-1) {
            if (Md[i] >= 13) {
                Ht[i] = 1;
            }
        }

        int Amd[M] = {0};
        FOR(i, 0, M-1) {
            Amd[i] = Md[i];
        }

        FOR(i, 1, M-1) {
            Amd[i] += Amd[i - 1];
        }
        int Tr[M] = {0};
        Tr[0] = 13;
        FOR (i, 1, M-1) {
            Tr[i] = 13 + Amd[i - 1];
        }

        int c = 0;

        FOR(i, 0, M-1) {
            if (Ht[i] == 1) {
                if (Tr[i] % 7 == 6)
                    c++;
            }
        }
        cout << c << endl;
    }
}
