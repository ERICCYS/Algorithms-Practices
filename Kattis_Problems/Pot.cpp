#include <iostream>

using namespace std;

#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)

int main() {
    int N;
    cin >> N;
    int num[N] = {0};
    int pow[N] = {0};
    FOR(i, 0 , N-1) {
        cin >> num[i];
        pow[i] = num[i] % 10;
        num[i] = num[i] / 10;
    }
    int R = 0;
    int r = 0;
    FOR (i, 0, N - 1) {;
        r = num[i];

        if (pow[i] > 0) {
            FOR(j, 0, pow[i] - 2) {
                r *= num[i];
            }
        }
        else {
            r = 1;
        }
        R += r;
    }

    cout << R;
}
