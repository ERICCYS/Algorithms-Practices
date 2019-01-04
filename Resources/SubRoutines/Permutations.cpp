#include<bits/stdc++.h>
using namespace std;
void permutation(string str,int i, int n) {
    if (i == n - 1) {
        cout << str << endl;
        return ;
    }
    for (int j = i; j < n; j++) {
        swap(str[i], str[j]);
        permutation(str, i + 1, n);
        swap(str[j], str[i]);
    }
}
int main() {
    string str;
    cin >> str;
    permutation(str, 0, str.length());
    return 0;
}