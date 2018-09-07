#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for(int (i) = (a); (i) >= (b); (i)--)

int MinIndexA (string S, int len) {
    int index = 0;
    FOR(i, 1, (len - 3)) {
        if (S[index] > S[i]){
            index = i;
        }
    }
    return index;
}

int MinIndexB (string S, int len) {
    int index = 0;
    FOR(i, 1, (len - 2)) {
        if (S[index] > S[i]){
            index = i;
        }
    }
    return index;
}

int BreakPoint(string S, int len, int leftmost) {
    int index = S.length() - 1;
    int breakPoint;
    ROF(i, S.length() - 2, leftmost) {
        breakPoint = i;
        if (S[index] > S[i]) {
            break;
        }
    }
    return breakPoint;
}
int main() {
    string S;
    cin >> S;

    if (S.length() <= 3) {
        return 0;
    }

    int minIndex = MinIndexA(S, S.length());
    if (minIndex == S.length() - 3) {
        string partA(S.substr(0,S.length() - 2));
        reverse(partA.begin(), partA.end());
        cout << partA << S[S.length() - 2] << S[S.length() - 1];
        return 0;
    }

    string partA(S.substr(0,minIndex + 1));
    string remain(S.substr(minIndex + 1));
    reverse(partA.begin(), partA.end());

    // plan 1
    int minIndex1 = MinIndexB(remain, remain.length());
    string partB1(remain.substr(0,minIndex1 + 1));
    string partC1(remain.substr(minIndex1 + 1));
    reverse(partB1.begin(), partB1.end());
    reverse(partC1.begin(), partC1.end());
    string A = partA + partB1 + partC1;


    int breakPoint = BreakPoint(S, S.length(), minIndex + 2);
    string partB2(S.substr(minIndex + 1, breakPoint - minIndex));
    string partC2(S.substr(breakPoint + 1));
    reverse(partB2.begin(), partB2.end());
    reverse(partC2.begin(), partC2.end());
    string B = partA + partB2 + partC2;

    if (A <= B)
        cout << A;
    else
        cout << B;
    return 0;
}
