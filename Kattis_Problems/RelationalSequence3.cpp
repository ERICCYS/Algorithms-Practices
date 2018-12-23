#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

string toStr(ull x) {
    string str = "r";
    while (x != 1) {
        if (x % 2 == 1) {
            str += "r";
        } else {
            str += "l";
        }
        x /= 2;
    }
    return str;
}

int main() {
    int T;
    cin >> T;
    int dummy;
    ull x;
    ull l, r;
    while (T--) {
        cin >> dummy;
        cin >> x;
        string str = toStr(x);
        l = 1; r = 1;
        while (str != "r") {
            if (str[str.length() - 1] == 'l') {
                r += l;
            } else {
                l += r;
            }
            str = str.substr(0, str.length() - 1);
        }
        cout << dummy << " " <<  l << "/" << r << endl;
    }   
}