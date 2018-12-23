#include<bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    if (str.length() == 1) {
        cout << "no hiss\n";
    } else {
        for (int i = 0; i < str.length()-1; i++) {
            if (str[i] == 's' && str[i+1] == 's') {
                cout << "hiss\n";
                return 0;
            }
        }
        cout << "no hiss\n";
    }
    return 0;
}