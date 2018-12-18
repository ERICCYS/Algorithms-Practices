#include<bits/stdc++.h>
using namespace std;

int main() {
    int l;
    cin >> l;
    string str;
    cin >> str;
    string a = "ABC";
    string b = "BABC";
    string c = "CCAABB";

    vector<char> va;
    vector<char> vb;
    vector<char> vc;

    for(int i = 0; i < l; i++) {
        va.push_back(a[i%3]);
        vb.push_back(b[i%4]);
        vc.push_back(c[i%6]);
    }

    int a_hit = 0;
    int b_hit = 0;
    int c_hit = 0;

    for (int i = 0; i < l; i++) {
        if (va[i] == str[i]) {
            a_hit++;
        }
        if (vb[i] == str[i]) {
            b_hit++;
        }
        if (vc[i] == str[i]) {
            c_hit++;
        }
    }
    // cout << a_hit << " " << b_hit << " " << c_hit << endl;
    int max_hit = max(a_hit, max(b_hit, c_hit));
    cout << max_hit << endl;
    if (a_hit == max_hit) {
        cout << "Adrian\n";
    }
    if (b_hit == max_hit) {
        cout << "Bruno\n";
    }
    if (c_hit == max_hit) {
        cout << "Goran\n";
    }
    return 0;
}