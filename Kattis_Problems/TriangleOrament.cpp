#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)
#define sqr(x) ((x) * (x))

int main() {
    int N;
    double L = 0;
    cin >> N;
    int a, b, c;
    FOR (i, 0, N - 1) {
        cin >> a >> b >> c;
        double d = sqrt(0.5  * (sqr(b) - 0.5 * sqr(c) + sqr(a)));
        double cos = (0.25 * sqr(c) + sqr(d) - sqr(b)) / (c * d);
        double sin = sqrt(1 - sqr(cos));
        L += c * sin;
    }
    cout << L;
    return 0;
}
