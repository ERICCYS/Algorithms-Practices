#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

bool cans[1000000002];
int caps[100001];
int need[100001];
int min_cap = 1000000002;

int LS(int a) {
    if (cans[a]) { return 0; }
    // Avoid extremly large number.
    if (a < min_cap) { return (min_cap - a); }
    for (int i = a + 1; i < 1000000001; i++) {
        if (cans[i]) { return i-a; }
    }
}

int main() {
    int n, m, can;
    ull total_waste = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) { scanf("%d", &caps[i]); min_cap = min(caps[i], min_cap); cans[caps[i]] = 1; }
    for (int i = 0; i < m; i++) { scanf("%d", &need[i]); }
    for (int i = 0; i < m; i++) {
        total_waste += LS(need[i]);
    }
    cout << total_waste << endl;
    return 0;
}