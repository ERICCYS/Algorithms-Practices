#include<bits/stdc++.h>
using namespace std;
#define LSOne(S) ((S) & -(S))
typedef vector<int> vi;

class FenwickTree {
private: vi ft; int n;
public: 
    FenwickTree(int _n) : n(_n) {ft.assign(n+1, 0);}
    int rsq(int j) {
        int sum = 0;
        for(; j; j -= LSOne(j)) sum += ft[j];
        return sum;
    }
    int rsq(int i, int j) {
        return rsq(j) - rsq(i-1);
    } 
    void update(int i) {
        int v = (rsq(i, i) == 1 ? -1 : 1); 
        for(; i <= n; i += LSOne(i)) ft[i] += v;
    }
};

FenwickTree ft(1000001);

int main() {
    int N, K, a, b;
    char c[2];
    scanf("%d %d",&N, &K);
    while(K--) {
        scanf("%2s",c);
        if (c[0] == 'F') {
            scanf("%d %d", &a);
            ft.update(a);
        } else {
            scanf("%d %d", &a, &b);
            printf("%d\n", ft.rsq(a, b));
        }
    }
}