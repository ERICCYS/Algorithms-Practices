#include<bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int (i) = (a); (i) = (b); (i)++)


int main() {
    string a;
    string b;

    cin >> a;
    cin >> b;

    if (a.length() >= b.length()) {
        cout << "go";
    }
    else {
        cout << "no";
    }
    return 0;
}
