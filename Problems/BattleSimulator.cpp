#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<char> defend;
    string ss;
    for (int i = 0; i < s.length(); i++) {
        if (i <= s.length() - 3) {
            ss = s.substr(i, 3);
            sort(ss.begin(), ss.end()); 
            if (ss == "BLR") {
                defend.push_back('C');
                // we have absort 2 more attacks.
                i += 2;
                continue;
            }
        } 
        if (s[i] == 'R') {
            defend.push_back('S');
        }
        if (s[i] == 'B') {
            defend.push_back('K');
        }
        if (s[i] == 'L') {
            defend.push_back('H');
        }
    }
    for(int i = 0; i < defend.size(); i++) {
        cout << defend[i];
    }
}