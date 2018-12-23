#include<bits/stdc++.h>
using namespace std;

int arr_min(vector<int> arr) {
    int a_min = 1000001;
    for (int a : arr) {
        if (a < a_min) {
            a_min = a;
        }
    }
    return a_min;
}

int arr_max(vector<int> arr) {
    int a_max = -1000001;
    for (int a : arr) {
        if (a > a_max) {
            a_max = a;
        }
    }
    return a_max;
}

int arr_ran(vector<int> arr) {
    return arr_max(arr) - arr_min(arr);
}

int main() {
    int T = 1;
    int n;
    while (scanf("%d", &n) != EOF) {
        vector<int> arr;
        int a;
        for (int i = 0; i < n; i++) {
            cin >> a;
            arr.push_back(a);
        }
        cout << "Case " << T++ << ": " << arr_min(arr) << " " << arr_max(arr) << " " << arr_ran(arr) << endl;
    }
    return 0;
}