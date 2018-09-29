#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iterator>
using namespace std;
typedef pair<int, set<int>> pisi;
#define FOR(i, a, b) for(int (i) = (a); (i) <= b; (i)++)

map<int, set<int>> tea;

int main() {
    int N;
    cin >> N;
    int T[N];
    FOR(i, 0, N - 1) {
        cin >> T[i];
    }
    int M;
    cin >> M;
    int P[M];
    FOR(i, 0, M - 1) {
        cin >> P[i];
    }
    int m, add;
    FOR(i, 0, N - 1) {
        cin >> m;
        FOR(j, 0, m - 1) {
            cin >> add;
            tea[T[i]].insert(P[add - 1]);
            // cout << "Tea price" << T[i] << " insert topping price: " << P[add - 1] << endl; 
        }
    }

    // for (auto it = tea.begin(); it != tea.end(); it++) {
    //     cout << "Tea price: " << it->first << endl;
    //     cout << "Topings " << " ";
    //     for(auto itr = it->second.begin(); itr != it->second.end(); itr++) {
    //         cout << (*itr) << " ";
    //     }
    //     cout << endl;
    // }

    vector <int> Ct;
    FOR(i, 0, N - 1) {
        Ct.push_back(T[i] + *tea[T[i]].begin());
    }

    
    sort(Ct.begin(), Ct.end());
    // cout << Ct[0] << endl;
    int X;
    cin >> X;
    if (((X/Ct[0]) - 1) < 0) {
        cout << 0 << endl;
    }
    else{
        cout << ((X/Ct[0]) - 1) << endl;
    }
    
    return 0;
}