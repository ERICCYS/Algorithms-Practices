#include<bits/stdc++.h>
using namespace std;

int main() {
    int h;
    char d;
    cin >> h;
    getchar();
    cin >> d;
    getchar();
    int score = 0;
    char v;
    char c;
    for (int i = 0; i < 4*h; i++) {
        cin >> v >> c;
        getchar();
        if (c == d) {
            if (v == 'A') score += 11;
            if (v == 'K') score += 4;
            if (v == 'Q') score += 3;
            if (v == 'J') score += 20;
            if (v == 'T') score += 10;
            if (v == '9') score += 14;
        } else {
            if (v == 'A') score += 11;
            if (v == 'K') score += 4;
            if (v == 'Q') score += 3;
            if (v == 'J') score += 2;
            if (v == 'T') score += 10;
        }
    }
    cout << score;
}