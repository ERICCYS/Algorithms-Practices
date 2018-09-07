#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define FOR(i, a, b) for(int(i) = (a); (i) <= (b); (i)++)

int Min (int A[], int N) {
    int Min = A[0];
    FOR(i, 1, N - 1){
        if (Min > A[i]){
            Min = A[i];
        }
    }
    return Min;
}
int main() {
    int N;
    cin >> N;

    int P[N];
    P[0] = 0;
    FOR(i, 1, N - 1) {
        P[i] = (int)ceil(log2(i + 1));
    }

    int R[N] = {0};
    R[0] = N;
    FOR(i, 1, N - 1) {
        int remain = pow(2, P[i]) - (i + 1);
        R[i] =  P[i] + (int)ceil(((double)(N - remain)) / (i + 1));
    }
    cout << Min(R, N);
}
