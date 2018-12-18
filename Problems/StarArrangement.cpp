#include <bits/stdc++.h>
using namespace std;

bool solve(int S, int a, int b) {
    return (S % (a+b) == 0 || S % (a + b) == a);
}

int main() {
    int S;
    cin >> S;
    cout << S << ":" << endl;
    for(int i = 2; i <= (S+1)/2; i++) {
        if(solve(S, i, i-1)) {
            cout << i << "," << i-1 << endl;
        }
        if(solve(S, i, i)) {
            cout << i << "," << i << endl;
        }
    }
}