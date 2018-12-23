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

UF * uf = new UF(500001);

int main() {
    int N;
    cin >> N;
    int M;
    int node;
    vector<int> nodes;
    vector<int> roots;
    map<int, int> set_size;
    map<int, int> set_count;   
    int a, b; 
    int count = 0;
    bool concoct;
    for (int i = 0; i < N; i++) {
        nodes.clear();
        roots.clear();
        set_size.clear();
        set_count.clear();
        concoct = true;
        cin >> M;
        for (int i = 0; i < M; i++) {
            cin >> node;
            nodes.push_back(node);
            roots.push_back(uf->root(node));
            set_count[uf->root(node)]++;
            set_size[uf->root(node)] = uf->ssize(node);
        }
        
        for(int i = 0; i < roots.size(); i++) {
            if (set_count.find(roots[i]) != set_count.end() && set_size.find(roots[i]) != set_size.end()) {
                a = set_count.find(roots[i])->second;
                b = set_size.find(roots[i])->second;
                if (a != b) {
                    concoct = false;
                    break;
                }
            } else {
                concoct = false;
                break;
            }
        }
        // for (auto itr = set_size.begin(); itr != set_size.end(); itr++){
        //     if (set_count.find(itr->first)->second != itr->second) {
        //         concoct = false;
        //         break;
        //     }
        // }  
        if (concoct) {
            count++;
            for (int i = 0; i < roots.size()-1; i++) {
                uf->uni(roots[i], roots[i+1]);
            }
        }
    }
    cout << count;
}