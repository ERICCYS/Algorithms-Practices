#include<bits/stdc++.h>
using namespace std;

class UF {
private:
    int * id;
    int * sz;
public:
    UF (int N) {
        id = new int[N];
        sz = new int[N];
        for (int i = 0; i < N; i++){
            id[i] = i;
            sz[i] = 0;
        }
    }
    int root(int i) {
        while (i != id[i])
            i = id[i];
        return i;
        
        // Alternative: implementation with path compassion 
        // return (id[i] == i) ? i : (id[i] = root(id[i]));
    }
    bool find(int p, int q){
        return root(p) == root(q);
    }
    void uni(int p, int q){
        int i = root(p);
        int j = root(q);
        if (i == j)
            return;

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

int main(){
    int N, Q, a, b;
    char c[2];
    scanf("%d %d",&N, &Q);
    UF * uf = new UF(N);
    while(Q--){
        scanf("%2s %d %d",c,&a,&b);
        if (c[0] == '=') {
            uf->uni(a,b);
        } else if (uf->find(a,b)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
        getchar();
    }
    return 0;
}