#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int T[N] = {0};
    int C = 0;
    for (int i = 0; i < N; i++) {

        cin >> T[i];
    }
    for (int i = 0; i < N; i++) {
        if (T[i] < 0) {
            C++;
        }
    }
    cout << C;
    return 0;
}
