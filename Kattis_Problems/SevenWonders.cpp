#include<bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    int t = 0, c = 0, g = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'T') {
            t++;
        } else if (str[i] == 'C') {
            c++;
        } else if (str[i] == 'G') {
            g++;
        }
    }
    int result = 0;
    result += 7 * min(t, min(c, g));
    result += t*t;
    result += c*c;
    result += g*g;
    cout << result;
}