#include<bits/stdc++.h>
using namespace std;

int main() {
    int l, r;
    cin >> l >> r;
    if (l == r && (r || l)) {
        cout << "Even " << 2*l;
    } else if (l != r && (r || l)) {
        cout << "Odd " << 2*max(l,r);
    } else {
        cout << "Not a moose";
    }
}