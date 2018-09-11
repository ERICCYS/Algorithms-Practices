#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

#define FOR(i, a, b) for(int(i) = (a); (i) <= (b); (i)++)
#define SIZE 23

map<string, int> vis;
int ans;

void RemovePeddle(const string& S){
    if (vis[S])
        return;

    vis[S] = 1;
    // If we alr checked this string's case, we just set it to one so that we don't need to check it again.
    int cnt = 0;

    FOR(i,0, SIZE - 1){
        cnt += (S[i] == 'o');
    }

    ans = min(ans, cnt);
    FOR(i, 0, SIZE - 3) {
        if (S[i + 1] != 'o')
            continue;

        if (S[i] == 'o' && S[i + 2] == '-') {
            string temp = S;
            temp[i] = '-';
            temp[i + 1] = '-';
            temp[i + 2] = 'o';
            RemovePeddle(temp);
            continue;
        }

        if (S[i] == '-' && S[i + 2] == 'o') {
            string temp = S;
            temp[i] = 'o';
            temp[i + 1] = '-';
            temp[i + 2] = '-';
            RemovePeddle(temp);
            continue;
        }
    }
}

int main() {
    int C;
    cin >> C;

    FOR(i, 0, C - 1) {
        vis.clear();
        string S;
        cin >> S;
        int cnt = 0;
        FOR(i, 0, SIZE - 1) {
            cnt += (S[i] == 'o');
        }
        ans = cnt;
        RemovePeddle(S);
        cout << ans << endl;
    }

}
