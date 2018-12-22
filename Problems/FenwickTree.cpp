#include<bits/stdc++.h>
using namespace std;
#define LSOne(S) ((S) & -(S))

typedef long long ll;
typedef vector<long long> vll;

class FenwickTree {
private: vll ft; int n;
public: 
    FenwickTree(int _n) : n(_n) {
        ft.assign(n+1, 0);
    }
    ll rsq(int j) {
        ll sum = 0;
        for(; j; j -= LSOne(j)) sum += ft[j];
        return sum;
    }
    void update(int i, ll v) {
        for(; i <= n; i += LSOne(i)) ft[i] += v;
    }
};

FenwickTree ft(5000001);

int main() {
    int N, Q, a, b;
    char c[2];
    scanf("%d %d",&N, &Q);
    while(Q--) {
        scanf("%2s",c);
        if (c[0] == '+') {
            scanf("%d %d", &a, &b);
            ft.update(a+1, b);
        } else {
            scanf("%d", &a);
            printf("%lld\n", ft.rsq(a));
        }
    }
}