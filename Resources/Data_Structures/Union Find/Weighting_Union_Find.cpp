// Weighted quick-union
// Modify quick union to avoid tall trees
// Keep track of size of each tree(number of objects)
// Balance by likig rooot of smaller tree to root of larger tree

// Data structure
// Same as the quick union, but maintain extra array sz[i] to count the number of objects in the tree rooted at i

// Find: Identical as quick union

// Union: Modify quick union to:
// Link root of smaller tree to root of larger tree
// Update the sz[] array

#include<bits/stdc++.h>
using namespace std;


int root(vector<int> id, int i) {
    while(id[i] != i) {
        i = id[i];
    }
    return i;
}

bool connected(vector<int> id, int p, int q) {
    return root(id,p) == root(id,q);
}

void uni(vector<int> &id, vector<int> &sz, int p, int q) {
    int i = root(id, p);
    int j = root(id, q);
    if (i == j) {
        return ;
    }
    if (sz[i] < sz[j]) {
        id[i] = j;
        sz[j] += sz[i];
    } else {
        id[j] = i;
        sz[i] += sz[j];
    }
}

int main() {
    int N = 10;
    vector<int> id;
    vector<int> sz;
    for (int i = 0; i < N; i++) {
        id.push_back(i);  
        sz.push_back(1);
    }
    uni(id,sz,4,3);
    uni(id,sz,3,8);
    uni(id,sz,6,5);
    uni(id,sz,9,4);
    uni(id,sz,2,1);
    cout << "Is 8 and 9 connected? " << connected(id,8,9) << endl;
    cout << "Is 5 and 4 connected? " << connected(id,5,4) << endl;
    uni(id,sz,5,0);
    uni(id,sz,7,2); 
    uni(id,sz,6,1); 
    uni(id,sz,7,3); 
    cout << "Is 8 and 6 connected? " << connected(id,8,6) << endl;
    return 0;
}