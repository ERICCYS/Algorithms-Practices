#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<string> strs;
    string str;
    set<string> words;
    
    while (cin >> str) {
        strs.push_back(str);
    }
    for (int i = 0; i < strs.size() - 1; i++) {
        for (int j = i + 1; j < strs.size(); j++) {
            words.insert(strs[i] + strs[j]);
            words.insert(strs[j] + strs[i]);
        }
    }
    for (auto itr = words.begin(); itr != words.end(); ++itr) { 
        cout << *itr << endl; 
    } 
    return 0;
}