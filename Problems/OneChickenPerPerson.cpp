#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    if (N > M) {
        if (N - M == 1) {
            cout << "Dr. Chaz needs 1 more piece of chicken!";
        } else {
            cout << "Dr. Chaz needs " << N - M << " more pieces of chicken!";
        }
        
    } else {
        if (M - N == 1) {
            cout << "Dr. Chaz will have 1 piece of chicken left over!";
        } else {
            cout << "Dr. Chaz will have " << M - N << " pieces of chicken left over!";
        }
    }
    return 0;
}