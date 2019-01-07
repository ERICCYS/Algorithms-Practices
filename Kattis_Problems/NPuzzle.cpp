#include<bits/stdc++.h>
using namespace std;

int main() {
    map<char, pair<int, int>> pos;
    pos['A'] = make_pair(0,0); pos['B'] = make_pair(0,1); pos['C'] = make_pair(0,2); pos['D'] = make_pair(0,3);
    pos['E'] = make_pair(1,0); pos['F'] = make_pair(1,1); pos['G'] = make_pair(1,2); pos['H'] = make_pair(1,3);
    pos['I'] = make_pair(2,0); pos['J'] = make_pair(2,1); pos['K'] = make_pair(2,2); pos['L'] = make_pair(2,3);
    pos['M'] = make_pair(3,0); pos['N'] = make_pair(3,1); pos['O'] = make_pair(3,2); pos['.'] = make_pair(3,3);
    string s;
    int dist = 0;
    for (int i = 0; i < 4; i++) {
        getline(cin, s);
        for (int j = 0; j < 4; j++) {
            if (s[j] != '.') {
                dist += (abs(i-pos[s[j]].first) + abs(j-pos[s[j]].second));
            }
        }
    }
    printf("%d", dist);
}