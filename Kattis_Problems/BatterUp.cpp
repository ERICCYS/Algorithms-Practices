#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> arr;
    int a;
    for (int i = 0; i < N; i++) {
        cin >> a;
        if (a != -1) {
            arr.push_back(a);
        } 
    }
    double sum;
    for (int x : arr) {
        sum += (double)x;
    }
    cout << sum/(double)(arr.size());
}