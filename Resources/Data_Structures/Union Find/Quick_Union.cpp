// Quick Union(lazy approach)

// Data Structure
// Integer array id[] of size N
// Interpretation: id[i] is parent of i
// Root of i is id[id[....id[i].....]]

// Find: Check if p and q have the same root
// Union: To merge components containing p and q, set the id of p's root to the id of the q's root

#include<bits/stdc++.h>
using namespace std;

int root (vector<int> id,  int i) {
    while(id[i] != i) {
        i = id[i];
    }
    return i;
}

bool connected(vector<int> id, int p, int q) {
    return root(id,p) == root(id,q);
}

void uni(vector<int> &id, int p, int q) {
    int i = root(id,p);
    int j = root(id,q);
    id[i] = j;
}

int main() {
    int N = 10;
    vector<int> id;
    for(int i = 0; i < N; i++) {
        id.push_back(i);
    }
    uni(id,4,3);
    uni(id,3,8);
    uni(id,6,5);
    uni(id,9,4);
    uni(id,2,1);
    cout << "Is 8 and 9 connected? " << connected(id,8,9) << endl;
    cout << "Is 5 and 4 connected? " << connected(id,5,4) << endl;
    uni(id,5,0);
    uni(id,7,2); 
    uni(id,6,1); 
    uni(id,7,3); 
    cout << "Is 8 and 6 connected? " << connected(id,8,6) << endl;
    return 0;
}

// Analysis of this algo (worst case)
// Initialize array (one time): O(N)
// Union (per time): O(N)
// Find (per time): O(N) 

// Problem: Trees can get too tall, difficult to find the root of an element
