#include<bits/stdc++.h>
using namespace std;
typedef pair <string, set<int>> pssi;
#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for(int (i) = (a); (i) >= (b); (i)--)

int main() {
    int N, K;
    cin >> N >> K;
    unordered_map <string, set<int>> rec;
    int shop;
    string item;
    FOR(k, 1, K) {
        cin >> shop;
        cin >> item;
        rec[item].insert(shop);
    }
    int M;
    vector <string> items;
    cin >> M;
    FOR(m, 0, M - 1) {
        cin >> item;
        items.push_back(item);
    }

    int maxshop = 0;
    vector<int> rem;
    FOR(i, 0, M - 1) {
        string temp = items[i];
        rem.clear();
        for (auto it = rec[temp].begin(); it != rec[temp].end(); it++)  {
            // cout << "Checking shop #" << *it << " for " << temp << endl;
            if (*it < maxshop) {
                // cout << "Shop #" << *it << "failed MAX check for " << temp << endl;
                rem.push_back(*it);
            }
        }
        for (auto it = rem.begin(); it != rem.end(); it++) {
            // cout << "Erasing shop #" << *it << " for " << temp << endl;
            rec[temp].erase(*it);
        }

        maxshop = max(*rec[temp].begin(), maxshop);
        // cout << "maxshop is " << maxshop << endl;
    }

    int minshop = 1000000;
    ROF(i, M - 1, 0) {
        string temp = items[i];
        rem.clear();
        if (rec[temp].size() == 0)
            continue;
        for(auto it = rec[temp].begin(); it != rec[temp].end(); it++) {
            // cout << "Checking shop #" << *it << " for " << temp << endl;
            if (*it > minshop) {
                // cout << "Shop #" << *it << "failed MIN check for " << temp << endl;
                rem.push_back(*it);
            } 
        }
        for (auto it = rem.begin(); it != rem.end(); it++) {
            rec[temp].erase(*it);
        }

        minshop = min(*rec[temp].rbegin(), minshop);
        // cout << "minshop is " << maxshop << endl;
    }

    bool possible = true;
    bool ambiguous = false;
    FOR(i, 0, M - 1) {
        string temp = items[i];
        if (rec[temp].size() == 0) {
            possible = false;
            break;
        }
        if (rec[temp].size() > 1) {
            ambiguous = true;
        }
    }

    if (possible) {
        if (!ambiguous)
            cout << "unique" << endl;
        else
            cout << "ambiguous" << endl;
    }
    else
        cout << "impossible" << endl;

}