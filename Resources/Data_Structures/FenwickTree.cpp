// Fenwick Tree (Binay indexed Tree)

#include<bits/stdc++.h>
using namespace std;
#define LSOne(S) ((S) & -(S))
typedef vector<int> vi;

class FenwickTree {
private: vi ft; int n;
public: FenwickTree(int _n) : n(_n) {ft.assign(n+1, 0);}
    FenwickTree(const vector<int> &f) : n(f.size()-1) {
        // 
        ft.assign(n+1, 0);
        for(int i = 1; i <= n; i++) {
            ft[i] += f[i];
            if(i + LSOne(i) <= n) {
                ft[i + LSOne(i)] += ft[i];
            }
        }
    }
    int rsq(int j) {
        int sum = 0;
        for(; j; j -= LSOne(j)) sum += ft[j];
        return sum;
    }
    int rsq(int i, int j) {
        return rsq(j) - rsq(i-1);
    } 
    void update(int i, int v) {
        for(; i <= n; i += LSOne(i)) ft[i] += v;
    }
};



int main() {
    // frequency vector, index 0 is always 0;
    vector<int> f = {0,0,1,0,1,2,3,2,1,1,0};
    FenwickTree ft(f);
    // frequency sum of score in range [1,6]
    cout << ft.rsq(1,6) << endl;
    // frequency sum of score in range [1,3]
    cout << ft.rsq(1,3) << endl;
    // Another score is 5 (one more score is 5, update the freqeuncy)
    ft.update(5,1);
    // frequency sum of score in range [1,10]
    cout << ft.rsq(1,10) << endl;
}