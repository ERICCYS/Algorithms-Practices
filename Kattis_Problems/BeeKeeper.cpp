#include<bits/stdc++.h>
using namespace std;

int vowel_pairs (string s) {
    int ctn = 0;
    for (int i = 0; i < s.length()-1; i++) {
        if ((s[i+1] == s[i]) && (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y')) {
                ctn++;
        }
    }
    return ctn;
}

int main() {
    int T;
    while(1){
        scanf("%d", &T);
        if (T == 0) {
            break;
        }
        vector<string> strs;
        string str;
        for (int i = 0; i < T; i++) {
            cin >> str;
            strs.push_back(str);
        }
        int vc = vowel_pairs(strs[0]);
        int max_id = 0;
        for (int i = 1; i < T; i++) {
            if (vowel_pairs(strs[i]) > vc) { max_id = i; vc = vowel_pairs(strs[i]); }
        }
        cout << strs[max_id] << endl;
    }
    return 0;
}