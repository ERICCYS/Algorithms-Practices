// Eager approach

// Data Structure:
// Integer array id[] of size N
// Interpretation: p and q are connected iff they have the same id

// Two parts: Find and Union
// Find: Check if p and q has the same id
// Union: To merge components contaning p and q change all entries whoes id equals id[p] to id[q]
// Problem with union: many values can change...

// Initially, id[i] = i

#include <bits/stdc++.h>
using namespace std;

bool connected(vector<int> id, int p, int q) {
    return id[p] == id[q];
}

void uni(vector<int> &id, int p, int q) {
    int pid = id[p];
    int qid = id[q];
    // make sure we get the original id of p and q first
    for(int i = 0; i < id.size(); i++) {
        if (id[i] == pid) {
            id[i] = qid; 
        }
    }
}

int main() {
    int N = 10;
    // int id[N];
    vector<int> id;
    for (int i = 0; i < N; i++) {
        id.push_back(i);
    }
    // for (int i = 0; i < N; i++) {
    //     cout << id[i] << "\n";
    // }
    uni(id,4,3);
    uni(id,3,8);
    uni(id,6,5);
    uni(id,9,4);
    uni(id,2,1);
    cout << "Is 8 and 9 connected? " << connected(id,8,9) << endl;
    cout << "Is 5 and 0 connected? " << connected(id,5,0) << endl;
    uni(id,5,0);
    cout<< "Is 5 and 0 connected? " << connected(id,5,0) << endl;
    uni(id,7,2); 
    uni(id,6,1); 
    cout << "Is 0 and 7 connected? " << connected(id,7,0) << endl;
    return 0;
}

// Analysis of this algo
// Initialize array: O(N)
// Union (per time): O(N)
// Find (per time): O(1) 