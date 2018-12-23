#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int main() {
    ull N;
    cin >> N;
    set<ull> A;
    for (ull i = sqrt(N); i > 0; i--) {
        if (abs((N / i) - ((double)N / (double)i)) < 0.000001) {
            A.insert(i);
            A.insert(N / i);
        }
    }
    for (auto itr = A.begin(); itr != A.end(); ++itr) { 
        cout << (*itr - 1) << " "; 
    } 
}