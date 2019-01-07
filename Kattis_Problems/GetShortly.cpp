#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef pair<long double, int> pli;
typedef vector<pli> vpli;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)

int main() {
    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) 
            return 0;

        vector <vpli> cross(n);
        int g1, g2;
        ld f;
        FOR(i, 0, m - 1) {
            cin >> g1 >> g2 >> f;
            cross[g1].push_back({f, g2});
            cross[g2].push_back({f, g1});
        }

        priority_queue <pli> pq;
        pq.push({1, 0});

        vector<bool> vis(n, false);
        vector<ld> S(n);

        while (!pq.empty()) {
            ld size = pq.top().first;
            int g = pq.top().second;
            pq.pop();

            if (vis[g])
                continue;
            
            vis[g] = true;
            S[g] = size;
            for (auto i : cross[g]) {
                pq.push({size * i.first, i.second});
                // Since it is a pq, it will alway show the optimal size;
            }
        }

        cout << setprecision(4) << fixed;
        cout << S[n - 1] << endl;
        
    }
}