#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int N, a;
        cin >> N;
        vector<int> arr;
        for(int i = 0; i < N; i++) {
            cin >> a;
            arr.push_back(a);
        }
        for(int i = 1; i < N; i++) {
            if (arr[i] - arr[i-1] != 1) {
                cout << (i + 1) << endl;
                break;
            }
        }
    }
}