#include <bits/stdc++.h>
using namespace std;

// We use this struct to record the no. of ways satisfies the order.
// Reason is that this can deal with the overflow.
// When we have a big n and big m, probably the no. of ways exceed the int range. 
struct Cost
{
    int val;
    Cost()
    {
        val = 0;
    }
    Cost(int vall)
    {
        val = vall;
    }
 
    Cost operator+(const Cost &c) const
    {
        int h = val + c.val;
        if (h >= 2) return Cost(2);
        return Cost(h);
    }
 
    bool operator!=(const Cost&c) const
    {
        return val != c.val;
    }
};

int main() {
    int n;
    cin >> n;
    vector <int> C;
    int c;
    for(int i = 0; i < n; i++) {
        cin >> c;
        C.push_back(c);
    }
    int m;
    cin >> m;
    vector <int> S;
    int s;
    for(int i = 0; i < m; i++) {
        cin >> s;
        S.push_back(s);
    }

    Cost F[30001];
    F[0] = Cost(1);
    for (int i = 1; i <= 30000; i++)
        F[i] = Cost(0);

    int trace[30001];
    memset(trace, 0, sizeof(trace[0]) * 30001);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 30000 - C[i]; j++) {
            if (F[j].val > 0) {
                F[j + C[i]] = F[j + C[i]] + F[j];
                trace[j + C[i]] = i;
            }
        }
    }

    for(int i = 0; i < m; i++) {
        if (F[S[i]].val == 0) {
            cout << "Impossible\n";
        }
        else if (F[S[i]].val == 2) {
            cout << "Ambiguous\n";
        }
        else {
            int money = S[i];
            vector<int> results;
            while (money > 0) {
                results.push_back(trace[money] + 1);
                money -= C[trace[money]];
            }

            
            for (auto x = results.rbegin(); x != results.rend(); x++) {
                cout << *x << " ";
            }
            results.empty();
            cout << '\n';
        }
    }
}