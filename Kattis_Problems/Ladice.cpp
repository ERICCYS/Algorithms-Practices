#include<bits/stdc++.h>
using namespace std;

class UF {
private:
    int * id;
    int * sz;
    int * ss;
public:
    UF (int N) {
        id = new int[N];
        sz = new int[N];
        ss = new int[N];
        for (int i = 0; i < N; i++){
            id[i] = i;
            sz[i] = 0;
            ss[i] = 1;
        }
    }
    int root(int i) {
        return (id[i] == i) ? i : (id[i] = root(id[i]));
    }
    bool find(int p, int q){
        return root(p) == root(q);
    }
    int ssize(int i) {
        return ss[root(i)];
    }
    void use(int i) {
        ss[root(i)]--;
    }
    void uni(int p, int q){
        int i = root(p);
        int j = root(q);
        int si = ss[i];
        int sj = ss[j];
        if (i == j)
            return;

        ss[i] = si + sj;
        ss[j] = si + sj;

        if (sz[i] < sz[j]) {
            id[i] = j;
            
        } else if (sz[i] > sz[j]) {
            id[j] = i;
        } else {
            id[j] = i;
            sz[i]++;
        }
    }
};


int main() {
    int N, Q, A, B;
    scanf("%d %d",&N, &Q);
    UF * uf = new UF(Q);
    while(N--){
        scanf("%d %d",&A, &B);
        uf->uni(A-1, B-1);
        if (uf->ssize(A-1) > 0) {
            printf("LADICA\n");
            uf->use(A-1);
        } else {
            printf("SMECE\n");
        }
    }
    return 0;
}