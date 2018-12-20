#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

ull findIndex(ull l, ull r) {
    if (l == r)
        return 1;
    else if (l > r) {
        return findIndex(l-r, r) * 2 + 1;
    } else {
        return findIndex(l, r-l) * 2;
    }
}

int main() {
    int T;
    cin >> T;
    int dummy;
    ull r, l;
    while (T--) {
        cin >> dummy;
        getchar();
        cin >> l;
        getchar();
        cin >> r;
        // cout << r << " " << l << endl;
        cout << dummy << " " << findIndex(l, r) << endl;
    } 
    return 0;
}