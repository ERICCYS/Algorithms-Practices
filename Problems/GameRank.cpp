#include<bits/stdc++.h>
using namespace std;

int stars(int rank) {
    if (rank > 20) return 2;
    if (rank > 15) return 3;
    if (rank > 10) return 4;
    return 5;
}

int main() {
    int rank = 25;
    int star = 0;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (rank == 0) break;
        if (s[i] == 'W') {
            star++;
            if (i >= 2 && rank >= 6 && (s[i-1] == 'W' && s[i-2] == 'W')) star++;
            if (star > stars(rank)) {
                star = star - stars(rank);
                rank--;
            }
        } else {
            if (rank > 20 || (rank == 20 && star == 0)) {
                continue;
            } else {
                star--;
                if (star < 0) {
                    rank++;
                    star = stars(rank) + star;
                }
            }
        }
    }
    if (rank == 0) {
        cout << "Legend";
    } else {
        cout << rank;
    }
}