#include<bits/stdc++.h>
using namespace std;

int dist(string a, string b) {
    int cnt = 0;
    int A[26];
    int B[26];
    for (int j = 0; j < 26; j++) { A[j] = 0; B[j] = 0; }
    for (auto c : a) { A[c-'A']++; } 
    for (auto c : b) { B[c-'A']++; }
    for (int j = 0; j < 26; j++) { cnt += (A[j] & B[j]); }
    return cnt;
}

int main() {
    int N;
    scanf("%d", &N);
    vector<string> strs(N);
    vector<int> ids(N);
    string str;
    for (int i = 0; i < N; i++) {  cin >> strs[i]; ids[i] = i; }
    int cnt, min_cnt = 100000000;

    vector<vector<int>> distance;
    distance.resize(N, vector<int>(N));
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            distance[i][j] = dist(strs[i], strs[j]);
            distance[j][i] = distance[i][j];
        }
    }
    
    do {
        cnt = 0;
        for (int i = 0; i < N-1; i++) {
            cnt += distance[ids[i]][ids[i+1]];
        }
        min_cnt = min_cnt > cnt ? cnt : min_cnt;
    } while(next_permutation(ids.begin(), ids.end()));
    
    printf("%d\n", min_cnt);
    return 0;
}