#include<bits/stdc++.h>
using namespace std;
#define LOG2 0.3010299957
#define LOG3 0.4771212547

int CircumferencePlaces (int N) {
    int place = 1 + (int) (N * (LOG3 - LOG2) + LOG3);
    return place;
}

int main() {
    int N;
    int c = 1;
    while (cin >> N) {
        cout << "Case " << c << ": " << CircumferencePlaces(N) << endl;
        c++;
    }
    return 0;
}
