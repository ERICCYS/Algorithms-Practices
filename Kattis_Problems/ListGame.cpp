#include<bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)

int main() {
    int N;
    cin >> N;

    int c = 0;
    set <int> F;
    set <int> :: iterator itr;
    int n = (int)sqrt(N) + 1;
    FOR (i, 2, n) {
        if (N % i == 0){
            F.insert(i);
        }
    }
    for (itr = F.begin(); itr != F.end();++itr)
    {
        F.insert(N / (*itr));
    }
    F.insert(N);
    for (itr = F.begin(); itr != F.end();)
    {
        if (N == 1)
            break;
        else if (N % (*itr) == 0) {
            N /= (*itr);
            c++;
            continue;
        }
        else
            itr++;
    }

    cout << c;
}
