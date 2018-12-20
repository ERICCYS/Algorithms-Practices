#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> V; 
    vector<int> Vmax;
    vector<int> Vmin;
    int n;
    cin >> n;
    int v;
    for (int i = 0; i < n; i++) {
        cin >> v;
        V.push_back(v);
        Vmax.push_back(0);
        Vmin.push_back(0);
    }
    Vmax[0] = V[0];
    for (int i = 1; i < n; i++) {
        Vmax[i] = max(V[i], Vmax[i-1]);
    }
    Vmin[n-1] = V[n-1];
    for (int i = n-2; i >= 0; i--) {
        Vmin[i] = min(V[i], Vmin[i+1]);
    }
    int r = 0;
    for (int i = 0; i < n; i++) {
        if (V[i] >= Vmax[i] && V[i] <= Vmin[i]) r++;
    }
    cout << r;
    return 0;
}