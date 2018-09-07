#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)

string LetIn (string S) {
    return S.substr(1);
}

string CutIn (string S) {
    string nS = S.substr(0,1) + S.substr(2);
    return nS;
}

int main() {
    int D_max;
    cin >> D_max;

    int M = 0;
    int W = 0;
    int D = 0;
    string S;
    cin >> S;
    while (S.length() != 0) {
        D = abs(M - W);
        if (D == D_max) {
            if (M > W) {
                if (S.substr(0,1) == "W"){
                    S = LetIn(S);
                    W++;
                }
                else if (S.substr(1,1) == "W"){
                    S = CutIn(S);
                    W++;
                }
                else{
                    break;
                }
            }
            else if (W > M) {
                if (S.substr(0,1) == "M") {
                    S = LetIn(S);
                    M++;
                }

                else if (S.substr(1,1) == "M"){
                    S = CutIn(S);
                    M++;
                }
                else {
                    break;
                }
            }
        }
        else {
            if (S.substr(0,1) == "M") {
                M++;
            }
            else{
                W++;
            }
            S = LetIn(S);
        }

    }
    cout << (M + W);

}
