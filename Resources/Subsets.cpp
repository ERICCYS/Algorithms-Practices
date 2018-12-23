#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> arr;
    for (int i = 1; i <= N; i++) {
        arr.push_back(i);
    } 
    for (int i = 0; i < (1<<N); i++) {
        cout << "{";
        for (int j = 0; j < N; j++) {
            if ((i & (1<<j)) != 0) {
                cout << arr[j] << " ";
            }
        }
        cout << "}\n";
    }

}