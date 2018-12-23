#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    string str;
    cin >> a >> b >> c;
    cin >> str;
    vector<int> arr;
    arr.push_back(a);
    arr.push_back(b);
    arr.push_back(c);

    sort(arr.begin(), arr.end());
    while(str.length() != 1) {
        if (str[0] == 'A') {
            cout << arr[0] << " ";
        } else if (str[0] == 'B') {
            cout << arr[1] << " ";
        } else {
            cout << arr[2] << " ";
        }
        str = str.substr(1);
    }
    if (str[0] == 'A') {
        cout << arr[0];
    } else if (str[0] == 'B') {
        cout << arr[1];
    } else {
        cout << arr[2];
    }
}