#include<bits/stdc++.h>
using namespace std;

int sts_min(vector<int> sts_q, vector<int> stickers) {
    int s_min = 101;
    for (int s : stickers) {
        if (sts_q[s-1] < s_min) {
            s_min = sts_q[s-1] ;
        }
    }
    return s_min;
}

int main() {
    int T;
    cin >> T;
    int n, m;
    while (T--) {
        cin >> n >> m;
        vector<int> prizes;
        vector<int> sts_q;
        vector<int> stickers[n];
        for (int i = 0; i < n; i++) {
            int q;
            cin >> q;
            int s;
            for (int j = 0; j < q; j++) {
                cin >> s;
                stickers[i].push_back(s);
            }
            int p;
            cin >> p;
            prizes.push_back(p);
        }


        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < stickers[i].size(); j++) {
        //         cout << stickers[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        int sticker_q;
        for (int i = 0; i < m; i++) {
            cin >> sticker_q;
            sts_q.push_back(sticker_q);
        }

        // for (int i = 0; i < m; i++) {
        //     cout << sts_q[i] << " ";
        // }
        // cout << endl;

        int cash = 0;
        for (int i = 0;i < n; i++) {
            // cout << sts_min(sts_q, stickers[i]) << endl;
            cash += prizes[i] * sts_min(sts_q, stickers[i]);    
        }
        cout << cash << endl;
    }
}