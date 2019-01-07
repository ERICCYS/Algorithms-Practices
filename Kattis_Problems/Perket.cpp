#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int main() {
    ull dif = numeric_limits<ull>::max();
    int N, s, b;
    scanf("%d", &N);
    vector<int> sour;
    vector<int> bitt;
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &s, &b);
        sour.push_back(s);
        bitt.push_back(b);
    } 
    ull S = 0, B = 0;
    for (int i = 0; i < (1<<N); i++) {
        S = 0, B = 0;
        for (int j = 0; j < N; j++) {
            if ((i & (1<<j)) != 0) {
                if (S == 0) {S = sour[j];}
                else {S *= sour[j];}
                B += bitt[j];
            }
        }
        if (S == 0 && B == 0)  { continue; }
        if (S > B) { dif = (dif < S-B) ? dif : S-B;}
        else { dif = (dif < B-S) ? dif : B-S;}
    }  
    cout << dif <<  endl;
}
