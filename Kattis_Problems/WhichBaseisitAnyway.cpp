#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(int(i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for(int(i) = (a); (i) >= (b); (i)--)

bool checkOctal(string s) {
    FOR(i, 0, s.size() - 1) {
        if (s[i] >= '8')
            return false;
    }
    return true;
}

ll toOctal(string s) {
    ll r = 0;
    ROF(i, s.size() - 1, 0) {
        r += pow(8, (s.size() - 1 - i)) * int(s[i] - 48);
    }

    return r;
}

ll toDec(string s) {
    ll r = 0;
    ROF(i, s.size() - 1, 0) {
        r += pow(10, (s.size() - 1 - i)) * int(s[i] - 48);
    }

    return r;
}

ll toHex(string s) {
    ll r = 0;
    ROF(i, s.size() - 1, 0) {
        r += pow(16, (s.size() - 1 - i)) * int(s[i] - 48);
    }
    return r;
}

int main() {
    int n;
    cin >> n;

    FOR(i, 1, n) {
        int dum;
        cin >> dum;
        string num;
        cin >> num;
        cout << dum << " ";
        if (checkOctal(num))
            cout << toOctal(num) << " ";
        else
            cout << "0" << " ";
        cout << toDec(num) << " ";
        cout << toHex(num) << endl;
    }
    return 0;
}