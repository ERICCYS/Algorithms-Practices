#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(int(i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for(int(i) = (a); (i) >= (b); (i)--)

bool wayToSort(int i, int j) {return i > j;}

int main() {
    int n;
    cin >> n;

    int A[n];
    FOR(i, 0, n - 1) {
        cin >> A[i];
    }

    sort(A, A + n, wayToSort);
    // FOR(i, 0, n - 1) {
    //     cout << A[i] << " ";
    // }
    // cout << endl;
    int total = 0;
    
    FOR(i, 0, n - 1) {
        if (i % 3 == 2) 
            continue;
        total += A[i];
    }

    cout << total;
}