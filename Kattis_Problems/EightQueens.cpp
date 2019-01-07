#include <bits/stdc++.h>
using namespace std;

int board[8][8];
int main() {
    string s;
    int queens = 0;
    memset(board, 0, sizeof(board));
    for (int i = 0; i < 8; i++) {
        getline(cin, s);
        for(int j = 0; j < 8; j++) { if(s[j] == '*') { board[i][j] = 1; queens++;} }
    }
    bool valid = true;
    if (queens != 8) { valid = false; }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == 0) { continue; }
            for (int a = 0; a < 8; a++) {
                for (int b = 0; b < 8; b++) {
                    if (board[a][b] == 0 || (a == i && b == j)) { continue; }
                    if (a == i || b == j || abs(a-i) == abs(b-j)) { valid = false; }
                }
            }
        }
    }
    if (!valid) {printf("invalid\n");}
    else {printf("valid\n");}
    return 0;
}