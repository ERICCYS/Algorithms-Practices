#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    if (s.length() % 2 == 1){
        cout << 0;
        return 0;
    } else {
        int b = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'B') {
                b++;
            }
        }
        if (2 * b == s.length()) {
            cout << 1;
        } else {
            cout << 0;
        }
    }
}