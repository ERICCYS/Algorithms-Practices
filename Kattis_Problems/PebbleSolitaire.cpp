#include<bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for(int (i) = (a); (i) >= (b); (i)--)
#define SIZE 12

struct Move {
    int from;
    int to;
};

int Cases(string S) {
    int c = 0;
    FOR(i, 0, SIZE - 3) {
        if (S.substr(i,3) == "-oo" || S.substr(i, 3) == "oo-") {
            c++;
        }
    }
    return c;
}

void GetMoves(string S, Move Ms[]) {
    int j = 0;
    FOR(i, 0, SIZE - 3) {
        if (S.substr(i,3) == "-oo") {
            Ms[j].from = i + 2;
            Ms[j].to = i;
            j++;
        }
        else if (S.substr(i, 3) == "oo-") {
            Ms[j].from = i;
            Ms[j].to = i + 2;
            j++;
        }
    }
}

string TakeMove(string S, Move M) {
    string nS;
    if (M.from < M.to) {
        nS = S.substr(0, M.from) + "--o" + S.substr(M.to + 1);
    }
    else {
        nS = S.substr(0, M.to) + "o--" + S.substr(M.from + 1);
    }
    return nS;
}

int PeddleCount (string S) {
    int c = 0;
    FOR(i, 0, SIZE - 1) {
        if (S.substr(i,1) == "o") {
            c++;
        }
    }
    return c;

}

int MakeMove (string S, Move M, int Memo[][SIZE], bool R[]) {
    string nS = TakeMove(S, M);
    if (Cases(nS) == 0){
        R[PeddleCount(nS) - 1] = 1;
        return 1;
    }

    else {
        Move Ms[Cases(nS)];
        GetMoves(nS,Ms);
        int ans = -1;
        Move OptM;
        int pre_ans = -1;
        FOR(i, 0, Cases(nS) - 1){
            pre_ans = ans;
            ans = max(ans, MakeMove(nS, Ms[i], Memo, R));
            if (ans >= pre_ans) {
                OptM.from = Ms[i].from;
                OptM.to = Ms[i].to;
            }
        }
        Memo[OptM.from][OptM.to] = ans;
        return 1 + ans;
    }
}

int main() {
    int N;
    cin >> N;
    FOR(k, 0, N - 1) {
        int Memo[SIZE][SIZE];
        FOR(i, 0, SIZE - 1){
            FOR(j, 0, SIZE - 1){
                Memo[i][j] = -1;
            }
        }
        string S;
        cin >> S;

        int c = Cases(S);
        if (c == 0) {
            cout << PeddleCount(S) << endl;
            continue;
        }
        else {
            Move Ms[c];
            GetMoves(S, Ms);
            bool R[SIZE] = {0};
            FOR(i, 0, c - 1) {
                FOR(a, 0, SIZE - 1){
                    FOR(b, 0, SIZE - 1){
                        Memo[a][b] = -1;
                    }
                }
                MakeMove(S,Ms[i],Memo,R);
            }
            FOR(i,0, SIZE - 1) {
                if (R[i] == 1){
                    cout << i + 1 << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
